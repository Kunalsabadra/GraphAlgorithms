#include<bits/stdc++.h>
using namespace std;

//Using DFS

bool checkCycle(int node, vector<int>adj[] , vector<int> &visited , int parent){

visited[node] = 1;

for(auto it: adj[node]){
	if(!visited[it]){
		if (checkCycle(it ,adj ,visited , node))
		return true;
	}
	else if(it != parent)
	return true;
}
return false;
}

bool isCycle(int V , vector<int> adj[]){

	vector<int> visited(V, 0);
    for(int i=0; i<V; i++){
		if(!visited[i]){
			if(checkCycle(i,adj , visited , -1))
           return true;
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
		 adj[v].push_back(u);
		 adj[u].push_back(v);
	 }

	 if(isCycle(V, adj)) {
		 cout<<"Cycle Present";
	 }
	 else cout<<"Cycle not Present ";

 return 0;
 }