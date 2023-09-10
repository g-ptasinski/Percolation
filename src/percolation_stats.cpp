#include "../include/percolation_stats.h"

#include<iostream>
#include <random> //import random module
#include <math.h>

//pseudo random generator seed
std::mt19937 generator(std::random_device{}());

PercolationStats::PercolationStats(uint n, uint trials)
{

}

void PercolationStats::union_find(uint ID1, uint ID2)
{
  std::cout<<"test"<<std::endl;
}

double PercolationStats::mean()
{
  std::cout<<"test"<<std::endl;
}

double PercolationStats::ComputeThreshold(Percolation& percolation)
{
  uint row, col;
  uint iOpenSites;
  uint size = percolation.getSize();

  std::uniform_int_distribution<int> distribution( 1, size );

  while( !percolation.percolates() )
  {
    col = distribution(generator);
    row = distribution(generator);
    
    percolation.open(row,col);
    iOpenSites = percolation.numberOfOpenSites();

    //percolation.printGrid();
  }

  /*std::cout<<iOpenSites<<std::endl;
  std::cout<<(size*size)<<std::endl;
  std::cout<<mean<<std::endl;*/

  double mean = (double)iOpenSites/(double)(size*size);
  
  return mean;
}