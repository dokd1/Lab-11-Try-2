#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph gh(5); //The number inside represents the number of vertices in the graph
    int choice;
    int userX;
    int userY;
    int odg;
    int idg;

    do {
        cout << "Press 1 to add an edge to graph" << endl;
        cout << "Press 2 to remove an edge from graph" << endl;
        cout << "Press 3 Find an edge in the graph" << endl;
        cout << "Press 4 Find the out edges of a vertices" << endl;
        cout << "Press 5 Find the in edges of a vertices" << endl;
        cout << "Press 6 to depth first search" << endl;
        cout << "Press 7 to breadth first search" << endl;
        cout << "Press 8 to exit" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Add Edge" << endl;
            cout << "--------" << endl;
            cout << "Enter x: ";
            cin >> userX;
            cout << "Enter y: ";
            cin >> userY;
            gh.addEdge(userX, userY);
            cout << "Edge (" << userX << ", " << userY << ") has been added." << endl;
            cout << endl;
        }
        else if (choice == 2) {
            cout << "Remove Edge" << endl;
            cout << "-----------" << endl;
            cout << "Enter x: ";
            cin >> userX;
            cout << "Enter y: ";
            cin >> userY;
            if (gh.hasEdge(userX, userY)) {
                gh.removeEdge(userX, userY);
                cout << "Edge (" << userX << ", " << userY << ") has been removed." << endl;
            }
            else {
                cout << "Edge (" << userX << ", " << userY << ") does not exist." << endl;
            }
            cout << endl;
        }
        else if (choice == 3) {
            cout << "Find Edge" << endl;
            cout << "---------" << endl;
            cout << "Enter x: ";
            cin >> userX;
            cout << "Enter y: ";
            cin >> userY;

            if (gh.hasEdge(userX, userY)) {
                cout << "Edge (" << userX << ", " << userY << ") has been found." << endl;
                cout << endl;
            }
            else {
                cout << "EDGE WAS NOT FOUND" << endl;
                cout << endl;
            }

        }
        else if (choice == 4) {
            cout << "Enter an integer for out edge (->out edge, in edge): ";
            cin >> odg;
            gh.outEdges(odg);

        }
        else if (choice == 5) {
            cout << "Enter an integer for in edge (out edge, in edge): ";
            cin >> idg;
            cout << "Printing the list of integers of in edge..." << endl;
            gh.inEdges(idg);
        }
        else if (choice == 6) {
            cout << "Searching nodes with Depth First Search..." << endl;



        }
        else if (choice == 7) {
            cout << "Searching nodes with Breadth First Search..." << endl;

        }
        else if (choice == 8) {
            cout << "Goodbye." << endl;
        }
        else if (choice >= 9 || choice <= 0) {
            cout << "INVALID CHOICE PLEASE TRY AGAIN" << endl;
            cout << endl;
            choice = 1;
        }
    } while (choice < 8);

    return 0;
}