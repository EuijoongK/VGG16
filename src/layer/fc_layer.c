#include "../../include/layer/fc_layer.h"

struct arr1D* cvt_featuremap2arr1d(
    const struct FeatureMap* input
){
    const uint32_t input_row = input -> row;
    const uint32_t input_col = input -> col;
    const uint32_t input_channel = input -> channel;
    const double* input_data = input -> data;
    uint32_t input_sz = input_row * input_col;
    double* data = (double*)malloc(input_sz * input_channel * sizeof(double));

    uint32_t i, j, k;
    for(i = 0; i < input_channel; ++i){
        const double* input_data_ptr = input_data + i * input_sz;
        for(j = 0; j < input_row; ++j){
            memcpy(data + i * input_sz + j * input_col, input_data_ptr + j * input_col, input_col * sizeof(double));
        }
    }

    struct arr1D* output = (struct arr1D*)malloc(sizeof(struct arr1D));
    output -> num_element = input_sz * input_channel;
    output -> data = data;
    return output;
}

struct arr1D* Fullyconnect(
    const struct arr1D* input,
    const struct kernel1D* kernel
){
    const uint32_t input_sz = input -> num_element;
    const double* input_data = input -> data;

    const uint32_t num_kernel = kernel -> num_kernel;
    const uint32_t num_kernel_element = kernel -> num_element;
    const double* kernel_data = kernel -> data;
    const double* kernel_bias = kernel -> bias;

    uint32_t output_num_element = num_kernel;
    double* output_data = (double*)malloc(output_num_element * sizeof(double));

    uint32_t i, j;
    for(i = 0; i < output_num_element; ++i){
        const double* kernel_ptr = kernel_data + i * num_kernel_element;
        double sum = kernel_bias[i];
        for(j = 0; j < num_kernel_element; ++j){
            sum += kernel_ptr[j] * input_data[j];
        }
        output_data[i] = sum;
    }

    struct arr1D* output = (struct arr1D*)malloc(sizeof(struct arr1D*));
    output -> num_element = output_num_element;
    output -> data = output_data;
    return output;
}