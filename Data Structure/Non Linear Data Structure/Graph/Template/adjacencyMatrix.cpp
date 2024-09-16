#include <bits/stdc++.h>
using namespace std;
#define MaxNUM 100

struct Graph {
    int Matrix[MaxNUM][MaxNUM];
    int numNode;

    Graph(int n) {
        numNode = n;
        for (int i = 0; i < MaxNUM; ++i) {
            for (int j = 0; j < MaxNUM; ++j) {
                Matrix[i][j] = 0;
            }
        }
    }

    void addNode() {
        if (numNode < MaxNUM) {
            numNode++;
        } else {
            cout << "Maximum number of nodes reached.\n";
        }
    }

    void removeNode(int node) {
        if (node >= numNode) {
            cout << "\nVertex not present!\n";
            return;
        }
        
        for (int i = 0; i < numNode; ++i) {
            for (int j = node; j < numNode - 1; ++j) {
                Matrix[i][j] = Matrix[i][j + 1];
            }
        }
        for (int i = node; i < numNode - 1; ++i) {
            for (int j = 0; j < numNode; ++j) {
                Matrix[i][j] = Matrix[i + 1][j];
            }
        }
        numNode--;
    }

    void addEdge(int src, int des, int weight = 1) {
        if (src < numNode && des < numNode) {
            Matrix[src][des] = weight;
            Matrix[des][src] = weight;
        } else {
            cout << "Edge cannot be added.\n";
        }
    }

    void removeEdge(int src, int des) {
        if (src < numNode && des < numNode) {
            Matrix[src][des] = 0;
            Matrix[des][src] = 0;
        } else {
            cout << "Edge doesn't exist.\n";
        }
    }

    bool hasNode(int node) {
        return node < numNode;
    }

    bool hasEdge(int src, int des) {
        if (src < numNode && des < numNode) {
            return Matrix[src][des] != 0;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < numNode; ++i) {
            for (int j = 0; j < numNode; ++j) {
                cout << setw(3) << Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }




};

int main() {
   Graph graph(3);
    cout << "Initial graph:" << endl;
    graph.display();

    cout << "\nAdding edge from 0 to 1" << endl;
    graph.addEdge(0, 1);
    graph.display();

    cout << "\nAdding edge from 1 to 2" << endl;
    graph.addEdge(1, 2);
    graph.display();

    cout << "\nAdding a new node" << endl;
    graph.addNode();
    graph.display();

    cout << "\nAdding edge from 3 to 0" << endl;
    graph.addEdge(3, 0);
    graph.display();

    cout << "\nChecking if edge exists between 1 and 2" << endl;
    if (graph.hasEdge(1, 2)) {
        cout << "Edge between 1 and 2 exists.\n";
    } else {
        cout << "Edge between 1 and 2 does not exist.\n";
    }

    cout << "\nChecking if node 2 exists" << endl;
    if (graph.hasNode(2)) {
        cout << "Node 2 exists.\n";
    } else {
        cout << "Node 2 does not exist.\n";
    }

    cout << "\nRemoving edge from 1 to 2" << endl;
    graph.removeEdge(1, 2);
    graph.display();

    cout << "\nChecking if edge exists between 1 and 2 after removal" << endl;
    if (graph.hasEdge(1, 2)) {
        cout << "Edge between 1 and 2 exists.\n";
    } else {
        cout << "Edge between 1 and 2 does not exist.\n";
    }

    cout << "\nRemoving node 1" << endl;
    graph.removeNode(1);
    graph.display();

    cout << "\nChecking if node 1 exists after removal" << endl;
    if (graph.hasNode(1)) {
        cout << "Node 1 exists.\n";
    } else {
        cout << "Node 1 does not exist.\n";
    }


    

    return 0;
}