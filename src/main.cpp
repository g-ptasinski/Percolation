#include "../include/percolation.h"
#include "../include/percolation_stats.h"
#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
  unsigned int n{ 1000 }; 
  unsigned int trials{ 50 };
  
  if (argc == 3) 
  {
    n      = std::stoi(argv[1]);
    trials = std::stoi(argv[2]);
  }

  //Creates an instance of Percolation class (grid nxn)
  Percolation       Grid(n); 

  //Creates an instance of Percolation Stats class (grid nxn)
  PercolationStats  perc(n, trials);

  Grid.Test();

  return 0;
}
