#include<bits/stdc++.h>
using  namespace std;
  int water_trap(vector<int> v){
    vector<int> lmax(v.size());
    vector<int> rmax(v.size());
    lmax[0]=v[0];
    rmax[0]=v[v.size()-1];
    for(int i=1;i<v.size();i++){
        if(lmax[i-1]>v[i]){
            lmax[i]=lmax[i-1];
        }
        else
         lmax[i]=v[i];
    }
    int j=1;
     for(int i=v.size()-2;i>=0;i--){
        
        if(rmax[j-1] > v[i]){
            rmax[j]=rmax[j-1];
        }
        else
         rmax[j]=v[i];
       
        j++;
    }
  
    
    // for(int i=0;i<v.size();i++){
    //    cout<<lmax[i]<<" ";
    // }
    cout<<endl;
    reverse(rmax.begin(),rmax.end());
    // for(int i=0;i<v.size();i++){
    //    cout<<rmax[i]<<" ";
    // }
    int height_water=0;
    for(int i=0;i<v.size();i++){
        height_water= min(lmax[i],rmax[i])-v[i]+height_water;
    }
    cout<<endl;
    return height_water; 
}
int main(){
    
    vector <int> v;
    int s;
    cin>>s;
    for(int i=0;i<s;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<water_trap(v);

}