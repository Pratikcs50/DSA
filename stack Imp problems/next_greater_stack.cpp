#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector <int> v){
    vector<int>nge(v.size());
    stack<int> st;
    for(int i=0;i<v.size();i++){
        while(!st.empty()&&v[i]>v[st.top()]){
            //cout<<nge[st.top()]<<endl;
            nge[st.top()]=i;
            //cout<<nge[st.top()]<<endl;
            st.pop();
        }
        st.push(i);
        //cout<<"push "<<st.top()<<endl;
    }
    while(!st.empty()){
        nge[st.top()]=-1;
        st.pop();
    }
    return nge;
}
int main(){
    int size;
    cin>>size;
    vector<int> n;
    while(size--){
        int x;
        cin>>x;
        n.push_back(x);

    }
    
    vector<int> v=NGE(n);
    for(int i=0;i<v.size();i++){
        cout<<n[i]<<" "<<(v[i]==-1?-1 : n[v[i]])<<endl;
    }

}