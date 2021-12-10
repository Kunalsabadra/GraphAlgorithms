#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
 
 public:
 vector<int>topo(int N, vector<int>adj[]){

     queue<int>q;
     vector<int> indegree(N,0);
     for(int i=0; i<N; i++){
         for(auto i:adj[N]){
             indegree[i] ++;
         }
     }

     for(int i=0; i<N; i++){
    if(indegree[i] == 0){
        q.push(i);
    }
     }
 
 vector<int> Topo;
 while(!q.empty()){
    int x= q.front();
  
    q.pop();
     Topo.push_back(x);
    for(auto it: adj[x]){
        indegree[it]--;
        if(indegree[it] == 0){
            q.push(it);
        }
    }

 }
return Topo;
 }
};

int main(){

    int N,E;
    cin>>N>>E;
    int u, v;
    vector<int> adj[N];

    for(int i=0; i<E; i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    Graph g;
    // cout<<g.icCyclic();
    vector<int> ans =g.topo(N, adj);
    for(int i=0; i<ans.size(); i++){
   cout<<ans[i]<<" ";

    }
    
    return 0;
}