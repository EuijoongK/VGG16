#include "../include/datahandler/datahandler.h"

int main(){
    char* fname1 = "../sample/test0123.bin";
    char* fname2 = "../sample/conv3d_output.bin";

    struct FeatureMap* input1 = load_input_binary(fname1, 510, 510, 1);
    struct FeatureMap* input2 = load_input_binary(fname2, 510, 510, 1);

    FILE* fp1 = fopen("./test0123.txt", "w");
    FILE* fp2 = fopen("./conv3d_output.txt", "w");

    uint32_t row = input1 -> row;
    uint32_t col = input1 -> col;

    uint32_t i, j;
    for(i = 0; i < row; ++i){
        for(j = 0; j < col; ++j){
            fprintf(fp1, "%f\t", *(input1 -> data + i * col + j));
            fprintf(fp2, "%f\t", *(input2 -> data + i * col + j));
        }
        fprintf(fp1, "\n");
        fprintf(fp2, "\n");
    }

    freeFeatureMap(input1);
    freeFeatureMap(input2);

    fclose(fp1);
    fclose(fp2);
}