#include<bits/stdc++.h>
using namespace std;
void toposort(int node,vector<int>adj[],stack<int> &st,int vis[]){
    vis[node]=1;
    for(auto it : adj[node]){
        if(vis[it]==-1){
            toposort(it,adj,st,vis);
        }
    }
    st.push(node);
}
vector<int> topoSort(int n,vector<int> adj[]){
    stack <int> st;
    int vis[n];
    memset(vis,-1,sizeof vis);
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            toposort(i,adj,st,vis);
        }
    }
    vector<int> v;
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    return v;
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
    vector <int > v=topoSort(n,adj);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}