#include "../include/datahandler/datahandler.h"

int main(){
    char* fname = "../sample/conv3d_output.bin";
    struct FeatureMap* input = load_input_binary(fname, 510, 510, 1);

    FILE* fp = fopen("../sample/lena_conv_torch.txt", "w");
    uint32_t row = input -> row;
    uint32_t col = input -> col;
    uint32_t ch = input -> channel;

    uint32_t i, j, k;
    for(i = 0; i < row; ++i){
        for(j = 0; j < col; ++j){
            for(k = 0; k < ch; ++k){
                fprintf(fp, "%f\t", *(input -> data + i * col * ch + j * ch + k));
            }
        }
    }

    fclose(fp);
    freeFeatureMap(input);
}