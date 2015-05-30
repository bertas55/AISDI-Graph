#include "Graph.h"
#include "Node.h"
#include <vector>
#include <stack>
#include <iostream>
using namespace std;


void Graph::addNode(double xCoordinate, double yCoordinate)
{
    Node tmpNode(xCoordinate, yCoordinate);
    vec.push_back(tmpNode);
    //213
}

bool Graph::DFSFindCycle(Graph *g, int sought)
{
	stack<Node> s;

	for(vector<Node>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		iter->visited = false;
	}
	
 
	s.push(sought); //Wrzucamy startujący wierzchołek na stos
 
	while(!s.empty())
	{
		sought = s.top();
		s.pop();//Usuwamy odwiedzany element
 
		printf("\nOdwiedzam: %d\n",sought);
 
		vec[sought].visited = true;
 
		for(int j = n-1; j >= 0;--j)
		{
			if(G[j][szukany] != 0 && V[j] == false)
			{
				stos.push(j);//Wrzucamy na stos jego sąsiadów
				V[j] = true;//Znaznaczamy ,że go odwiedzimy!(w niedalekiej przyszłości)
//Inaczej będziemy mieli np taką sytuację w stosie 2,3,4,2 <-- 2x dwójka
			}
		}
	}
}