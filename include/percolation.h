class PercolationStats {

    public:
    //int PercolationStats(int n, int trials);
    // mean of percolation threshold
    bool open[100];
    // checks if the nodes are connected
    void union_find();
    // mean of percolation threshold
    double mean();
    // standard deviation of percolation threshold
    double stddev();
    // low endpoint of 95% confidence interval
    double confidenceLo();
    // high endpoint of 95% confidence interval
    double confidenceHi();
};
