#include "../include/model/model.h"
#include "../include/datahandler/datahandler.h"

int main(){
    double kernel_weight[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    double kernel_bias[] = {0, 0, 0};
    struct Kernel kernel;
    kernel.row = 3;
    kernel.col = 3;
    kernel.channel = 1;
    kernel.num = 1;
    kernel.weight = kernel_weight;
    kernel.bias = kernel_bias;

    printf("Loading input file...\n");
    struct FeatureMap* input = load_input_binary("./export/lena.bin", 512, 512, 1);
    printf("Input file loaded!\n");

    printf("Applying convolution...\n");
    struct FeatureMap* output = Conv3D(
        input, &kernel, 1, 1, 1, 1
    );
    printf("Convolution finished!\n");

    printf("Output file open attempt...\n");
    FILE* fp = fopen("./export/test_conv.bin", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        return 1;
    }
    printf("Output file opened!\n");

    uint32_t i, j, k;
    uint32_t row = output -> row;
    uint32_t col = output -> col;
    uint32_t channel = output -> channel;

    unsigned char* buf = (unsigned char*)malloc(sizeof(unsigned char) * row * col);

    for(i = 0; i < row; ++i){
        for(j = 0; j < col; ++j){
            uint8_t data_r = (uint8_t)(*(output -> data + i * col + j));
            //unsigned char data_g = (unsigned char)(*(output -> data + row * col + i * col + j));
            //unsigned char data_b = (unsigned char)(*(output -> data + row * col * 2 + i * col + j));
            *(buf + i * col + j) = data_r;
            fwrite(buf + i * col + j, sizeof(uint8_t), 1, fp);
            //fwrite(data_g, sizeof(uint8_t), 1, fp);
            //fwrite(data_b, sizeof(uint8_t), 1, fp);
        }
    }

    fclose(fp);
    printf("Memory free for input file...\n");
    freeFeatureMap(input);
    printf("Success\n");
    printf("Memory free for output file...\n");
    freeFeatureMap(output);
    printf("Success\n");
}