#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int>bfs(int v,vector<int> adj[]){
            vector<int> bfs;
            vector <int> visited(v+1,0);
            for(int i=1;i<=v;i++){
                if(!visited[i]){
                    queue<int> q;
                    q.push(i);
                    visited[i]=1;
                    while(!q.empty()){
                        int node=q.front();
                        bfs.push_back(node);
                        q.pop();
                    
                        for(auto it : adj[node]){
                            if(!visited[it]){
                                q.push(it);
                                visited[it]=1;
                            }
                        }
                    }
                }
            }
            return bfs;
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
     Solution s;
     vector<int> v = s.bfs(n,adj);
     cout<<endl;
     for(int i=0;i<v.size();i++){
         cout<<v[i]<<" ";
     }
}