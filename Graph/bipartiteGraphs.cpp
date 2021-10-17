#include<bits/stdc++.h>
using namespace std;
bool bipartiteBfs(int src, vector<int>adj[],int color[]){
    queue<int> q;
    q.push(src);
    color[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                q.push(it);
            }else if(color[it]==color[node]){
                return false;
            }
        }

    }
    return true;
}

bool isBipartite(int V,vector<int> adj[]){
    int color[V];
    memset(color,-1,sizeof color);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(!bipartiteBfs(i,adj,color)){
                return false;
            }
        }
    }
    return true;   
}

int main(){
    int n,m;
     cin>>n>>m;
     vector<int> adj[n+1];
     for(int i=0;i<m;i++){
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     bool a=isBipartite(n,adj);
     if(a==true){
         cout<<" graph is bipartite ";
     }
     else{
         cout<<" not bipartite ";
     }
}