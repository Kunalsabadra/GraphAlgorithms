#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node , int parent , vector<int> &vis, vector<int> adj[]){
    vis[node] =1;
    for(auto it:adj[node]){
        if(!vis[it]){
          if(checkCycle(it, node, vis, adj))
          return true;
        }
         else if(it != parent)
         return true;
    }
    return false;
}

bool Cycle(int V, vector<int> adj[]){
    vector<int> vis(V+1, 0);
    for(int i=9; i<V; i++){
        if(!vis[i]){
            if(checkCycle(i, -1, vis, adj)) return true;
        }
    }
    return false;
}

int main(){

    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   if(Cycle(V,adj)){
       cout<<"Cycle is present";
   }
   else cout<<"Cycle is not present ";
    
    return 0;
}