#include "../include/model/model.h"
#include "../include/datahandler/datahandler.h"

int main(){
    float kernel_weight[27] = {-1, -1, -1, 0, 0, 0, 1, 1, 1,
                                -2, -2, -2, 0, 0, 0, 2, 2, 2,
                                -1, -1, -1, 0, 0, 0, 1, 1, 1};
    float kernel_bias[] = {0};
    struct Kernel kernel;
    kernel.row = 3;
    kernel.col = 3;
    kernel.channel = 3;
    kernel.num = 1;
    kernel.weight = kernel_weight;
    kernel.bias = kernel_bias;

    printf("Loading input file...\n");
    struct FeatureMap* input = load_input_binary("../sample/lena.bin", 512, 512, 3);
    printf("Input file loaded!\n");

    printf("Applying convolution...\n");
    struct FeatureMap* output = Conv3D2(
        input, &kernel, 1, 1, 0, 0
    );
    printf("Convolution finished!\n");

    printf("Output file open attempt...\n");
    FILE* fp = fopen("../sample/test_conv.bin", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        return 1;
    }
    printf("Output file opened!\n");

    uint32_t i, j, k;
    uint32_t row = output -> row;
    uint32_t col = output -> col;
    uint32_t channel = output -> channel;

    uint8_t* buf = (uint8_t*)malloc(sizeof(uint8_t) * 1);

    for(i = 0; i < row; ++i){
        for(j = 0; j < col; ++j){
            uint8_t data_r = (uint8_t)(*(output -> data + i * col + j));
            //uint8_t data_g = (uint8_t)(*(output -> data + i * col + j + row * col));
            //uint8_t data_b = (uint8_t)(*(output -> data + i * col + j + row * col * 2));

            *buf = data_r;
            //*(buf + 1) = data_g;
            //*(buf + 2) = data_b;

            fwrite(buf, sizeof(uint8_t), 1, fp);
        }
    }

    free(buf);
    fclose(fp);
    printf("Memory free for input file...\n");
    freeFeatureMap(input);
    printf("Success\n");
    printf("Memory free for output file...\n");
    freeFeatureMap(output);
    printf("Success\n");
}