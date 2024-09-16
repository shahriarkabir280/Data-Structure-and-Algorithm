#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int V;//number of vertices
    vector<vector<int>>AdjM;
    Graph(int x){
        V=x;
       AdjM.resize(V);
    }

    void addEdge(int i,int j){
       
        AdjM[i].push_back(j);
        AdjM[j].push_back(i);//for undirected graph
    }
    void removeEdge(int i,int j){
        // Remove j from AdjM[i]
        AdjM[i].erase(remove(AdjM[i].begin(), AdjM[i].end(), j), AdjM[i].end());

        // Remove i from AdjM[j] (for undirected graph)
        AdjM[j].erase(remove(AdjM[j].begin(), AdjM[j].end(), i), AdjM[j].end());
    }

    void display(){
        for(int i=0;i<AdjM.size();++i){
            cout<<i<<" : ";
            for(int j:AdjM[i]){
                
                cout<<j<<" ";

            }
            cout<<"\n";
        }
        
    }


    void BFS(int s) {
    vector<bool> visited(V, false); // Mark all the vertices as not visited
    queue<int> q; // Create a queue for BFS

    visited[s] = true; // Mark the current node as visited and enqueue it
    q.push(s);

    while (!q.empty()) {
        int currentNode = q.front();
        cout << currentNode << " ";
        q.pop();

        // Iterate over all adjacent vertices of the dequeued vertex
        for (int neighbor : AdjM[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void DFS(int s) {
    vector<bool> visited(V, false); // Mark all the vertices as not visited
    stack<int> stack; // Create a stack for DFS
    

    visited[s] = true; // Mark the current node as visited and push it
    stack.push(s);

    while (!stack.empty()) {
        int currentNode = stack.top();
        cout << currentNode << " ";
        stack.pop();

        // Iterate over all adjacent vertices of the popped vertex
        for (int neighbor : AdjM[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}



};

int main(){
    
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.display();
    g.removeEdge(1,2);
    cout<<"after: "<<"\n";
    g.display();
    cout<<"BFS: ";
    g.BFS(0);
    cout<<"\n";
    g.DFS(0);
    cout<<"DFS: ";
 

    return 0;
}