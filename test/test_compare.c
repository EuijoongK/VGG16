#include "../include/model/model.h"
#include "../include/datahandler/datahandler.h"

int main(){
    printf("Loading First input...\n");
    struct FeatureMap* input1 = load_input_binary("../sample/lena.bin", 512, 512, 3);
    printf("Loading Second input...\n");
    struct FeatureMap* input2 = load_input_binary("/mnt/c/Users/MICS/Desktop/lena.bin", 512, 512, 3);

    uint32_t i, j, k;
    uint8_t flag = 0;

    uint32_t channel = input1 -> channel;
    uint32_t row = input1 -> row;
    uint32_t col = input1 -> col;

    for(i = 0; i < row; ++i){
        for(j = 0; j < col; ++j){
            for(k = 0; k < channel; ++k){
                float val1 = *(input1 -> data + i * col * channel + j * channel + k);
                float val2 = *(input2 -> data + i * col * channel + j * channel + k);
                if(val1 != val2){
                    printf("%lf != %lf\n", val1, val2);
                    flag = 1;
                }
            }
        }
    }

    if(flag){
        printf("Two inputs are different\n");
    }else{
        printf("Two inputs are same\n");
    }

    freeFeatureMap(input1);
    freeFeatureMap(input2);
}