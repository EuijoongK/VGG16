#include "../include/model/model.h"
#include "../include/datahandler/datahandler.h"

int main(){

    struct FeatureMap* input = load_input_binary(
        "./export/lena.bin",
        512, 512, 3
    );

    FILE* fp = fopen("./export/test.txt", "w");

    uint32_t row, col, channel;

    row = input -> row;
    col = input -> col;
    channel = input -> channel;

    uint32_t i, j, k;
    for(i = 0; i < channel; ++i){
        for(j = 0; j < row; ++j){
            for(k = 0; k < col; ++k){
                fprintf(fp, "%d\n", (int)(*(input -> data + i * row * col + j * col + k)));
            }
        }
    }

    fclose(fp);
    freeFeatureMap(input);
}