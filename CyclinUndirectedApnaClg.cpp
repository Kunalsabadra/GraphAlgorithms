#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool checkcycle(int src , vector<int>adj[], vector<bool>&visited, int parent){
    visited[src] = true;
    for(auto i: adj[src]){
        if(i != parent){
            if(visited[i]) return true;
            if(!visited[i] and checkcycle(i, adj,visited,-1)) return true;
 }
    }
    return false;
}


bool isCycle( int n, vector<int> adj[]){

    vector<bool>visited(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i] and checkcycle(i, adj, visited, -1)){
            return true;
        }
    }
return false;

}


int main(){

    

        int n,m;
        cin>>n>>m;
        vector<int>adj[n];
        for(int i=0; i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(isCycle(n,adj))  cout<<"Cycle Present ";

        else  cout<<"Cycle is not present";
        

    


    
    return 0;
}