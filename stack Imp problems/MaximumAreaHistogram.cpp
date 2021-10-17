/*
the problem is a mixture of nearest_smaller_right and nearest_smaller_left
. The code had been submitted to hackerrank and use array as much possible as vector takes much more space 
In this problem the the code fails in few testcase if NSL and NSR had been vectors. GOOD LUCK !! :)  
*/
#include<bits/stdc++.h>
using namespace std;
long MaxRectangle(vector <int> v){
    int NSL[v.size()];    //find index of nearest smaller to left
    int NSR[v.size()];     //find index of nearest smaller to right
    stack<int> st;
    long max=0,area,temp;
    for(int i=0;i<=v.size();i++){
        while(!st.empty()&&v[i]<v[st.top()]){
            NSR[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        NSR[st.top()]=v.size()+1;
        st.pop();
    }
    for(int i=v.size()-1;i>=0;i--){
        while(!st.empty()&&v[i]<v[st.top()]){
            NSL[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        NSL[st.top()]=-1;
        st.pop();
    }
    for(int i=0;i<=v.size();i++){
        area=v[i]*((NSR[i]-NSL[i])-1);
        temp=area;
        if(max<temp){
            max=temp;
        }
    }
    return max;
}
int main(){
    long q;
    cin>>q;
    vector<int> v;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    long max=MaxRectangle(v);
    cout<<max<<endl;
}