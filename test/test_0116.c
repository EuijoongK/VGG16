#include "../include/model/model.h"
#include "../include/datahandler/datahandler.h"

int main(){

    struct FeatureMap* input = load_input(
        "./export/lena.txt",
        512, 512, 3
    );
    struct Kernel* kernel = load_con_kernel(
        "./export/first_conv_layer_weight.txt",
        "./export/first_conv_layer_bias.txt",
        3, 3, 3, 64
    );

    FILE* fp = fopen("./export/first_convolution.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        return 1;
    }

    struct FeatureMap* output = Conv3D(
        input,
        kernel,
        1,
        1,
        1,
        0
    );

    uint32_t i, j, k, m;
    uint32_t output_row = output -> row;
    uint32_t output_col = output -> col;
    uint32_t output_channel = output -> channel;

    for(i = 0; i < output_channel; ++i){
        for(j = 0; j < output_row; ++j){
            for(k = 0; k < output_col; ++k){
                fprintf(fp, "%lf\n", *(output -> data + i * output_row * output_col + j * output_col + k));
            }
        }
    }

    fclose(fp);
    freeFeatureMap(input);
    freeFeatureMap(output);
    freeKernel(kernel);
}