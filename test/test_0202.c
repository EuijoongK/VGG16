#include "../include/datahandler/datahandler.h"
#include "../include/layer/conv_layer.h"

int main(){
    printf("Loading input image...\n");
    struct FeatureMap* input = load_input_binary("../sample/lena.bin", 512, 512, 3);

/*
    printf("Loading convolution kernel...\n");
    struct Kernel* kernel = load_conv_kernel_binary("../sample/conv1_weight.bin", "", 3, 3, 3, 64);

    float bias[64] = {0, };
    kernel -> bias = bias;
*/
    struct Kernel kernel;
    kernel.row = 3;
    kernel.col = 3;
    kernel.channel = 3;
    kernel.num = 1;

    float weight[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1,
                    -1, 0, 1, -2, 0, 2, -1, 0, 1,
                    -1, 0, 1, -2, 0, 2, -1, 0, 1};
    float bias[] = {0};

    kernel.weight = weight;
    kernel.bias = bias;

    printf("Convolution layer...\n");
    struct FeatureMap* output = Conv3D(
        input,
        &kernel,
        1, 1, 0, 0
    );

    printf("Convolution Done.\n");
    printf("Opeing output file...\n");

    FILE* fp = fopen("../sample/test_0202.bin", "wb");

    float* output_data = output -> data;
    size_t num = (output -> row) * (output -> col) * (output -> channel);

    printf("Writing output data @ file...\n");
    
    uint32_t row = output -> row;
    uint32_t col = output -> col;
    uint32_t channel = output -> channel;

    uint32_t i, j, k;
    
    for(i = 0; i < row; ++i){
        for(j = 0; j < col; ++j){
            for(k = 0; k < channel; ++k){
                fwrite((void*)(output_data + k * row * col + i * col + j), sizeof(float), 1, fp);
            }
        }
    }

    fclose(fp);

    printf("-----------------------\n");
    for(i = 0; i < 3; ++i){
        printf("%d channel\n", i + 1);
        for(j = 0; j < 3; ++j){
            for(k = 1; k < 4; ++k){
                printf("%f\t", *(input -> data + i * (input -> row) * (input -> col) + j * (input -> col) + k));
            }
            printf("\n");
        }
    }

    printf("Memory free...\n");
    printf("Input...\n");
    freeFeatureMap(input);
    printf("Output...\n");
    freeFeatureMap(output);
    printf("Kernel...\n");
    //freeKernel(kernel);
}