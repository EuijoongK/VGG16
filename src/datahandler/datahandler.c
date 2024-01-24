#include "../../include/datahandler/datahandler.h"

// Load Channel Row Col wise kernel text file
struct Kernel* load_conv_kernel_txt(
    char* file_weight,
    char* file_bias,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t kernel_channel,
    uint32_t kernel_num
){
    char buffer[256];
    FILE* fp = fopen(file_weight, "r");
    float* weight = (float*)malloc(kernel_num * kernel_channel * kernel_row * kernel_col * sizeof(float));

    uint32_t i, j, k, m;
    for(i = 0; i < kernel_num; ++i){
        for(j = 0; j < kernel_channel; ++j){
            for(k = 0; k < kernel_row; ++k){
                for(m = 0; m < kernel_col; ++m){
                    fgets(buffer, sizeof(buffer), fp);
                    *(weight + i * kernel_channel * kernel_row * kernel_col +
                        j * kernel_row * kernel_col + k * kernel_col + m) = strtod(buffer, NULL);
                }
            }
        }
    }
    
    FILE* fp2 = fopen(file_bias, "r");
    float* bias = (float*)malloc(kernel_num * sizeof(float));
    for(i = 0; i < kernel_num; ++i){
        fgets(buffer, sizeof(buffer), fp2);
        *(bias + i) = strtod(buffer, NULL);
    }

    fclose(fp);
    fclose(fp2);

    struct Kernel* output = (struct Kernel*)malloc(sizeof(struct Kernel));
    output -> row = kernel_row;
    output -> col = kernel_col;
    output -> channel = kernel_channel;
    output -> num = kernel_num;
    output -> weight = weight;
    output -> bias = bias;
    return output;
}

// Load Channel Row Col wise input text file
struct FeatureMap* load_input_txt(
    char* file_name,
    uint32_t input_row,
    uint32_t input_col,
    uint32_t input_channel
){
    char buffer[256];
    FILE* fp = fopen(file_name, "r");
    float* data = (float*)malloc(input_row * input_col * input_channel * sizeof(float));

    uint32_t i, j, k;
    for(i = 0; i < input_channel; ++i){
        for(j = 0; j < input_row; ++j){
            for(k = 0; k < input_col; ++k){
                fgets(buffer, sizeof(buffer), fp);
                *(data + i * input_row * input_col + j * input_col + k) = strtod(buffer, NULL);
            }
        }
    }

    struct FeatureMap* output = (struct FeatureMap*)malloc(sizeof(struct FeatureMap));
    output -> row = input_row;
    output -> col = input_col;
    output -> channel = input_channel;
    output -> data = data;

    return output;
}

// Load # of Kernel, Row, Col, Channel -wise kernel binary file
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