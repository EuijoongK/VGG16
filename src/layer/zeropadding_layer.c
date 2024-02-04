#include "../../include/layer/zeropadding_layer.h"

struct FeatureMap* Zeropadding(
    const struct FeatureMap* input,
    const uint32_t padding_num
){
    struct FeatureMap* output = Zeropadd(input, padding_num);
    return output;
}

struct FeatureMap* Zeropadd(
    const struct FeatureMap* featuremap,
    const uint32_t padding_num
){
    uint32_t input_row = featuremap -> row;
    uint32_t input_col = featuremap -> col;
    float* input_data = featuremap -> data;
    uint32_t input_channel = featuremap -> channel;
    uint32_t output_row = input_row + 2 * padding_num;
    uint32_t output_col = input_col + 2 * padding_num;
    uint32_t output_channel =   input_channel;
    float* output_data = (float*)malloc(output_row * output_col * output_channel * sizeof(float));
    memset(output_data, 0, output_row * output_col * output_channel * sizeof(float));

    uint32_t featuremap_sz = featuremap -> row * featuremap -> col;
    uint32_t buffer_size = input_channel;
    
    uint32_t i, j;
    
    float* input_ptr;
    float* output_ptr;
    for(i = 0; i < input_row; ++i){
        for(j = 0; j < input_col; ++j){
            output_ptr = output_data + ((i + padding_num) * output_row + j + padding_num) * output_channel;
            input_ptr = input_data + (i * input_row + j) * input_channel;
            memcpy(output_ptr, input_ptr, sizeof(float) * buffer_size);
        }
    }

    struct FeatureMap* output = (struct FeatureMap*)malloc(sizeof(struct FeatureMap));
    output -> row = output_row;
    output -> col = output_col;
    output -> channel = output_channel;
    output -> data = output_data;
    return output;
}

struct FeatureMap* Zeropadd2(
    const struct FeatureMap* input,
    const uint32_t padding_num
){
    uint32_t output_row = input -> row + 2 * padding_num;
    uint32_t output_col = input -> col + 2 * padding_num;
    uint32_t output_channel = input -> channel;
    float* output_data = (float*)malloc(output_row * output_col * output_channel * sizeof(float));
    memset(output_data, 0, output_row * output_col * output_channel * sizeof(float));

    uint32_t input_sz = input -> row * input -> col;
    uint32_t output_sz = output_row * output_col;
    
    uint32_t i, j;
    for (i = 0; i < input -> channel; ++i) {
        float* data_ptr = input -> data + i * input_sz;
        float* output_data_ptr = output_data + i * output_sz;
        for (j = 0; j < input -> row; ++j) {
            memcpy(output_data_ptr + (j + padding_num) * output_col + padding_num, data_ptr + j * input -> col,
                sizeof(float) * input -> col);
        }
    }

    struct FeatureMap* output = (struct FeatureMap*)malloc(sizeof(struct FeatureMap));
    output -> row = output_row;
    output -> col = output_col;
    output -> channel = output_channel;
    output -> data = output_data;
    return output;
}
