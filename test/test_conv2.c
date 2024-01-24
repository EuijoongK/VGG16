#include "../include/layer/conv_layer.h"

int main(){
    float data[] = {1, 1, 1, 2, 2, 2, 0, 3, 3,
                    0, 3, 2, 0, 1, 1, 1, 0, 0,
                    1, 0, 3, 0, 1, 0, 5, 0, 1};
    float weight[] = {1, 1, 0, 0, 1, 0, 0, 1, 0,
                    1, 0, 1};
    float bias[] = {0};

    struct FeatureMap input;
    input.row = 3;
    input.col = 3;
    input.channel = 3;
    input.data = data;

    struct Kernel kernel;
    kernel.row = 2;
    kernel.col = 2;
    kernel.channel = 3;
    kernel.num = 1;
    kernel.weight = weight;
    kernel.bias = bias;

    struct FeatureMap* output = Conv3D2(
        &input,
        &kernel,
        1, 1, 0, 0
    );

    uint32_t i, j, k;
    uint32_t row = output -> row;
    uint32_t col = output -> col;
    uint32_t channel = output -> channel;

    for(i = 0; i < row; ++i){
        for(j = 0; j < col; ++j){
            for(k = 0; k < channel; ++k){
                printf("%f\t", *(output -> data + i * col * channel + j * channel + k));
            }
        }
        printf("\n");
    }

    freeFeatureMap(output);
}