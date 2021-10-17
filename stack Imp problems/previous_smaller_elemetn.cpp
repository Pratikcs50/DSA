#include<bits/stdc++.h>
using namespace std;

vector<int> PSE(vector<int> v){
    vector<int> sm(v.size());
    stack<int> st;
    for(int i=v.size()-1;i>=0;i--){
        while(!st.empty()&&v[i]<v[st.top()]){
            sm[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        sm[st.top()]=-1;
        st.pop();
    }
    return sm;
}
int main(){
    int q;
    cin>>q;
    vector<int > v;
    vector<int> sm;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        v.push_back(x);        
    }
    sm=PSE(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "<<((sm[i]==-1)?-1:v[sm[i]])<<endl;
    }

}