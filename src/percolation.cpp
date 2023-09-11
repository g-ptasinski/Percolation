#include "../include/percolation.h"
#include "../include/union_find.h"
#include <iostream>

typedef unsigned int uint;

Percolation::Percolation(uint n) 
          : iSize(n), iOpenSites(0), iTotalSites(n*n + 2), uf_algorithm(n*n + 2)
{
  //Resizes a vector to size N^2+2 (1d representation of grid)
  open_sites.resize(iTotalSites, false);

  //Start point (artificially added on top, above first row)
  open_sites.at(0) = true;   
  
  //Endpoint (added on bottom, below last row)
  open_sites.at(iTotalSites-1) = true; 

}

void Percolation::open(uint row, uint col)
{
  validate(row, col);

  if( !isOpen(row, col) )
  {
    ConnectWithNeighbours(row, col);
    open_sites.at(RowColToSiteID(row, col)) = true;
    
    iOpenSites++;
  }
}

bool Percolation::isOpen(int row, int col)
{
  validate(row, col);

  return(open_sites.at(RowColToSiteID(row, col)));
}

int Percolation::RowColToSiteID(int row, int col)
{
  return(( row - 1 )*iSize + ( col - 1 ) + 1);
}

void Percolation::validate(int row, int col)
{
  if ( (row < 1 || row > iSize) || (col < 1 || col > iSize) ) 
  {
    std::cerr << "\n Row/Col out of bounds " << std::endl;

    exit(EXIT_FAILURE);
  }
}

uint Percolation::numberOfOpenSites()
{
  return iOpenSites;
}

bool Percolation::percolates()
{
  return uf_algorithm.connected(0, iTotalSites-1);
}

uint Percolation::getSize( void )
{
  return iSize;
}

void Percolation::printGrid( void )
{
  for(int x=1; x<=iSize ; x++)
  {
    for(int y=1 ; y<=iSize ; y++)
    {
      if(isOpen(x,y))
          std::cout<<"[ ]";
        else
          std::cout<<"[X]";
    }
    std::cout << std::endl;
  }
}

void Percolation::ConnectWithNeighbours(int row, int col)
{
  uint SiteID = RowColToSiteID(row, col);


  //Not in 1st or last column or 1st or last row. Cell in the middle, neighbours on all sides
  if(row!=1 && row!=iSize && col!=1 && col!=iSize)
  {
    if(isOpen(row + 1, col))
    {
      uf_algorithm.join(SiteID, RowColToSiteID(row + 1, col));
    }
    if(isOpen(row - 1, col))
    {
      uf_algorithm.join(SiteID, RowColToSiteID(row - 1, col));
    }
    if(isOpen(row , col + 1))
    {
      uf_algorithm.join(SiteID, RowColToSiteID(row , col + 1));
    }
    if(isOpen(row , col - 1))
    {
      uf_algorithm.join(SiteID, RowColToSiteID(row , col - 1));
    }
  }
  else if(row == 1) //TOP
  {

    uf_algorithm.join(SiteID, 0);

    if(isOpen(row + 1, col))
    {
      uf_algorithm.join(SiteID, RowColToSiteID(row + 1, col));
    }
    if(col != iSize)
    {  
      if(isOpen(row , col + 1))
      {
        uf_algorithm.join(SiteID, RowColToSiteID(row , col + 1));
      }
    }
    if(col != 1)
    {  
      if(isOpen(row , col - 1))
      {
        uf_algorithm.join(SiteID, RowColToSiteID(row , col - 1));
      }
    }
  }
  else if (row == iSize) //BOTTOm
  {
    uf_algorithm.join(SiteID, iTotalSites - 1);  

    if (isOpen(row - 1, col))
    {
      uf_algorithm.join(SiteID, RowColToSiteID(row - 1, col));
    }

    if (col != 1) 
    {
      // Left
      if (isOpen(row, col - 1))
      {
        uf_algorithm.join(SiteID, RowColToSiteID(row, col - 1));
      }
    }

    if (col != iSize) 
    {
      // Right
      if (isOpen(row, col + 1))
      {
        uf_algorithm.join(SiteID, RowColToSiteID(row, col + 1));
      }
    }
  }
  else 
  {
    // Top
    if (isOpen(row - 1, col))
    {
      uf_algorithm.join(SiteID, RowColToSiteID(row - 1, col));
    }

    // Bottom
    if (isOpen(row + 1, col))
    {
      uf_algorithm.join(SiteID, RowColToSiteID(row + 1, col));
    }

    if (col == iSize) 
    {
      // Left
      if (isOpen(row, col - 1))
      {
        uf_algorithm.join(SiteID, RowColToSiteID(row, col - 1));
      }
    }

    if (col == 1) 
    {
      // Right
      if (isOpen(row, col + 1))
      {
        uf_algorithm.join(SiteID, RowColToSiteID(row, col + 1));
      }
    }
  }
}