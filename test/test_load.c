#include "../include/model/model.h"
#include "../include/datahandler/datahandler.h"

int main(){
    struct FeatureMap* input1 = load_input_binary("./export/lena.bin", 512, 512, 3);
    struct FeatureMap* input2 = load_input("./export/lena.txt", 512, 512, 3);

    uint32_t i, j, k;
    uint8_t flag = 0;

    uint32_t channel = input1 -> channel;
    uint32_t row = input1 -> row;
    uint32_t col = input1 -> col;

    for(i = 0; i < channel; ++i){
        for(j = 0; j < row; ++j){
            for(k = 0; k < col; ++k){
                double val1 = *(input1 -> data + i * row * col +
                                j * col + k);
                double val2 = *(input2 -> data + i * row * col +
                                j * col + k);
                if(val1 != val2){
                    flag = 1;
                    printf("%lf != %lf\n", val1, val2);
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