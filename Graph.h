#ifndef __AISDIGraf__Graph__
#define __AISDIGraf__Graph__

#include <iostream>
#include <vector>
#include <stack>
#include "Node.h"
using namespace std;

class Graph
{
public:
    void addNode(double, double);
    
    Node & operator[](size_t el)
    {
        return vec[el];
    }
    
    const Node & operator[](size_t el) const
    {
        return vec[el];
    }
    
    void DFSFindCycle(int, vector<int>&, vector<vector<int> >&, double);
    void DFSFindCycles();
    int CheckIfCycleExist(vector<int>&, vector<vector<int> >&);
    void ClearStates();
    void PrintCycle(vector<int>&);

    vector <Node> vec;
};


#endif
