#include<bits/stdc++.h>
using namespace std;

vector<int> PGE(vector<int> v){
    vector<int>pge(v.size());
    stack<int> st;
    for(int i=v.size()-1;i>=0;i--){
        
        while(!st.empty()&&v[i]>v[st.top()]){
            pge[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        pge[st.top()]=-1;
        st.pop();
    }
    return pge;
}
int main(){
    int s;
    cin>>s;
    vector<int> v;
    vector<int> n;
    for(int i=0;i<s;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    n=PGE(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  "<<((n[i]==-1)?-1:v[n[i]])<<endl;
    }
}