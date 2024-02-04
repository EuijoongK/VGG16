#include "../../include/datahandler/datahandler.h"

struct Kernel* load_conv_kernel_binary(
    char* file_weight,
    char* file_bias,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t kernel_channel,
    uint32_t kernel_num
){
    uint32_t size = kernel_row * kernel_col;
    float* weight = (float*)malloc(size * kernel_channel * kernel_num * sizeof(float));
    float* buf = (float*)malloc(size * kernel_channel * kernel_num * sizeof(float));
    float* bias = (float*)malloc(kernel_num * sizeof(float));

    FILE* fp = fopen(file_weight, "rb");
    fread((void*)buf, sizeof(float), size * kernel_channel * kernel_num, fp);
    fclose(fp);

    fp = fopen(file_bias, "rb");
    fread((void*)bias, sizeof(float), kernel_num, fp);
    fclose(fp);

    uint32_t i, j, k, m;
    for(i = 0; i < kernel_num; ++i){
        float* kernel_weight = weight + i * kernel_channel * size;
        float* current_kernel = buf + i * kernel_channel * size;
        for(j = 0; j < kernel_row; ++j){
            for(k = 0; k < kernel_col; ++k){
                for(m = 0; m < kernel_channel; ++m){
                    *(kernel_weight + j * kernel_col + k + m * size) = *(current_kernel + j * kernel_col * kernel_channel +
                        k * kernel_channel + m);
                }
            }
        }
    }

    struct Kernel* kernel = (struct Kernel*)malloc(sizeof(struct Kernel));
    kernel -> row = kernel_row;
    kernel -> col = kernel_col;
    kernel -> channel = kernel_channel;
    kernel -> num = kernel_num;
    kernel -> weight = weight;
    kernel -> bias = bias;

    return kernel;
}

// Load # of Kernel, Row, Col, Channel -wise kernel binary file
struct Kernel* load_conv_kernel_binary2(
    char* file_weight,
    char* file_bias,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t kernel_channel,
    uint32_t kernel_num
){
    uint32_t size = kernel_row * kernel_col;
    float* weight = (float*)malloc(size * kernel_channel * kernel_num * sizeof(float));
    float* buf = (float*)malloc(size * kernel_channel * kernel_num * sizeof(float));
    float* bias = (float*)malloc(kernel_num * sizeof(float));

    FILE* fp = fopen(file_weight, "rb");
    fread((void*)buf, sizeof(float), size * kernel_channel * kernel_num, fp);
    fclose(fp);

    fp = fopen(file_bias, "rb");
    fread(bias, sizeof(float), kernel_num, fp);
    fclose(fp);

    uint32_t i, j, k, m;
    for(i = 0; i < kernel_num; ++i){
        float* kernel_weight = weight + i * kernel_channel * size;
        float* current_kernel = buf + i * kernel_channel * size;
        for(j = 0; j < kernel_row; ++j){
            for(k = 0; k < kernel_col; ++k){
                for(m = 0; m < kernel_channel; ++m){
                    *(kernel_weight + j * kernel_col + k + m * size) = *(current_kernel + j * kernel_col * kernel_channel +
                        k * kernel_channel + m);
                }
            }
        }
    }

    struct Kernel* kernel = (struct Kernel*)malloc(sizeof(struct Kernel));
    kernel -> row = kernel_row;
    kernel -> col = kernel_col;
    kernel -> channel = kernel_channel;
    kernel -> num = kernel_num;
    kernel -> weight = weight;
    kernel -> bias = bias;

    return kernel;
}

// Load input RGB pixels in row col wise input binary
struct FeatureMap* load_input_binary(
    char* file_name,
    uint32_t input_row,
    uint32_t input_col,
    uint32_t input_channel
){
    FILE* fp = fopen(file_name, "rb");
    uint8_t* buf = (uint8_t*)malloc(input_row * input_col * input_channel * sizeof(uint8_t));
    float* data = (float*)malloc(input_row * input_col * input_channel * sizeof(float));

    fread((void*)buf, sizeof(uint8_t), input_row * input_col * input_channel, fp);

    uint32_t input_size = input_row * input_col;

    uint32_t i, j, k;
    for(i = 0; i < input_row; ++i){
        for(j = 0; j < input_col; ++j){
            for(k = 0; k < input_channel; ++k){
                *(data + k * input_size + i * input_col + j) = (float)(*(buf + i * input_col * input_channel +
                    j * input_channel + k));
            }
        }
    }

    struct FeatureMap* output = (struct FeatureMap*)malloc(sizeof(struct FeatureMap));
    output -> row = input_row;
    output -> col = input_col;
    output -> channel = input_channel;
    output -> data = data;

    free(buf);
    return output;
}

struct FeatureMap* load_input_binary2(
    char* file_name,
    uint32_t input_row,
    uint32_t input_col,
    uint32_t input_channel
){
    FILE* fp = fopen(file_name, "rb");
    uint8_t* buf = (uint8_t*)malloc(input_row * input_col * input_channel * sizeof(uint8_t));
    float* data = (float*)malloc(input_row * input_col * input_channel * sizeof(float));

    fread((void*)buf, sizeof(uint8_t), input_row * input_col * input_channel, fp);

    uint32_t i, j, k;
    for(i = 0; i < input_row; ++i){
        for(j = 0; j < input_col; ++j){
            for(k = 0; k < input_channel; ++k){
                *(data + i * input_col * input_channel + j * input_channel + k) = (float)(*(buf + i * input_col * input_channel +
                    j * input_channel + k));
            }
        }
    }

    struct FeatureMap* output = (struct FeatureMap*)malloc(sizeof(struct FeatureMap));
    output -> row = input_row;
    output -> col = input_col;
    output -> channel = input_channel;
    output -> data = data;

    free(buf);
    return output;
}