#include<bits/stdc++.h>
using namespace std;
#define MaxSize 10000

struct DSU{
    int parent[MaxSize];
    int rank[MaxSize];
   // int size[MaxSize];

    void make_set(int x){
        parent[x]=x;
        rank[x]=0;
       // size[x]=1;
    }
    int find_set(int x){
        if(x==parent[x]){
            return x ;
        }
        return parent[x]=find_set(parent[x]);
    }
    //unionbysize
   /* void union_sets(int a,int b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }*/
    //union by rank
    void union_sets(int a, int b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(rank[a]<rank[b]){
                swap(a,b);
            }
            parent[b]=a;
        if(rank[a]==rank[b])
        rank[a]++;
        }
    }

};

int main(){

    DSU* dsu= new DSU();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        dsu->make_set(x);

    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        dsu->union_sets(x,y);
    }
    int p;
    cin>>p;
    for(int j=0;j<p;j++){
        int r,s;
        cin>>r>>s;
        if(dsu->find_set(r)==dsu->find_set(s)){
            //they are in same set
            cout<<1<<"\n";
        }
        else{
            //ther are not in same set
            cout<<0<<"\n";
        }
    }
   
}