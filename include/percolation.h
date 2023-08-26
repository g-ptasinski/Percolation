#include <vector>

class Percolation {

    typedef unsigned int uint;

public:

    // creates n-by-n grid, with all sites initially blocked
    Percolation(uint n);            //[x]

    // opens the site (row, col) if it is not open already
    void open(uint row, uint col);  //[x]

    // is the site (row, col) open?
    bool isOpen(int row, int col);  //[x]

    // is the site (row, col) full?
    bool isFull(int row, int col);  //[x]

    // returns the number of open sites
    uint numberOfOpenSites();       //[x]

    // does the system percolate?
    bool percolates();

    // Test prints
    void Test( void );

private: 

    //Size of the side of grid
    uint iSize;

    //Total number of sites
    uint iTotalSites;

    //How many sites are currently open
    uint iOpenSites;

    //How many sites are currently open
    uint iN_sites;

    // stores open sites
    std::vector<bool> open_sites;

    // validates if row or column out of bounds
    void validate(int row, int col);        //[x]

    // translates position on 2D grid to an ID of a cell in a 1D vector
    int RowColToSiteID(int row, int col);   //[x]

    // Checks if neighbouring cells are open, connects the cell to neighbours
    int ConnectWithNeighbours(int row, int col);   

};