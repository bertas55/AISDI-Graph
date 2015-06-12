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

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			vec[j].visited = false;
		}
		DFSFindCycle(i);
/*

		if (DFSFindCycle(i) == true)
		{
			   t.push_back(i);
      while(!s.empty())            // Przerzucamy stos S do stosu T
      {
        t.push_back(s.back()); 
        s.pop_back();
      }

      while(!t.empty())            // Wyświetlamy ścieżkę
      {
        cout << t.back() << " "; 
        t.pop_back();
      }
      cout << endl;
		      }
	*/
		}


}
/*


K01:	Utwórz n-elementową tablicę visited	 
K02:	Utwórz pusty stos S	 
K03:	Dla i = 0,1,...,n-1: wykonuj K04...K09	 
K04:	    Ustaw wszystkie elementy visited na false	 
K05:	    Jeśli DFSfindCycle(graf,i,i,S,visited) = false, to następny obieg pętli K03	; szukamy cyklu, wynik będzie na stosie
K06:	    Pisz i	; wypisujemy wierzchołek startowy
K07:	    Dopóki S.empty() = false, wykonuj K08...K09	; wypisujemy wierzchołki tworzące cykl
K08:	        Pisz S.top()	; wypisujemy wierzchołek
K09:	        S.pop()	; usuwamy go ze stosu
K10:	Zakończ

*/
/*
bool Graph::DFSFindCycle(int v, int w)
{
	int u;
	vec[w].visited = true;
	s.push_back(w);
	Node p = vec[w];
	

	for (int i = 0; i < p.edge.size(); i++)
	{

		u = p.edge[i].first;
		if (u== v)
		{
			return true;
		}

		if (!vec[u].visited && DFSFindCycle(v, u))
		{
			return true;
		}
		s.pop_back();

		return false;
	}

}

*/
void Graph::DFSFindCycle(int index)
{
	vector<int> s;
	vec[index].visited = true;

	s.push_back(index);
	cout << "==================================" << endl;

	while(!s.empty())
	{
		int act = s.back();	//indeks

//cout << "ACT = " << act << endl;

		s.pop_back();

		//printf("%d ",act);

		vec[index].visited = true;

		for (int i = 0; i < vec[act].edge.size(); i++)
		{
			cout << "VECTOR \n";
			for (int j = 0; j < s.size(); j++)
			{
				cout << s[j] << " ";
			}
			cout << endl;

			if (vec[act].edge[i].first == index)
			{
				cout << vec[act].edge[i].first << " TAK" << endl;
				//break;

				vec[index].visited = false;
				//i = i - 2;
				//s.pop();
				//continue;

			}

			if (vec[vec[act].edge[i].first].visited == false)
			{
				s.push_back(vec[act].edge[i].first);
				vec[vec[act].edge[i].first].visited = true;
			}
		}
	}

	printf("\n");

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].visited = false;
	}

		cout << "==================================END" << endl;
}



