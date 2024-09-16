#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s); // BFS starting from vertex s
    void DFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list
    adj[w].push_back(v); // Add v to w's list (for undirected graph)
}

void Graph::BFS(int s) {
    vector<bool> visited(V, false); // Mark all the vertices as not visited
    queue<int> q; // Create a queue for BFS

    visited[s] = true; // Mark the current node as visited and enqueue it
    q.push(s);

    while (!q.empty()) {
        int currentNode = q.front();
        cout << currentNode << " ";
        q.pop();

        // Iterate over all adjacent vertices of the dequeued vertex
        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void Graph::DFS(int s) {
    vector<bool> visited(V, false); // Mark all the vertices as not visited
    stack<int> stack; // Create a stack for DFS
    

    visited[s] = true; // Mark the current node as visited and push it
    stack.push(s);

    while (!stack.empty()) {
        int currentNode = stack.top();
        cout << currentNode << " ";
        stack.pop();

        // Iterate over all adjacent vertices of the popped vertex
        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}


int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "BFS : ";
    g.BFS(0);
    cout<<"\n";
    cout<<"DFS: ";
    g.DFS(0);
  

    return 0;
}
