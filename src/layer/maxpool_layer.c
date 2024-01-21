#include "../../include/layer/maxpool_layer.h"

void calculate_maxpool_sz(
    const uint32_t input_row,
    const uint32_t input_col,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t stride_row,
    const uint32_t stride_col,
    uint32_t* output_row,
    uint32_t* output_col
){
    *output_row = (uint32_t)((input_row - kernel_row) / stride_row) + 1;
    *output_col = (uint32_t)((input_col - kernel_col) / stride_col) + 1;
    return;
}

struct FeatureMap* Maxpool(
    const struct FeatureMap* input,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t stride_row,
    const uint32_t stride_col
){  
    uint32_t input_row = input -> row;
    uint32_t input_col = input -> col;
    uint32_t input_channel = input -> channel;
    const float* input_data = input -> data;
    uint32_t output_row, output_col;
    calculate_maxpool_sz(input_row, input_col, kernel_row, kernel_col,
                        stride_row, stride_col, &output_row, &output_col);
    uint32_t output_channel = input_channel;
    float* output_data = (float*)malloc(output_row * output_col * output_channel * sizeof(float));
    float* arr = (float*)malloc(kernel_row * kernel_col * sizeof(float));

    uint32_t input_sz = input_row * input_col;
    uint32_t output_sz = output_row * output_col;
    uint32_t kernel_sz = kernel_row * kernel_col;
    uint32_t i, j, k, m;
    for(i = 0; i < input_channel; ++i){
        const float* input_data_ptr = input_data + i * input_sz;
        float* output_data_ptr = output_data + i * output_sz;
        for(j = 0; j < output_row; ++j){
            for(k = 0; k < output_col; ++k){
                for(m = 0; m < kernel_row; ++m){
                    memcpy(arr + m * kernel_col, input_data_ptr + (j * stride_row + m) * input_col + k * stride_col,
                        kernel_row * kernel_col * sizeof(float));
                }
                float max_value = 0;
                for(uint32_t n = 0; n < kernel_sz; ++n){
                    if(max_value < arr[n]){
                        max_value = arr[n];
                    }
                }
                *(output_data_ptr + j * output_sz + k) = max_value;
            }
        }
    }

    struct FeatureMap* output = (struct FeatureMap*)malloc(sizeof(struct FeatureMap));
    output -> row = output_row;
    output -> col = output_col;
    output -> channel = output_channel;
    output -> data = output_data;

    free(arr);
    return output;
}