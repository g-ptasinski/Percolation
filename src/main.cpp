#include "../include/percolation.h"
#include "../include/percolation_stats.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


int main(int argc, char *argv[])
{
  unsigned int n{ 10 }; 
  unsigned int trials{ 100 };
  
  if (argc == 3) 
  {
    n      = std::stoi(argv[1]);
    trials = std::stoi(argv[2]);
  }

  sf::Window window(sf::VideoMode(800, 600), "Percolation", sf::Style::Default);

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
  Perc_Stats.computeConfidenceLo();
  Perc_Stats.computeConfidenceHi();

  std::cout<<"Analysis complete              "<<std::endl<<std::endl;
  std::cout<<"Trials done:                   "<< trials <<std::endl;
  std::cout<<"Grid size:                     "<< n << " x " << n <<std::endl;
  std::cout<<"Percolation mean threshold is: "<< Perc_Stats.getMean() <<std::endl;
  std::cout<<"StdDev is:                     "<< Perc_Stats.getStddev() <<std::endl;
  std::cout<<"High confidence interval is:   "<< Perc_Stats.getConfidenceHi() <<std::endl;
  std::cout<<"Low confidence interval is:    "<< Perc_Stats.getConfidenceLo() <<std::endl;


  while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

  return 0;
}
