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
}

void Graph::DFSFindCycles()
{
	double pathWeight;
	vector<int> visited;
	vector <vector<int> > cycles;
	Node actualNode;

	for (int i = 0; i < vec.size(); i++)
	{
		actualNode = vec[i];

		for (int j = 0; j < actualNode.edge.size(); j++)
		{
			ClearStates();
			visited.clear();
			vec[i].vertexState = black;
			visited.push_back(i);
			pathWeight = actualNode.edge[j].second;
			DFSFindCycle(actualNode.edge[j].first, visited, cycles, pathWeight);
		}	
	}
}

void Graph::DFSFindCycle(int index, vector <int> &visited, vector<vector<int> > &cycles, double pathWeight)
{
	int actualIndex, tmpInt;
	Node actualNode;
	bool onlyGray;

	visited.push_back(index);
	actualNode = vec[index];
	vec[index].vertexState = gray;

	for (int i = 0; i < actualNode.edge.size(); i++)
	{
		actualIndex = actualNode.edge[i].first;

		if(vec[actualIndex].vertexState == black)
		{
			visited.push_back(actualIndex);
			pathWeight += actualNode.edge[i].second;
			tmpInt = CheckIfCycleExist(visited, cycles);



			if(tmpInt == -1 && visited.size() % 2)
			{

				PrintCycle(cycles.back());
				cout << pathWeight << endl;;
			}
			visited.pop_back();
			pathWeight -= actualNode.edge[i].second; 
		}
		else if(vec[actualIndex].vertexState == white)
		{
			pathWeight += actualNode.edge[i].second;
			DFSFindCycle(actualIndex, visited, cycles, pathWeight);
			vec[actualIndex].vertexState = white;
			visited.pop_back();
			pathWeight -= actualNode.edge[i].second;
		}

	}
}

void Graph::ClearStates()
{
	for (int j = 0; j < vec.size(); j++)
	{
		vec[j].vertexState = white;
	}
}

void Graph::PrintCycle(vector<int> &visited)
{
	for(int i = 0; i < visited.size(); i++)
	{
		cout << visited[i] << " ";
	}
}

int Graph::CheckIfCycleExist(vector<int> &visited, vector<vector<int> > &cycles)
{
	bool exist = true, quit = false;
	int indexNewCycle, indexOldCycle, sizeNewCycle, sizeOldCycle;

	sizeNewCycle = visited.size() - 1;

	for(int i = 0; i < cycles.size(); i++)
	{
		sizeOldCycle = cycles[i].size() - 1;
		exist = true;

		if(sizeOldCycle == sizeNewCycle)
		{
			indexNewCycle = 0;
			indexOldCycle = 0;
			while(indexOldCycle < sizeOldCycle && visited[0] != cycles[i][indexOldCycle])
			{
				indexOldCycle++;
			}
			if(indexOldCycle >= sizeOldCycle)
			{
				exist = false;
			}
			for(; indexNewCycle < sizeNewCycle && indexOldCycle < sizeOldCycle; indexNewCycle++, indexOldCycle++)
			{
				if(visited[indexNewCycle] != cycles[i][indexOldCycle % sizeOldCycle])
				{
					exist = false;
				}
			}

			if(exist)
			{
				return i;
			}
		}
	}
	
	cycles.push_back(visited);
	return -1;
}

