#pragma once

#include "../include/percolation.h"

class PercolationStats {
        
    public:

    typedef unsigned int uint;

    PercolationStats(uint n, uint trials);

    // Compute mean of percolation threshold
    void   computeMean();

    // Getter for standard deviation
    void   computeStddev();

    // low endpoint of 95% confidence interval
    void   computeConfidenceLo();

    // high endpoint of 95% confidence interval
    void   computeConfidenceHi();

    // Getter for mean of percolation threshold
    double getMean();

    // standard deviation of percolation threshold
    double getStddev();

    // low endpoint of 95% confidence interval
    double getConfidenceLo();

    // high endpoint of 95% confidence interval
    double getConfidenceHi();

    void   ComputeThreshold(Percolation& percolation);

    private:

    double Percolation_Threshold = 0.0;

    double mean;
    double StdDev;

    // stores open sites
    std::vector<double> Percolation_Thresholds;

    // Size of grid
    uint n;

    //Confidence intervals
    double ConfidenceLo;
    double ConfidenceHi;

    // Number of trials to be carried out in simulation
    uint trials;

};
