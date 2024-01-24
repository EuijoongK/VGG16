#include "../../include/featuremap/featuremap.h"

void summary_featuremap(const struct FeatureMap* input){
    printf("-------------------------\n");
    printf("FeatureMap Summary\n");
    printf("Row : %d\n", input -> row);
    printf("Col : %d\n", input -> col);
    printf("Channel : %d\n", input -> channel);
    
    printf("-------------------------\n");
    return;
}

void summary_kernel(const struct Kernel* input){
    printf("-------------------------\n");
    printf("Kernel Summary\n");
    printf("Row : %d\n", input -> row);
    printf("Col : %d\n", input -> col);
    printf("Channel : %d\n", input -> channel);
    printf("Number : %d\n", input -> num);
    printf("-------------------------\n");
    return;
}

struct FeatureMap* Zeropadd(
    const struct FeatureMap* featuremap,
    const uint32_t padding_num
){
    uint32_t output_row = featuremap -> row + 2 * padding_num;
    uint32_t output_col = featuremap -> col + 2 * padding_num;
    uint32_t output_channel = featuremap -> channel;
    float* output_data = (float*)malloc(output_row * output_col * output_channel * sizeof(float));
    memset(output_data, 0, output_row * output_col * output_channel * sizeof(float));

    uint32_t featuremap_sz = featuremap -> row * featuremap -> col;
    uint32_t output_sz = output_row * output_col;
    
    uint32_t i, j;
    for (i = 0; i < featuremap -> channel; ++i) {
        float* data_ptr = featuremap -> data + i * featuremap_sz;
        float* output_data_ptr = output_data + i * output_sz;
        for (j = 0; j < featuremap -> row; ++j) {
            memcpy(output_data_ptr + (j + padding_num) * output_col + padding_num, data_ptr + j * featuremap -> col,
                sizeof(float) * featuremap -> col);
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

void freeFeatureMap(struct FeatureMap* featuremap){
    free(featuremap -> data);
    free(featuremap);
    return;
}

void freeKernel(struct Kernel* kernel){
    free(kernel -> weight);
    free(kernel -> bias);
    free(kernel);
    return;
}

void freearr1D(struct arr1D* arr){
    free(arr -> data);
    return;
}