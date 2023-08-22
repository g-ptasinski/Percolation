#include "../include/percolation.h"
#include "../include/percolation_stats.h"
#include<iostream>
#include <string>


int main(int argc, char *argv[])
{
  unsigned int n{ 1000 }; 
  unsigned int trials{ 50 };

  PercolationStats perc;
  



  if (argc == 3) 
  {
    n      = std::stoi(argv[1]);
    trials = std::stoi(argv[2]);
  }

  Percolation Grid(n);
  Grid.Test();
  //std::cout<<n << " " << trials <<std::endl;


  return 0;
}
