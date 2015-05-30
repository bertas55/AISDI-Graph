#ifndef __AISDIGraf__Node__
#define __AISDIGraf__Node__

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node();
    Node(double, double);
    
    double x;
    double y;
    bool visited;
    
    vector <pair<int, double> > edge;
};

#endif
