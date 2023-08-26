#include "../include/percolation.h"
#include "../include/union_find.h"
#include <iostream>

typedef unsigned int uint;

Percolation::Percolation(uint n) 
          : iSize(n), iOpenSites(0)
{
  //Resizes a vector to size N^2+2 (1d representation of grid)
  open_sites.resize(n*n + 2, false);

  //Start point (artificially added on top, above first row)
  open_sites[0] = true;   
  
  //Endpoint (added on bottom, below last row)
  open_sites[n*n+1] = true; 

  Union_Find uf_algorithm(1);
}

void Percolation::open(uint row, uint col)
{
  validate(row, col);

  if( !isOpen(row, col) )
  {
    open_sites[RowColToSiteID(row, col)] = true;
    iOpenSites++;
  }
}

bool Percolation::isOpen(int row, int col)
{
  validate(row, col);

  return(open_sites[RowColToSiteID(row, col)]);
}

int Percolation::RowColToSiteID(int row, int col)
{
  return(( row - 1 )*iSize + ( col - 1 ) + 1);
}

void Percolation::validate(int row, int col)
{
  if ( (row < 1 || row > iSize) || (col < 1 || col > iSize) ) 
  {
    std::cerr << "\n Row/Col out of bounds " << std::endl;

    exit(EXIT_FAILURE);
  }
}

uint Percolation::numberOfOpenSites()
{
  return iOpenSites;
}

bool Percolation::percolates()
{
  return false;
}

void Percolation::Test( void )
{
  std::cout<<open_sites.size()<<std::endl;
}