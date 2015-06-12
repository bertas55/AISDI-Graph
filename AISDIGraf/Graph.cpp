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


void Graph::DFSFindCycles()
{
	vector<int> visited;
	Node actualNode;

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			vec[j].vertexState = white;
		}
		vec[i].vertexState = black;
		visited.push_back(i);
		actualNode = vec[i];
		for (int j = 0; j < actualNode.edge.size(); j++)
		{
			DFSFindCycle(vec[i].edge[j].first, visited);
		}	
	}
}

void Graph::DFSFindCycle(int index, vector <int> &visited)
{
	int actualIndex;
	Node actualNode;
	visited.push_back(index);
	actualNode = vec[index];
	vec[index].vertexState = gray;

	for (int i = 0; i < actualNode.edge.size(); i++)
	{
		actualIndex = vec[index].edge[i].first;

		if(vec[actualIndex].vertexState == white)
		{
			DFSFindCycle(actualIndex, visited);
		}
		else if(vec[actualIndex].vertexState == black)
		{
			PrintCycle(visited);
		}
		
	}

}

void Graph::PrintCycle(vector<int> &visited)
{
	for (int i = 0; i < visited.size(); i++)
	{
		cout << visited[i] << " ";
	}

	cout << endl;
	visited.clear();
}


