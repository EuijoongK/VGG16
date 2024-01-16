#include "../include/model/model.h"
#include "../include/datahandler/datahandler.h"

int main(){
    struct FeatureMap* input1 = load_input_binary("./export/lena.bin", 512, 512, 3);
    struct FeatureMap* input2 = load_input("./export/lena.txt", 512, 512, 3);

    uint32_t i, j, k;
    uint8_t flag = 0;
    for(i = 0; i < input1 -> channel; ++i){
        for(j = 0; j < input1 -> row; ++j){
            for(k = 0; k < input1 -> col; ++k){
                double val1 = *(input1 -> data + i * input1 -> row * input1 -> col +
                                j * input1 -> col + k);
                double val2 = *(input2 -> data + i * input2 -> row * input2 -> col +
                                j * input2 -> col + k);
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