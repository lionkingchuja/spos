#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the total number of processor: "<<endl;
    cin>>n;
    int ma=INT_MIN;
    int mi=INT_MAX;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vector<int>temp;        
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        v.push_back(temp);
        ma=max(ma,a);
        mi=min(mi,a);
    }
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(v[i][0]==mi){
            vector<int>temp;
            temp.push_back(1*v[i][2]);//lesser no high the priority
            temp.push_back(v[i][0]);
            temp.push_back(i);
            ans.push_back(temp);
        }
    }   

    vector<int>ct(n);
    int r=mi;
    int l=n;
    while(l>0){
        //if(r==ct.size()) break;
        if(ans.size()==0){
            r++;
            for(int i=0;i<n;i++){
                if(v[i][0]==r){
                    vector<int>temp;
                    temp.push_back(1*v[i][2]);
                    temp.push_back(v[i][0]);
                    temp.push_back(i);
                    ans.push_back(temp);
                }
            }  
        }
        else{
            sort(ans.begin(),ans.end());
            int in=ans[0][2];//index access kar raha hu.
            int b=v[in][1];//index ke help se access kar raha hu.
            ct[in]=r+b;
            l--;
            r =r+b;//pura complete ke baad next at Aayega nom-premitive
            for(int i=0;i<n;i++){
                if(v[i][0] > r-b and v[i][0] <=r){
                    vector<int>temp;
                    temp.push_back(1*v[i][2]);
                    temp.push_back(v[i][0]);
                    temp.push_back(i);
                    ans.push_back(temp);
                }
            }
            ans.erase(ans.begin());
        }
    }
    for(int i=0;i<n;i++) cout<<ct[i]<<" ";
    return 0;
}