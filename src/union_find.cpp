#include "../include/union_find.h"
#include <iostream>

typedef unsigned int uint;

Union_Find::Union_Find(uint n) 
{

  parent.reserve(n);      //Set size of parent vector to n
  set_size.assign(n, 1);  //Initially every set contains just one element.

  for(uint i = 1; i<n ; i++)
  {
    parent.push_back(i);
  }

  std::cout<< "Union find Created" <<std::endl;
}

uint Union_Find::root(uint i) 
{
  while(i != parent[i])
  {
    //Traces the subset back to the root node of element i
    i = parent[i];  
  }

  return i;
}

void Union_Find::join(uint p, uint q) 
{
  uint root_p = root(p);
  uint root_q = root(q);

  //Check if elements are in the same subset
  //if so, return
  if( root_p == root_q ) return;

  if( set_size[p] < set_size[q] )
  {
    parent[root_p] = root_q ;

    set_size[p]+=set_size[q];
  }
  else
  {
    parent[root_q] = root_p ;
    
    set_size[q]+=set_size[p];
  }
}

bool Union_Find::connected(uint p, uint q) 
{
  std::cout<< p <<std::endl; 
  std::cout<< q <<std::endl;
  return root(p)==root(q);
}