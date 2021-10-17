#include<bits/stdc++.h>
using namespace std;

int min_ele(int ar[],int n){
    stack<int> st;
    stack<int> ss;
    for(int i=0;i<n;i++){
        st.push(ar[i]);
        if(i==0){
            ss.push(ar[i]);
        }
        else{
            if(st.top()<ss.top()){
                ss.push(st.top());
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    while(!ss.empty()){
        cout<<ss.top()<<" ";
        ss.pop();
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    cout<<min_ele(ar,n);
}