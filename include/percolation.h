class Percolation {
public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation(int n);

    // opens the site (row, col) if it is not open already
    void open(int row, int col);

    // is the site (row, col) open?
    bool isOpen(int row, int col);

    // is the site (row, col) full?
    bool isFull(int row, int col);

    // returns the number of open sites
    int numberOfOpenSites();

    // does the system percolate?
    bool percolates();

};