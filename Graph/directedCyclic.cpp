#include<bits/stdc++.h>
using namespace std;

bool checkCyclic(int node,vector<int > adj[],int vis[],int dfsvis[]){
    vis[node]=1;
    dfsvis[node]=1;
    for(auto it: adj[node]){
        if(vis[it]==-1){
            if(checkCyclic(it,adj,vis,dfsvis)){
                return true;
            }
        }else if(dfsvis[it])return true;
    }
    dfsvis[node]=-1;
    return false;
}
bool isCyclic(int V,vector<int> adj[]){
    int vis[V];
    int dfsvis[V];
    memset(vis,-1,sizeof vis);
    memset(dfsvis,-1,sizeof dfsvis);
    for(int i=0;i<V;i++){
        if(vis[i]==-1){
            if(checkCyclic(i,adj,vis,dfsvis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    cout<<isCyclic(n,adj)<<endl;

}