#pragma once

#include "../include/percolation.h"

class PercolationStats {
        
    public:

    typedef unsigned int uint;

    PercolationStats(uint n, uint trials);

    // Compute mean of percolation threshold
    void   computeMean();

    // Getter for mean of percolation threshold
    double getMean();

    // standard deviation of percolation threshold
    double getStddev();

    // low endpoint of 95% confidence interval
    double confidenceLo();

    // high endpoint of 95% confidence interval
    double confidenceHi();

    void   union_find(uint ID1, uint ID2);

    double ComputeThreshold(Percolation& percolation);



    private:

    double Percolation_Threshold = 0.0;

    double mean;

    // Size of grid
    uint n;

    // Number of trials to be carried out in simulation
    uint trials;

};
