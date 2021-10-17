#include<bits/stdc++.h>
using namespace std;
void toposort(int node,vector<pair<int,int>>adj[],stack<int> &st,int vis[]){
    vis[node]=1;
    for(auto it : adj[node]){
        if(vis[it.first]==0){
            toposort(it.first,adj,st,vis);
        }
    }
    st.push(node);
}
void shortestPath(int src,int n,vector<pair<int,int>> adj[]){
    stack <int> st;
    int vis[n]={0};
    
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            toposort(i,adj,st,vis);
        }
    }
    int dis[n];
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
    }
    dis[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
            if(dis[node]!=INT_MAX){
                for(auto it: adj[node]){
                if((dis[node]+it.second) < dis[it.first]){
                    dis[it.first]=dis[node]+it.second;
                }
            }
            }
            
        
    }
    for(int i=0;i<n;i++){
        (dis[i]==INT_MAX)?cout<<" INF " : cout<<dis[i]<<" ";
    }
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        //adj[v].push_back(u);
    }
    int src;
    cin>>src;
    shortestPath(src,n,adj);
    
}