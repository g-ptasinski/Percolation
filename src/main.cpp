#include "../include/percolation.h"
#include "../include/percolation_stats.h"
#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
  unsigned int n{ 10 }; 
  unsigned int trials{ 100 };
  
  if (argc == 3) 
  {
    n      = std::stoi(argv[1]);
    trials = std::stoi(argv[2]);
  }

  //Creates an instance of Percolation Stats class (grid nxn)
  PercolationStats  Perc_Stats(n, trials);

  for(int i=0; i<trials; i++)
  {
    //Creates an instance of Percolation class (grid nxn)
    Percolation       Grid(n); 
    Perc_Stats.ComputeThreshold(Grid);
  }

  Perc_Stats.computeMean();
  Perc_Stats.computeStddev();

  std::cout<<"Percolation mean threshold is: "<< Perc_Stats.getMean() <<std::endl;
  std::cout<<"StdDev is: "<< Perc_Stats.getStddev() <<std::endl;

  return 0;
}
