#include "../include/datahandler/datahandler.h"

int main(){
    char* fname = "../sample/lenaRGB.bin";
    struct FeatureMap* input = load_input_binary(fname, 512, 512, 3);

    uint32_t row = input -> row;
    uint32_t col = input -> col;
    uint32_t channel = input -> channel;

    FILE* fp_r = fopen("../sample/lena_R.txt", "w");
    FILE* fp_g = fopen("../sample/lena_G.txt", "w");
    FILE* fp_b = fopen("../sample/lena_B.txt", "w");

    //for fp_r
    fprintf(fp_r, "%f\t", *(input -> data));
    fprintf(fp_r, "%f\t", *(input -> data + 3));
    fprintf(fp_r, "%f\t", *(input -> data + 6));
    fprintf(fp_r, "%f\t", *(input -> data + col * 3));
    fprintf(fp_r, "%f\t", *(input -> data + col * 3 + 3));
    fprintf(fp_r, "%f\t", *(input -> data + col * 3 + 6));
    fprintf(fp_r, "%f\t", *(input -> data + col * 6));
    fprintf(fp_r, "%f\t", *(input -> data + col * 6 + 3));
    fprintf(fp_r, "%f\t", *(input -> data + col * 6 + 6));

    //for fp_g
    fprintf(fp_g, "%f\t", *(input -> data + 1));
    fprintf(fp_g, "%f\t", *(input -> data + 3 + 1));
    fprintf(fp_g, "%f\t", *(input -> data + 6 + 1));
    fprintf(fp_g, "%f\t", *(input -> data + col * 3 + 1));
    fprintf(fp_g, "%f\t", *(input -> data + col * 3 + 3 + 1));
    fprintf(fp_g, "%f\t", *(input -> data + col * 3 + 6 + 1));
    fprintf(fp_g, "%f\t", *(input -> data + col * 6 + 1));
    fprintf(fp_g, "%f\t", *(input -> data + col * 6 + 3 + 1));
    fprintf(fp_g, "%f\t", *(input -> data + col * 6 + 6 + 1));

    //for fp_r
    fprintf(fp_b, "%f\t", *(input -> data + 2));
    fprintf(fp_b, "%f\t", *(input -> data + 3 + 2));
    fprintf(fp_b, "%f\t", *(input -> data + 6 + 2));
    fprintf(fp_b, "%f\t", *(input -> data + col * 3 + 2));
    fprintf(fp_b, "%f\t", *(input -> data + col * 3 + 3 + 2));
    fprintf(fp_b, "%f\t", *(input -> data + col * 3 + 6 + 2));
    fprintf(fp_b, "%f\t", *(input -> data + col * 6 + 2));
    fprintf(fp_b, "%f\t", *(input -> data + col * 6 + 3 + 2));
    fprintf(fp_b, "%f\t", *(input -> data + col * 6 + 6 + 2));

    fclose(fp_r);
    fclose(fp_g);
    fclose(fp_b);
}