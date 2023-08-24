class PercolationStats {

    typedef unsigned int uint;
    
    public:

    PercolationStats(uint n, uint trials);

    // mean of percolation threshold
    uint Percolation_Threshold[100];

    // checks if the nodes are connected
    void union_find(); //THE MAIN ALGORITHM

    // mean of percolation threshold
    double mean();

    // standard deviation of percolation threshold
    double stddev();

    // low endpoint of 95% confidence interval
    double confidenceLo();

    // high endpoint of 95% confidence interval
    double confidenceHi();

    private:

    // Size of grid
    uint n;

    // Number of trials to be carried out in simulation
    uint trials;

};
