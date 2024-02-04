#ifndef FEATUREMAP_H
#define FEATUREMAP_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

struct FeatureMap{
    uint32_t row;
    uint32_t col;
    uint32_t channel;
    float* data;
};

struct Kernel{
    uint32_t row;
    uint32_t col;
    uint32_t num;
    uint32_t channel;
    float* weight;
    float* bias;
};

struct arr1D{
    uint32_t num_element;
    float* data;
};

struct kernel1D{
    uint32_t num_element;
    uint32_t num_kernel;
    float* data;
    float* bias;
};

void summary_featuremap(const struct FeatureMap* input);
void summary_kernel(const struct Kernel* input);

void freeFeatureMap(struct FeatureMap* featuremap);
void freeKernel(struct Kernel* kernel);
void freearr1D(struct arr1D* arr);

#endif