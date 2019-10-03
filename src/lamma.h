//
// Created by pierfied on 10/2/19.
//

#ifndef LAMMA_LAMMA_H
#define LAMMA_LAMMA_H

#include <hmc.h>

extern "C" {

typedef struct LammaArgs_struct {
    long lmax;
    double *cl;
    double shift;
    long g_nside;
    double *mask;
    double *g1_obs;
    double *g2_obs;
} LammaArgs;

SampleChain lamma_sample(HMCArgs hmc_args, LammaArgs lamma_args);

Hamiltonian lamma_likelihood(double *x, void *args_ptr);

};

#endif //LAMMA_LAMMA_H
