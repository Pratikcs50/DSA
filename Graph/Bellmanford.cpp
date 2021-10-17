#include<bits/stdc++.h>
using namespace std;
struct node{
    int u;
    int v;
    int wt;
    node(int ut,int vt,int wtt){
        u=ut;
        v=vt;
        wt=wtt;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<node> ed;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        ed.push_back(node(u,v,wt));
    }
    int sr;
    cin>>sr;
    vector<int>dis(n,1000000);
    dis[sr]=0;
   
    for(int i=1;i<=n-1;i++){
        for(auto it:ed){
            //cout<<(dis[it.u]+it.wt)<<"  "<<dis[it.v]<<endl;
            if((dis[it.u]+it.wt) < dis[it.v]){
                //cout<<(dis[it.u]+it.wt)<<"  "<<dis[it.v]<<endl;
                dis[it.v]=dis[it.u]+it.wt;

            }

        }
    }
    int ct=0;
    for(auto it: ed){
        if((dis[it.u]+it.wt) < dis[it.v]){
            cout<<" -ve cycle ";
            ct=1;
            break;
        }
    }
    if(ct==0){
        for(int i=0;i<n;i++){
           cout<<i<<" "<<dis[i]<<endl;
        }
    }

}