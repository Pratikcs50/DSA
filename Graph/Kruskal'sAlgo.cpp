#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    public:
        node(int u,int v,int wt){
            this->u=u;
            this->v=v;
            this->wt=wt;

        }
};
bool comp(node a,node b){
    return a.wt <b.wt;
}
int find(int n,vector<int> &parent){
    if(n==parent[n]){
        return parent[n];
    }
    return parent[n]=find(parent[n],parent);
}
void unn(int u,int v,vector<int > &parent,vector<int>&rank){
    u=find(u,parent);
    v=find(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent [v]=u;
    }
    else{
        parent[u]=v;
        rank[v]++;
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    sort(edges.begin(),edges.end(),comp);
    vector<int> parent(n);
    for(int i=0;i<n;i++)parent[i]=i;
    vector<int> rank(n,0);
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto it:edges){
        if(find(it.v,parent)!=find(it.u,parent)){
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unn(it.u,it.v,parent,rank);
        }
    }
    cout<<cost<<endl;
    for(auto it:mst)cout<<it.first<<"->"<<it.second<<endl;
}