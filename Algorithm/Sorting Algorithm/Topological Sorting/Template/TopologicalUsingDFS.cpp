#include<bits/stdc++.h>
using namespace std;
void topologicalSortUtil(int s,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&stk){
    visited[s]=true;
    for(int neighbour:adj[s]){
        if(!visited[neighbour]){          
           topologicalSortUtil(neighbour,adj,visited,stk);
        }
       
    }
     stk.push(s);
    
}
void topologicalSort(vector<vector<int>>&adj,int V){
            vector<bool>visited(V,false);
            stack<int>s;
            for(int i=0;i<V;i++){
               if(!visited[i]){
                topologicalSortUtil(i,adj,visited,s);
               }
            }
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
             }
            
}


int main(){
    int V,E;
    cin>>V>>E;
   vector<vector<int>>adj(V);
   
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    topologicalSort(adj,V);

}