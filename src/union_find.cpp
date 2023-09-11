#include "../include/union_find.h"
#include <iostream>

typedef unsigned int uint;

Union_Find::Union_Find(uint n) 
{

  parent.reserve(n);      //Set size of parent vector to n

  for(auto i = 0; i < n ; ++i)
  {
    parent.push_back(i);
  }

  set_size.assign(n, 1);  //Initially every set contains just one element.
}

uint Union_Find::root(uint i) 
{
  while(i != parent.at(i))
  {
    //Traces the subset back to the root node of element i
    i = parent.at(i);      
    //std::cout<<parent.at(i)<<std::endl;
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

  if( set_size.at(p) < set_size.at(q) )
  {
    parent.at(root_p) = root_q ;

    set_size.at(p) += set_size.at(q);
  }
  else
  {
    parent.at(root_q) = root_p ;
    
    set_size.at(q) += set_size.at(p);
  }

  //std::cout<<p<<" joined with "<<q<<std::endl;
}

bool Union_Find::connected(uint p, uint q)
{
  return root(p) == root(q);
}