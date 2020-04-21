#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <iterator>
#include <Linkedlist.h>
#include <bits/stdc++.h>
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
    void DFS(bool visited[],int v);
    int depthFirstSearch();    //NEEDS TO BE WORKED ON

    //searches all the nodes in a breadth first manner.
    void breadthFirstSearch(int);  //NEEDS TO BE WORKED ON

};

int counter = 0;

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

void Graph::inEdges(int y)
{
    List inedges;
    for (int i = 0; i < numVertices; i++)
    {
        if (arr[i].findNode(y)) inedges.insertNode(i);
    }
    ListNode* temp = inedges.gethead();
    cout << y << "->";
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Graph::breadthFirstSearch(int v) {
    // Mark all the vertices as not visited
    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[v] = true;
    queue.push_back(v);

    // 'i' will be used to get all adjacent
    // vertices of a vertex

    ListNode* head = arr[v].gethead();

    while(!queue.empty()) {
        // Dequeue a vertex from queue and print it
        v = queue.front();
        cout << v << " ";
        queue.pop_front();
        while (head != nullptr) {
            if (!visited[head->value]) { //if adjacent vertex hasn't been visited
                DFS(visited, head->value); //start a new search with that vertex
            }
            head = head->next;
        }
    }

}

void Graph::DFS(bool visited[],int v) {
    //Mark vertex as visited and print it
    visited[v] = true;
    cout << v << " ";

    //Traverse the linked list contained at vertexArr[i] (i.e. get all adjacent vertices via recursion)
    ListNode* head = arr[v].gethead();
    while (head != nullptr) {
        if (!visited[head->value]) { //if adjacent vertex hasn't been visited
            DFS(visited, head->value); //start a new search with that vertex
        }
        head = head->next;
    }
}

int Graph::depthFirstSearch() {
    // Mark all the vertices as not visited
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    for (int i = 0; i < numVertices; i++) {
        counter++;
        if (visited[i] == false) {
            DFS(visited, i);
        }
    }
    return counter;

}
