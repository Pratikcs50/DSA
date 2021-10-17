#include<bits/stdc++.h>
using namespace std;
class Solution{
    void dfs(int n, vector<int> &vis, vector<int> adj[],vector<int> &store){
        store.push_back(n);
        vis[n]=1;
        for(auto it:adj[n]){
            if(vis[it]==-1){
                dfs(it,vis,adj,store);
            }
        }
    }
    public :
        vector<int> dfs(int n,vector<int> adj[]){
            vector<int> vis(n,-1);
            vector<int> store;
            for(int i=0;i<n;i++){
                if(vis[i]==-1){
                    dfs(i,vis,adj,store);
                }
            }
            return store;
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
     vector<int> v = s.dfs(n,adj);
     cout<<endl;
     for(int i=0;i<v.size();i++){
         cout<<v[i]<<" ";
     }
}