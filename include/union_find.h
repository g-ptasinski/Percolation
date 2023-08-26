#pragma once

#include <vector>

class Union_Find {

    typedef unsigned int uint;

public:

    // Creates two vectors (parent and size), containing IDs of objects, and sizes of subsets respectively
    Union_Find(uint n);            //[x]

    bool connected(uint p, uint q);
    void join(uint p, uint q);

private: 

    std::vector<uint> parent, set_size;

    uint root(uint i);

};