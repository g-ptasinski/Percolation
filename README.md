# Percolation

This is the C++ implementation of Percolation problem, from Coursera [Algorithms 1](https://www.coursera.org/learn/algorithms-part1/home) course. Below, one can find a summary of the problem from the theoretical point of view.

## Percolation

Given a composite systems comprised of randomly distributed insulating and metallic materials: what fraction of
the materials need to be metallic so that the composite system is an electrical conductor? Given a porous landscape with water on
the surface (or oil below), under what conditions will the water be able to drain through to the bottom (or the oil to gush through
to the surface)? Scientists have defined an abstract process known as percolation to model such situations.

## The model

We model a percolation system using an N-by-N grid of sites. Each site is either open or blocked. A full site is an
open site that can be connected to an open site in the top row via a chain of neighboring (left, right, up, down) open sites. We say
the system percolates if there is a full site in the bottom row. In other words, a system percolates if we fill all open sites connected
to the top row and that process fills some open site on the bottom row. (For the insulating/metallic materials example, the open
sites correspond to metallic materials, so that a system that percolates has a metallic path from top to bottom, with full sites
conducting. For the porous substance example, the open sites correspond to empty space through which water might flow, so that
a system that percolates lets water fill open sites, flowing from top to bottom.

The full description of the problem can be found on the [Princeton website](https://coursera.cs.princeton.edu/algs4/assignments/percolation/specification.php).

All of the code has been done using C++, and is compiled with make. The default simulation does a 1000 simulations of 5x5 lattice, calculates and displays all of the statistical values required:
* Average percolation threshhold 
* Standard deviation
* The 95% confidence interval boundary values

To change the default values for lattice size and trials number one should run main.exe or ./main with appropriate commandline arguments:

'main.exe {lattice side size} {number of trials}

For example

'main.exe 10 50'

Will perform 50 simulations of a 10x10 lattice. 

### Todo

- [X] The core functionality, union find, stats
- [ ] GUI
- [ ] Migration to C++17 



