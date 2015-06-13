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
	visited.push_back(index);
	actualNode = vec[index];
	vec[index].vertexState = gray;



	for (int i = 0; i < actualNode.edge.size(); i++)
	{
		actualIndex = actualNode.edge[i].first;

		if(vec[actualIndex].vertexState == black)
		{
			visited.push_back(actualIndex);
			tmpInt = CheckIfCycleExist(visited, cycles);
			if(tmpInt < 0)
			{
				pathWeight += actualNode.edge[i].second;
				PrintCycle(cycles.back());
				cout << pathWeight << endl;
			}
			return;
		}
		else if(vec[actualIndex].vertexState == white)
		{
			pathWeight += actualNode.edge[i].second;
			DFSFindCycle(actualIndex, visited, cycles, pathWeight);
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
	bool exact = true, quit = false;
	int j, k;

	if(cycles.empty())
	{
		cycles.push_back(visited);
	}
	else
	{
		for(int i = 0; i < cycles.size(); i++)
		{
			exact = true;
			quit = false;

			if(visited.size() == cycles[i].size())
			{
				j = 0;
				k = 0;

				while(j < visited.size() && k < visited.size() && visited[j] != cycles[i][k])
				{
					k++;
				}
				while(j < visited.size() && k < visited.size())
				{
					if(visited[j] != cycles[i][k])
					{
						exact = false;
						quit = true;
						break;
					}
					j++;
					k++;
				}


				if(k > j)
				{
					k = 0;
					j++;
				}
				else
				{
					j = 0;
					k++;
				}

				while(j < visited.size() && k < visited.size() && !quit)
				{
					if(visited[j] != cycles[i][k])
					{
						exact = false;
						quit = true;
						break;
					}
					j++;
					k++;
				}

				if (exact)
				{
					return i;
				}
				
			}
		}
		cycles.push_back(visited);
	}
	return -1;
}


