#pragma once

#include "../include/percolation.h"

class PercolationStats {
        
    public:

    typedef unsigned int uint;

    PercolationStats(uint n, uint trials);

    // mean of percolation threshold
    uint Percolation_Threshold[100];

    // mean of percolation threshold
    double mean();

    // standard deviation of percolation threshold
    double stddev();

    // low endpoint of 95% confidence interval
    double confidenceLo();

    // high endpoint of 95% confidence interval
    double confidenceHi();

    void   union_find(uint ID1, uint ID2);

    double ComputeThreshold(Percolation& percolation);

    private:

    // Size of grid
    uint n;

    // Number of trials to be carried out in simulation
    uint trials;

};
