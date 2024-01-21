#include "../../include/datahandler/export_data.h"

void export_featuremap_binary(
    char* file_name,
    struct FeatureMap* target
){
    FILE* fp = fopen(file_name, "wb");

    uint32_t row, col, channel;
    row = target -> row;
    col = target -> col;
    channel = target -> channel;

    fwrite((void*)(target -> data), sizeof(float), row * col * channel, fp);

    fclose(fp);
}