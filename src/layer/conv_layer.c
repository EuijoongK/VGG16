#include "../../include/layer/conv_layer.h"

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

double patch_convolution(
    const double* input_data,
    const double* kernel_params,
    const uint32_t input_row,
    const uint32_t input_col,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const double bias
){
    double sum = bias;
    for(uint32_t i = 0; i < kernel_row; ++i){
        const double* input_ptr = input_data + i * input_col;
        const double* kernel_ptr = kernel_params + i * kernel_col;

        uint32_t j = 0;
        for(; j < kernel_col - 3; j += 4){
            sum += (input_ptr[j] * kernel_ptr[j] +
                input_ptr[j + 1] * kernel_ptr[j + 1] +
                input_ptr[j + 2] * kernel_ptr[j + 2] +
                input_ptr[j + 3] * kernel_ptr[j + 3]);
        }
        for(; j < kernel_col; ++j){
            sum += input_ptr[j] * kernel_ptr[j];
        }
    }
    return sum;
}

//in progress
struct FeatureMap* Conv3D(
    const struct FeatureMap* input,
    const struct Kernel* kernel,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    const uint8_t relu_opt
){
    uint32_t output_row, output_col;
    uint32_t output_channel = kernel -> num;
    uint32_t input_row = input -> row;
    uint32_t input_col = input -> col;
    uint32_t input_channel = input -> channel;
    
    uint32_t kernel_row = kernel -> row;
    uint32_t kernel_col = kernel -> col;
    uint32_t kernel_channel = kernel -> channel;
    uint32_t kernel_num = kernel -> num;

    double* input_data = input -> data;
    double* kernel_weight = kernel -> weight;
    double* kernel_bias = kernel -> bias;

    calculate_conv_sz(input_row, input_col, kernel_row, kernel_col, 
                    stride_row, stride_col, padding_num, &output_row, &output_col);
    
    struct FeatureMap* padded_input = Zeropadding(input, padding_num);

    uint32_t output_sz = output_row * output_col;
	uint32_t input_sz = (input_row + 2 * padding_num) * (input_col + 2 * padding_num);
	uint32_t kernel_sz = kernel_row * kernel_col;

    double* output_data = (double*)malloc(output_row * output_col * output_channel * sizeof(double));
    
    uint32_t i, j, k, m, n;
    for(i = 0; i < kernel_num; ++i){
        double* output_data_ptr = output_data + i * output_sz;
        for(j = 0; j < output_row; ++j){
            for(k = 0; k < output_col; ++k){
                double sum = kernel_bias[i];
                for(n = 0; n < kernel_channel; ++n){
                    const double* input_ptr = padded_input -> data + n * input_sz + 
                                            j * (input_col + 2 * padding_num) * stride_row + k * stride_col;
                    const double* kernel_ptr = kernel_weight + (i * kernel_channel + n) * kernel_sz;

                    uint32_t p = 0, q = 0;
                    for(; p < kernel_row; ++p){
                        for(q = 0; q < kernel_col - 3; q += 4){
                            sum += input_ptr[p * (input_col + 2 * padding_num) + q] * kernel_ptr[p * kernel_col + q];
                            sum += input_ptr[p * (input_col + 2 * padding_num) + q + 1] * kernel_ptr[p * kernel_col + q + 1];
                            sum += input_ptr[p * (input_col + 2 * padding_num) + q + 2] * kernel_ptr[p * kernel_col + q + 2];
                            sum += input_ptr[p * (input_col + 2 * padding_num) + q + 3] * kernel_ptr[p * kernel_col + q + 3];
                        }
                        for(; q < kernel_col; ++q){
                            sum += input_ptr[p * (input_col + 2 * padding_num) + q] * kernel_ptr[p * kernel_col + q];
                        }
                    }
                }
                if(relu_opt && (sum < 0)){
                    sum = 0;
                }
                output_data_ptr[j * output_col + k] = sum;
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