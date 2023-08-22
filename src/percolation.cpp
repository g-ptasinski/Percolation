#include "../include/percolation.h"
#include<iostream>

Percolation::Percolation(uint n)
{

 
  iSize       = n;
  iOpenSites  = 0;

  open_sites.resize(n, 0);
}

void Percolation::open(uint row, uint col)
{
  validate(row, col);

}

bool Percolation::isOpen(int row, int col)
{
  validate(row, col);

}



void Percolation::validate(int row, int col)
{
  if ( (row < 1 || row > iSize) || (col < 1 || col > iSize) ) 
  {
    std::cerr << "\n Row/Col out of bounds " << std::endl;

    exit(EXIT_FAILURE);
  }
}

void Percolation::Test( void )
{
  std::cout<<open_sites.size()<<std::endl;
}