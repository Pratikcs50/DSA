#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
     cin>>n>>m;
     vector<pair<int,int>> adj[n+1];
     for(int i=0;i<m;i++){
         int u,v,w;
         cin>>u>>v>>w;
         adj[u].push_back({v,w});
         adj[v].push_back({u,w});
     }
     int src;
     cin>>src;
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     vector<int>dist(n+1,INT_MAX);
     dist[src]=0;
     pq.push({0,src});
    
     while(!pq.empty()){
         int prev=pq.top().second;
         int prevdist=pq.top().first;
         pq.pop();
         for(auto it:adj[prev]){
             int next=it.first;
             int nextdist=it.second;
             if(dist[next]>dist[prev]+nextdist){
                 dist[next]=dist[prev]+nextdist;
                 pq.push({dist[next],next});        
             }
         }
     }
     for(int i=0;i<n;i++){
         cout<<dist[i]<<" ";
     }


}