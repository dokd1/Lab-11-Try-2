#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Linkedlist.h"
#include<list>
using namespace std;
class Graph {

public:
    int numVertices;    //Represents the number of vertices in the graph
    List arr[5];

    //Constructor
    Graph(int v);

    //Destructor
    ~Graph();

    //Add the edge (i,j) to E
    void addEdge(int, int);

    //Remove the edge (i,j) from E.
    void removeEdge(int, int);

    //Check if the edge (i,j) ∈ E.
    bool hasEdge(int, int);

    //Return a list of all integers j such that edge (i,j) ∈ E.
    void outEdges(int);

    //Return a list of all integers j such that edge (j,i) ∈ E.
    void inEdges(int);

    //searches all the nodes in a depth first manner
    void depthFirstSearch(int);    //NEEDS TO BE WORKED ON

    //searches all the nodes in a breadth first manner.
    void breadthFirstSearch();  //NEEDS TO BE WORKED ON

};

Graph::Graph(int numVertices) {             //Constructor
    this->numVertices = numVertices;
}
Graph::~Graph() {                               //Destructor

}

void Graph::addEdge(int x, int y) {
    arr[x].insertNode(y);
}

void Graph::removeEdge(int x, int y) {
    arr[x].deleteNode(y);
}

bool Graph::hasEdge(int x, int y) {
    return arr[x].findNode(y);
}
void Graph::outEdges(int x)
{
        cout << x << "->";
        ListNode* head = arr[x].gethead();
        while (head != nullptr)
        {
            cout << head->value << " ";
            head = head->next;
        }
        cout << endl;
}
void Graph::inEdges(int x)
{ 
    List inedges;
    for (int i = 0; i < numVertices; i++)
    {
        if (arr[i].findNode(x)) inedges.insertNode(i);
    }
    ListNode* temp = inedges.gethead();
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
void Graph::breadthFirstSearch() {

}










#endif // GRAPH_H