
#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;                        // Number of vertices
    int AdjM[10][10] = {0};       // 2D array for adjacency matrix (assuming max 10 vertices)

    // Constructor
    Graph(int x) {
        V = x;
        // Initialize the adjacency matrix to 0
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                AdjM[i][j] = 0;
            }
        }
    }

    // Add an edge (for undirected graph)
    void addEdge(int i, int j) {
        AdjM[i][j] = 1;
        AdjM[j][i] = 1; // For undirected graph
    }

    // Remove an edge
    void removeEdge(int i, int j) {
        AdjM[i][j] = 0;
        AdjM[j][i] = 0; // Remove the edge in both directions
    }

    // Display the adjacency matrix
    void display() {
        for (int i = 0; i < V; ++i) {
            cout << i << " : ";
            for (int j = 0; j < V; ++j) {
                cout << AdjM[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n";
    }

    // BFS implementation
    void BFS(int start) {
        vector<bool> visited(V, false);  // To keep track of visited vertices
        queue<int> q;  // Queue for BFS

        // Start from the starting vertex
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from vertex " << start << ": ";
        while (!q.empty()) {
            int vertex = q.front();
            cout << vertex << " ";
            q.pop();

            // Traverse all adjacent vertices
            for (int i = 0; i < V; i++) {
                if (AdjM[vertex][i] == 1 && !visited[i]) {  // If there's an edge and it's unvisited
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // DFS Recursive helper function
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;  // Mark the current node as visited
        cout << vertex << " ";   // Output the vertex

        // Traverse all adjacent vertices
        for (int i = 0; i < V; i++) {
            if (AdjM[vertex][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);  // Recur for the adjacent vertex
            }
        }
    }

    // DFS Recursive implementation
    void DFSRecursive(int start) {
        vector<bool> visited(V, false);  // To keep track of visited vertices

        cout << "DFS Recursive Traversal starting from vertex " << start << ": ";
        DFSUtil(start, visited);  // Call the recursive helper function
        cout << endl;
    }

    // DFS Iterative implementation using stack
    void DFSIterative(int start) {
        vector<bool> visited(V, false);  // To keep track of visited vertices
        stack<int> s;  // Stack for DFS

        // Start by pushing the starting vertex to the stack
        s.push(start);

        cout << "DFS Iterative Traversal starting from vertex " << start << ": ";
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            // If the vertex has not been visited
            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = true;  // Mark it as visited
            }

            // Push all unvisited adjacent vertices to the stack
            for (int i =V-1; i >=0; i--) {
                if (AdjM[vertex][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add some edges
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // Display the adjacency matrix
    g.display();

    // Perform BFS, DFS Recursive, and DFS Iterative starting from vertex 0
    g.BFS(1);
    g.DFSRecursive(1);
    g.DFSIterative(1);

    return 0;
}
