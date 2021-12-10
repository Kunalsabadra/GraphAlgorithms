#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{


 
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDFS){
     storeDFS.push_back(node);
     vis[node] = 1;
     for(auto it: adj[node]){
         if(!vis[it]){
             dfs(it, vis,adj, storeDFS);
         }
     }
    }
 public:
    vector<int>dfsofGraph(int V, vector<int> adj[]){
        vector<int> storeDFS;
        vector<int> vis(V+1, 0);
        for(int i=1; i<=V; i++){
            if(!vis[i]) dfs(i, vis, adj, storeDFS);
        }
        return storeDFS;
    }
};

int main(){

   int t;
   cin>>t;
   while(t--){
    int V, E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0; i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
      Graph g;
    vector<int> ans = g.dfsofGraph(V , adj);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
   }
    return 0;
}