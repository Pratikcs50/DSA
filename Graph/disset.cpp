#include<bits/stdc++.h>
//using namespace std;
int parent[100000];
int rank[100000];
void make(){
    for(int i=0;i<100000;i++){
        rank[i]=0;
        parent[i]=i;
    }
}
int find(int node){
    if(node==parent[node]){
        return parent[node];
    }
    return parent[node]=find(parent[node]);
}
void uni(int u,int v){
    u=find(u);
    v=find(v);
    if(rank[v]>rank[u]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

int main(){
    make();
    int m;
    std::cin>>m;
    for(int i=0;i<m;i++ ){
        int u,v;
        std::cin>>u>>v;
        uni(u,v);
    }
    int u,v;
    std::cin>>u>>v;
    if(parent[u]==parent[v]){
        std::cout<<"same component";
    }
}