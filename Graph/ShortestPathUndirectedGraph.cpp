#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void bfs(int v,int src,vector<int> adj[]){
            
            int visited[v];
            for(int i=0;i<v;i++){visited[i]=INT_MAX;}
            
                    queue<int> q;
                    visited[src]=0;
                    q.push(src);
                    while(!q.empty()){
                        int node=q.front();
                        q.pop();
                    
                        for(auto it : adj[node]){
                            if((visited[node]+1)<visited[it]){
                                
                                visited[it]=visited[node]+1;
                                q.push(it);
                            }
                        }
                    }
            for(int i=0;i<v;i++){
         cout<<visited[i]<<" ";
     }
            
            
        }
};
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
     int src;
     cin>>src;
     Solution s;
     s.bfs(n,src,adj);
     cout<<endl;
     
}