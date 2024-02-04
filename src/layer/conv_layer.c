#include "../../include/layer/conv_layer.h"

#define THREAD_NUM 8

void calculate_conv_sz(
    const uint32_t input_row,
    const uint32_t input_col,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    uint32_t* output_row,
    uint32_t* output_col
){
    *output_row = (uint32_t)((input_row - kernel_row + 2 * padding_num) / stride_row) + 1;
    *output_col = (uint32_t)((input_col - kernel_col + 2 * padding_num) / stride_col) + 1;
    return;
}

float patch_convolution(
    const float* input_data,
    const float* kernel_data,
    const uint32_t input_row,
    const uint32_t input_col,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t channel,
    const uint32_t bias
){
    float sum = bias;
    float* input_ptr;
    float* kernel_ptr;

    uint32_t i, j;
    uint32_t k = 0;

    for(i = 0; i < kernel_row; ++i){
        for(j = 0; j < kernel_col; ++j){
            for(k = 0; k < channel; ++k){
                input_ptr = input_data + i * input_col * channel + j * channel + k;
                kernel_ptr = kernel_data + i * kernel_col * channel + j * channel + k;
                sum += ((*input_ptr) * (*kernel_ptr));
            }
        }
    }
    return sum;
}

struct FeatureMap* Conv3D(
    const struct FeatureMap* input,
    const struct Kernel* kernel,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    const uint8_t relu_opt
){
    uint32_t input_row = input -> row;
    uint32_t input_col = input -> col;
    uint32_t input_channel = input -> channel;
    uint32_t input_sz = input_row * input_col;
    float* input_data = input -> data;
    
    uint32_t kernel_row = kernel -> row;
    uint32_t kernel_col = kernel -> col;
    uint32_t kernel_channel = kernel -> channel;
    uint32_t kernel_num = kernel -> num;
    uint32_t kernel_sz = kernel_row * kernel_col;
    float* kernel_weight = kernel -> weight;
    float* kernel_bias = kernel -> bias;

    uint32_t output_row, output_col;
    uint32_t output_channel = kernel -> num;
    calculate_conv_sz(input_row, input_col, kernel_row, kernel_col, 
                    stride_row, stride_col, padding_num, &output_row, &output_col);
    uint32_t output_sz = output_row * output_col;
    float* output_data = (float*)malloc(output_row * output_col * output_channel * sizeof(float));

    //struct FeatureMap* padded_input = Zeropadding(input, padding_num);
	//uint32_t input_sz = (padded_input -> row) * (padded_input -> col);
    
    uint32_t i, j, k, m, n, p, q;
    for(i = 0; i < kernel_num; ++i){
        float* current_kernel = kernel_weight + i * kernel_sz * kernel_channel;
        float* output_ch = output_data + i * output_sz;
        for(j = 0; j < output_row; ++j){
            for(k = 0; k < output_col; ++k){
                float sum = kernel_bias[i];
                for(n = 0; n < kernel_channel; ++n){
                    //float* input_ptr = padded_input -> data + n * input_sz + 
                    //                       j * (padded_input -> col) * stride_row + k * stride_col;
                    float* input_ptr = input -> data + n * input_sz + j * input_col * stride_row + k * stride_col;
                    float* kernel_ptr_ch = current_kernel + n * kernel_sz;
                    for(p = 0; p < kernel_row; ++p){
                        for(q = 0; q < kernel_col; ++q){
                            //sum += ((*(input_ptr + p * (padded_input -> col) + q)) * (*(kernel_ptr_ch + p * kernel_col + q)));
                            sum += ((*(input_ptr + p * input_col + q)) * (*(kernel_ptr_ch + p * kernel_col + q)));
                        }
                    }
                }
                if(relu_opt && (sum < 0)){
                    sum = 0;
                }
                *(output_ch + j * output_col + k) = sum;
            }
        }
    }

    struct FeatureMap* output = (struct FeatureMap*)malloc(sizeof(struct FeatureMap));
    output -> row = output_row;
    output -> col = output_col;
    output -> channel = output_channel;
    output -> data = output_data;

    //freeFeatureMap(padded_input);
    return output;
}

struct FeatureMap* Conv3D2(
    const struct FeatureMap* input,
    const struct Kernel* kernel,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    const uint8_t relu_opt
){

    if(kernel -> channel != input -> channel){
        printf("Input channel != kernel channel\n");
        
    }

    uint32_t output_row, output_col;
    uint32_t output_channel = kernel -> num;
    uint32_t input_row = input -> row;
    uint32_t input_col = input -> col;
    uint32_t input_channel = input -> channel;
    
    uint32_t kernel_row = kernel -> row;
    uint32_t kernel_col = kernel -> col;
    uint32_t kernel_channel = kernel -> channel;
    uint32_t kernel_num = kernel -> num;

    float* input_data = input -> data;
    float* kernel_weight = kernel -> weight;
    float* kernel_bias = kernel -> bias;

    calculate_conv_sz(input_row, input_col, kernel_row, kernel_col, 
                    stride_row, stride_col, padding_num, &output_row, &output_col);
    
    struct FeatureMap* padded_input = Zeropadding(input, padding_num);

    uint32_t output_sz = output_row * output_col;
	uint32_t input_sz = (padded_input -> row) * (padded_input -> col);
	uint32_t kernel_sz = kernel_row * kernel_col;

    float* output_data = (float*)malloc(output_row * output_col * output_channel * sizeof(float));
    
    uint32_t i, j, k, m, n;

    float temp = 0;
    for(i = 0; i < kernel_num; ++i){
        float* current_kernel_weight = kernel_weight + i * kernel_sz * kernel_channel;
        float current_kernel_bias = *(kernel_bias + i);
        for(j = 0; j < output_row; ++j){
            for(k = 0; k < output_col; ++k){
                temp = patch_convolution(
                    padded_input -> data + j * stride_row * (padded_input -> col) * input_channel + k * stride_col * input_channel,
                    current_kernel_weight,
                    input_row,
                    input_col,
                    kernel_row,
                    kernel_col,
                    input_channel,
                    current_kernel_bias
                );
                if(relu_opt && (temp < 0)){
                    *(output_data + j * output_col * output_channel + k * output_channel + i) = 0;
                }else{
                    *(output_data + j * output_col * output_channel + k * output_channel + i) = temp;
                }
            }
        }
    }

    struct FeatureMap* output = (struct FeatureMap*)malloc(sizeof(struct FeatureMap));
    output -> row = output_row;
    output -> col = output_col;
    output -> channel = output_channel;
    output -> data = output_data;

    freeFeatureMap(padded_input);
    return output;
}