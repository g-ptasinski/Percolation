#include "../include/percolation_stats.h"

#include<iostream>
#include <random> //import random module
#include <math.h>

// get 'entropy' from device that generates random numbers itself
// to seed a mersenne twister (pseudo) random generator
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
  uint p,q;
  uint iOpenSites;
  uint size = percolation.getSize();

  std::uniform_int_distribution<int> distribution(0,size);

  while(!percolation.percolates())
  {

    q = distribution(generator);
    p = distribution(generator);

    std::cout<<q <<" | "<< p << std::endl;

    percolation.open(p,q);

    iOpenSites = percolation.numberOfOpenSites();

  }

  std::cout<<iOpenSites<<std::endl;
}