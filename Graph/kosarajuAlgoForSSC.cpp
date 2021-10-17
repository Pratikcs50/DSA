#include<bits/stdc++.h>
using namespace std;

     vector<int> adj[100];
     vector<int>rev[100];
void dfs(int n,vector<int>adj[],stack<int>&st,vector<int>&vis){
    vis[n]=1;
    for(auto it: adj[n]){
        if(vis[it]==-1){
            dfs(it,adj,st,vis);
        }
    }//cout<<" n : "<<n <<endl;
    st.push(n);
}
void reverse(int n,vector<int>rev[],vector<int>adj[]){
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            rev[it].push_back(i);
        }
        
    }
}
void dfs2(int n,vector<int>&vis,vector<int>rev[]){
    vis[n]=1;
    cout<<n<<" ";
    for(auto it : rev[n]){
        if(vis[it]==-1){
            dfs2(it,vis,rev);
        }//else cout<<n<<" ";
    }
}
void findSsc(int n,vector<int>adj[],vector<int>rev[]){
    stack<int> st;
    vector<int> vis(n,-1);
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            dfs(i,adj,st,vis);
        }
    }
    reverse(n,rev,adj);
    for(int i=0;i<n;i++){
        vis[i]=-1;
    }
    cout<<" SSC are : "<<endl;
    while(!st.empty()){
        int ele=st.top();
        
        st.pop();
        //cout<<ele<<" vis ele :"<<vis[ele]<<endl;
        if(vis[ele]==-1){
            //cout<<ele<<" ";
            dfs2(ele,vis,rev);
            cout<<endl;
        }
        
    }

}
int main(){
    int n,m;
     cin>>n>>m;

     for(int i=0;i<m;i++){
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
     }
    
     findSsc(n,adj,rev);

			

}