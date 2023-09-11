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

  //Creates an instance of Percolation class (grid nxn)
  //Percolation       Grid(n); 

  //Creates an instance of Percolation Stats class (grid nxn)
  PercolationStats  Perc_Stats(n, trials);

  double meanthreshold;

  for(int i=0; i<trials; i++)
  {
    //Creates an instance of Percolation class (grid nxn)
    Percolation       Grid(n); 

    std::cout<<"Trial: "<<i<<std::endl;
    meanthreshold+=Perc_Stats.ComputeThreshold(Grid);

  }

  meanthreshold = meanthreshold/(double)(trials);

  std::cout<<"Percolation mean threshold is: "<<meanthreshold<<std::endl;

  return 0;
}
