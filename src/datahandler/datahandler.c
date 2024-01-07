#include "../../include/datahandler/datahandler.h"

struct Kernel* load_con_kernel(
    char* file_weight,
    char* file_bias,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t kernel_channel,
    uint32_t kernel_num
){
    char buffer[256];
    FILE* fp = fopen(file_weight, "r");
    double* weight = (double*)malloc(kernel_num * kernel_channel * kernel_row * kernel_col * sizeof(double));

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
    double* bias = (double*)malloc(kernel_num * sizeof(double));
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

struct FeatureMap* load_input(
    char* file_name,
    uint32_t input_row,
    uint32_t input_col,
    uint32_t input_channel
){
    char buffer[256];
    FILE* fp = fopen(file_name, "r");
    double* data = (double*)malloc(input_row * input_col * input_channel * sizeof(double));

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