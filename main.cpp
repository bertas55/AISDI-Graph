#include <iostream>
#include "Graph.h"
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    string input;
    Graph g;
    size_t firstSpace;
    size_t lastSpace;
    string first, second, third;
    double x, y, weight;
    int index1, index2;
    bool quit;
    
    while(getline(cin, input) && !input.empty())
    {

        firstSpace = input.find(' ');
        lastSpace = input.rfind(' ');
        
        if (firstSpace == lastSpace && !input.empty())    // jesli pierwsza i ostatnia spacja sa na tej samej pozycji
        {
            first = input.substr(0, firstSpace);
            second = input.substr(firstSpace + 1, input.back());
            
            x = stod(first);
            y = stod(second);
            
            g.addNode(x, y);
        }
        else
        {
            first = input.substr(0, firstSpace);
            second = input.substr(firstSpace + 1, lastSpace - firstSpace - 1);
            third = input.substr(lastSpace + 1, input.back() - lastSpace - 1);
            
            index1 = stoi(first);
            index2 = stoi(second);
            weight = stod(third);

            quit = false;
            for(int i = 0; i < g[index1].edge.size(); i++)
            {
                if(g[index1].edge[i].first == index2)
                {
                    g[index1].edge[i].second = weight;
                    quit = true;
                }
            }
            
            if(!quit)
            {
                g[index1].edge.push_back(make_pair(index2, weight));
            }
            
            
        }
        
    }

    g.DFSFindCycles();
    
    return 0;
}
