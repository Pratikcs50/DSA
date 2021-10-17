#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src=0;
   // cin>>src;
    int key[n];
    int parent[n];
    bool vis[n];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        vis[i]=false;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    parent[0]=-1;
    key[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        vis[node]=true;
        for(auto it : adj[node]){
            int weight=it.second;
            int next_node=it.first;
            if(vis[next_node]==false&&key[next_node] >weight){
                parent[next_node]=node;
                pq.push({key[next_node],next_node});
                key[next_node]=weight;
            }
        }

    }

    for(int i=1;i<n;i++){
        cout<<parent[i]<<"->"<<i<<endl;
    }

}