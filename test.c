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

    FILE* fp = fopen("./export/loaded_data.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        return 1;
    }

    char buffer[256];

    uint32_t i, j, k, m;
    uint32_t input_row = input -> row;
    uint32_t input_col = input -> col;
    uint32_t input_channel = input -> channel;

    for(i = 0; i < input_channel; ++i){
        for(j = 0; j < input_row; ++j){
            for(k = 0; k < input_col; ++k){
                fprintf(fp, "%lf\n", *(input -> data + i * input_row * input_col + j * input_col + k));
            }
        }
    }

    fclose(fp);
    freeFeatureMap(input);
    freeKernel(kernel);
}