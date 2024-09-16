#include<bits/stdc++.h>
using namespace std;
void topologicalSort(vector<vector<int>>adj,int v){
     vector<int>ans;
     vector<int>indegree(v,0);
     queue<int>q;
     for(int i=0;i<v;i++){
        for(auto neighbour:adj[i]){
            indegree[neighbour]++;
        }
     }
     for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
     }
     while(!q.empty()){
          int x=q.front();
          q.pop();
          ans.push_back(x);
          for(auto neighbour:adj[x]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
          }
     }
     for(auto x:ans){
        cout<<x<<" ";
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
    return 0;
}