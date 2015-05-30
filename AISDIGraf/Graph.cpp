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
/*

bool DFSfindCycle(slistEl ** graf, int v, int w, stack & S, bool * visited)
{
    int u;
    slistEl * p;
    
    visited[w] = true;             // Oznaczamy wierzchołek jako odwiedzony
    p = graf[w];                   // Rozpoczynamy przeglądanie sąsiadów
    while(p)
    {
        u = p->v;                    // u - numer wierzchołka będącego sąsiadem
        if(u != S.top())             // Pomijamy wierzchołek, z którego przyszliśmy
        {
            S.push(w);                 // Na stos wierzchołek bieżący
            if(u == v) return true;    // Cykl znaleziony, kończymy
            if(!visited[u] && DFSfindCycle(graf,v,u,S,visited)) return true;
            S.pop();
        }
        p = p->next;
    }
    return false;
}


K01:	visited[w] ← true	; oznaczamy bieżący wierzchołek jako odwiedzony
K02:	Dla każdego sąsiada u wierzchołka w wykonuj K03...K07	; przeglądamy kolejnych sąsiadów wierzchołka w
K03:	    Jeśli u = S.top(), to następny obieg pętli K02	; sąsiad jest wierzchołkiem, z którego przyszliśmy
K04:	    S.push(w)	; wierzchołek w umieszczamy na stosie
K05:	    Jeśli u = v, to zakończ	; znaleźliśmy cykl, kończymy rekurencję
K06:	    Jeśli (visited[u] = false)   (DFSfindCycle(graf,v,u,S,visited) = true),
to zakończ z wynikiem true	; rekurencyjnie odwiedzamy nieodwiedzonych sąsiadów
K07:	    S.pop()	; usuwamy ze stosu wierzchołek bieżący
K08:	Zakończ z wynikiem false

 */
 
bool Graph::DFSFindCycle(Graph g, int v, int w, stack <Node> s)
{
    int u;
    Graph *elem;
    
    g[w].visited = true;
    elem = g[w];
    
    while (elem)
    {
        u = elem->v;
        if(u != s.top())
        {
            s.push(w);
            if(u == v)
            {
                return true;
            }
            if(g[u].visited && DFSFindCycle(g, v, u, s))
            {
                return true;
            }
            s.pop();
        }
        elem = elem->next;
    }
    
}