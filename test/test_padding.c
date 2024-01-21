//gcc test_padding.c -o test_padding -I../include

#include "../include/model/model.h"
#include "../include/datahandler/datahandler.h"

int main(){
    uint32_t row = 3;
    uint32_t col = 3;
    uint32_t channel = 3;
    size_t sz = row * col * channel;

    float* arr = (float*)malloc(sizeof(float) * sz);
    for(uint32_t i = 0; i < sz; ++i){
        *(arr + i) = i + 1;
    }

    struct FeatureMap input;
    input.row = row;
    input.col = col;
    input.channel = channel;
    input.data = arr;

    struct FeatureMap* output = Zeropadding(&input, 2);

    for(uint32_t i = 0; i < output -> channel; ++i){
        for(uint32_t j = 0; j < output -> row; ++j){
            for(uint32_t k = 0; k < output -> col; ++k){
                printf("%lf\t", *(output -> data + i * output -> row * output -> col + j * output -> col + k));
            }
            printf("\n");
        }
        printf("\n");
    }

    freeFeatureMap(output);
    free(arr);
}