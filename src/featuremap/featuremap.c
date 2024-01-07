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

void get_data(const struct FeatureMap* input){
    uint32_t input_row = input -> row;
    uint32_t input_col = input -> col;
    uint32_t input_channel = input -> channel;
    uint32_t input_sz = input_row * input_col;
    double* input_data = input -> data;

    uint32_t i, j, k;
    for(i = 0; i < input_channel; ++i){
        for(j = 0; j < input_row; ++j){
            for(k = 0; k < input_col; ++k){
                printf("%lf ", *(input_data + i * input_sz + j * input_col + k));
            }
            printf("\n");
        }
        printf("\n");
    }
    return;
}

struct FeatureMap* Zeropadd(
    const struct FeatureMap* featuremap,
    const uint32_t padding_num
){
    uint32_t output_row = featuremap -> row + 2 * padding_num;
    uint32_t output_col = featuremap -> col + 2 * padding_num;
    uint32_t output_channel = featuremap -> channel;
    double* output_data = (double*)malloc(output_row * output_col * output_channel * sizeof(double));
    memset(output_data, 0, output_row * output_col * output_channel * sizeof(double));

    uint32_t featuremap_sz = featuremap -> row * featuremap -> col;
    uint32_t output_sz = output_row * output_col;
    
    uint32_t i, j;
    for (i = 0; i < featuremap -> channel; ++i) {
        double* data_ptr = featuremap -> data + i * featuremap_sz;
        double* output_data_ptr = output_data + i * output_sz;
        for (j = 0; j < featuremap -> row; ++j) {
            memcpy(output_data_ptr + (j + padding_num) * output_col + padding_num, data_ptr + j * featuremap -> col,
                sizeof(double) * featuremap -> col);
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