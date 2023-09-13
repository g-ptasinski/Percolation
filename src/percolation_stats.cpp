#include "../include/percolation_stats.h"

#include<iostream>
#include <random> //import random module
#include <math.h>

//pseudo random generator seed
std::mt19937 generator(std::random_device{}());

PercolationStats::PercolationStats(uint n, uint trials) : trials(trials)
{
  
}

void PercolationStats::union_find(uint ID1, uint ID2)
{
  std::cout<<"test"<<std::endl;
}

void PercolationStats::computeMean()
{
  mean = Percolation_Threshold/trials;
}

double PercolationStats::getMean()
{
  return mean;
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

  double threshold = (double)iOpenSites/(double)(size*size);

  Percolation_Threshold += (double)threshold;

  return threshold;
}

double PercolationStats::getStddev()
{

}

