#include<bits/stdc++.h>
using namespace std;
 
class Solution{
    public:
        void dfs(int n,int parent,vector<int>adj[],vector<int>&vis,vector<int>&storage,int &cy){
            storage.push_back(n);
            vis[n]=1;
            for(auto it : adj[n]){
                if(vis[it]==0){
                    dfs(it,n,adj,vis,storage,cy);
                }else if(it!= parent){
                    cy++;
                }
            }
        }
        bool isCycle(int n,vector<int>adj[]){
            vector<int> storage;
            vector<int >vis(n+1,0);
            int cy=0;
            for(int i=1;i<n+1;i++){
                if(vis[i]==0){
                  dfs(i,-1,adj,vis,storage,cy);  
                }
            }
            if(cy>0)return true;
            
            return false;
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
     cout<< s.isCycle(n,adj);
     
     
}
