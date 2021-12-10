#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main(){
    int n,m;
    cin>>n>>m;
    int count =0;
    vector<vector<int>> adj(n);       //Adjacency list

    vector<int> indegree(n,0);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        count++;
        int x= q.front();
        q.pop();
        cout<<x<<" ";
        for(auto it: adj[x]){
            indegree[it]--;
            if(indegree[it] == 0)
            q.push(it);
        }
    }


    
    return 0;
}