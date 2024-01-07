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
    double* data;
};

struct Kernel{
    uint32_t row;
    uint32_t col;
    uint32_t num;
    uint32_t channel;
    double* weight;
    double* bias;
};

struct arr1D{
    uint32_t num_element;
    double* data;
};

struct kernel1D{
    uint32_t num_element;
    uint32_t num_kernel;
    double* data;
    double* bias;
};

void summary_featuremap(const struct FeatureMap* input);
void summary_kernel(const struct Kernel* input);
void get_data(const struct FeatureMap* input);

struct FeatureMap* Zeropadd(
    const struct FeatureMap* featuremap,
    const uint32_t padding_num
);

void freeFeatureMap(struct FeatureMap* featuremap);
void freeKernel(struct Kernel* kernel);
void freearr1D(struct arr1D* arr);

#endif