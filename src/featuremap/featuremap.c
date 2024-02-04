#include "../../include/featuremap/featuremap.h"

void summary_featuremap(const struct FeatureMap* input){
    printf("-------------------------\n");
    printf("FeatureMap Summary\n");
    printf("Row : %d\n", input -> row);
    printf("Col : %d\n", input -> col);
    printf("Channel : %d\n", input -> channel);
    
    printf("-------------------------\n");
    return;
}

void summary_kernel(const struct Kernel* input){
    printf("-------------------------\n");
    printf("Kernel Summary\n");
    printf("Row : %d\n", input -> row);
    printf("Col : %d\n", input -> col);
    printf("Channel : %d\n", input -> channel);
    printf("Number : %d\n", input -> num);
    printf("-------------------------\n");
    return;
}

void freeFeatureMap(struct FeatureMap* featuremap){
    free(featuremap -> data);
    free(featuremap);
    return;
}

void freeKernel(struct Kernel* kernel){
    free(kernel -> weight);
    free(kernel -> bias);
    free(kernel);
    return;
}

void freearr1D(struct arr1D* arr){
    free(arr -> data);
    return;
}