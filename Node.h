#ifndef __AISDIGraf__Node__
#define __AISDIGraf__Node__

#include <iostream>
#include <vector>
using namespace std;

typedef enum State 
{ 
	white = 0,
	gray = 1,
	black = 2 
} State;
    

class Node
{
public:
    Node();
    Node(double, double);
    
    double x;
    double y;

    State vertexState; 

    vector <pair<int, double> > edge;
};

#endif
