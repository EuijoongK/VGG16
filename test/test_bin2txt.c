#include "../include/model/model.h"
#include "../include/datahandler/datahandler.h"

int main(){

    struct FeatureMap* input = load_input_binary(
        "../sample/conv3d_0125.bin",
        512, 512, 3
    );

    FILE* fp = fopen("../sample/lena_conv_torch_0125.txt", "w");

    uint32_t row, col, channel;

    row = input -> row;
    col = input -> col;
    channel = input -> channel;

    uint32_t i, j, k;

    for(i = 0; i < row; ++i){
        for(j = 0; j < col; ++j){
            for(k = 0; k < channel; ++k){
                fprintf(fp, "%d\t", (int)(*(input -> data + i * col * channel + j * channel + k)));
            }
        }
    }

    fclose(fp);
    freeFeatureMap(input);
}