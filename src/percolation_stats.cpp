#include "../include/percolation_stats.h"

#include<iostream>
#include <random> //import random module
#include <math.h>
#include <numeric>

//pseudo random generator seed
std::mt19937 generator(std::random_device{}());

PercolationStats::PercolationStats(uint n, uint trials) : trials(trials)
{
  Percolation_Thresholds.reserve(trials);
}

void PercolationStats::computeMean()
{
  mean = std::accumulate(Percolation_Thresholds.begin(), Percolation_Thresholds.end(), 0.0) / Percolation_Thresholds.size();
}

void PercolationStats::computeStddev()
{
  double SquaresSum = 0.0;

  for (int i = 0; i < Percolation_Thresholds.size() ; i++)
  {
    SquaresSum += pow((Percolation_Thresholds.at(i) - mean), 2);
  }

  double variance = SquaresSum / ( trials - 1 );
  
  StdDev = sqrt(variance);
}

void PercolationStats::computeConfidenceLo()
{
  ConfidenceLo = mean - 1.96 * StdDev / sqrt(trials);
}


void PercolationStats::computeConfidenceHi()
{
  ConfidenceHi = mean + 1.96 * StdDev / sqrt(trials);
}


double PercolationStats::getMean()
{
  return mean;
}

double PercolationStats::getStddev()
{
  return StdDev;
}

double PercolationStats::getConfidenceLo()
{
  return ConfidenceLo;
}

double PercolationStats::getConfidenceHi()
{
  return ConfidenceHi;
}

void PercolationStats::ComputeThreshold(Percolation& percolation)
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

  Percolation_Thresholds.push_back(threshold);
}



