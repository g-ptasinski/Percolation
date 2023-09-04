#include "../include/percolation_stats.h"

#include<iostream>

#include <stdlib.h>     
#include <time.h>       
#include <math.h>

PercolationStats::PercolationStats(uint n, uint trials)
{
  srand (time(NULL));
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
  uint p,q;
  uint iOpenSites;
  uint size = percolation.getSize();

  while(!percolation.percolates())
  {
    q = rand()%size;
    p = rand()%size;

    percolation.open(p,q);
    iOpenSites = percolation.numberOfOpenSites();

  }
}