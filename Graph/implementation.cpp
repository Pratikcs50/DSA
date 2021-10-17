 #include<bits/stdc++.h>
 using namespace std;

 //Adjacency matrix method
 void adjacent_matrix(){
     int m,n;
     cin>>n>>m;
     int adj[n+1][n+1];
     for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)adj[i][j]=0;
     for(int i=0;i<m;i++){
         int u,v;
         cin>>u>>v;
         adj[u][v]=1;
         adj[v][u]=1;
     }
     for(int i=1;i<=n;i++){
         cout<<i <<"--> ";
         for(int j=1;j<=n;j++){
             cout<<adj[i][j]<<" ";
         }
         cout<<endl;
     }
 }
 //Adjacency list
 void adjacency_list(){
     int n,m;
     cin>>n>>m;
     vector<int> adj[n+1];
     for(int i=0;i<m;i++){
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     for(int i=1;i<=n;i++){
         cout<<i <<"--> ";
         for(int j=0;j<adj[i].size();j++){
             cout<<adj[i][j]<<" ";
         }
         cout<<endl;
     }
 }
 int main(){
     adjacent_matrix();
     //adjacency_list();
 }