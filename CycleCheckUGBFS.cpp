#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool CheckCycle(int node, vector<int>adj[], int V, vector<int> &visited){
 vector<int> parent(V, -1);

 //Create queue for BFS queue will contain pair which will store
 //current node and previous node
 queue<pair<int, int> >q;
 visited [node] = true;
 q.push({node, -1});

while(!q.empty()){

    int node = q.front().first;
    int parent = q.front().second;
    q.pop();

    for(auto it: adj[node]){
        if(!visited[it]){
            visited[it] = true;
            q.push({it, node});
        }
        else if(parent != it) return true;
    }
}
return false;
}

bool isCycle(int V , vector<int>adj[]){
    vector<int> visited(V, 0);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            if(CheckCycle(i,adj , V, visited)) return true;
        }
    }
    return false;
}

int main(){

    int V, E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(V, adj)){
        cout<<"Cycle present ";
    } 
    else cout<<"Cycle not present ";
    
    return 0;
}