#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"----jai shree ram----"<<endl;
    int n;
    cout<<"Total number of process: "<<endl;
    cin>>n;
    int at[n];
    cout<<"Enter Arrival time: "<<endl;
    for(int i=0;i<n;i++) cin>>at[i];
    int bt[n];
    cout<<"Enter Burst time: "<<endl;
    for(int i=0;i<n;i++) cin>>bt[i];
    int ct[n];
    int tat[n];
    int wt[n];
    vector<pair<int,int>>vp;
    for(int i=0;i<n;i++) vp.push_back({at[i],bt[i]});
    sort(vp.begin(),vp.end());
    for(int i=0;i<n;i++){
        if(i==0) ct[i]=vp[i].second;
        else{
            if(vp[i].first <= ct[i-1]) ct[i]=ct[i-1]+vp[i].second;
            else ct[i]=vp[i].first+vp[i].second;
        }
    }
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    cout<<"at"<<"   "<<"bt"<<endl;
    for(auto i:vp){
        cout<<i.first<<"    "<<i.second<<endl;
    }
    //cout<<"---";
    cout<<"ct"<<"   "<<"tat"<<"   "<<"wt"<<endl;
    for(int i=0;i<n;i++){
        cout<<ct[i]<<"     "<<tat[i]<<"    "<<wt[i]<<endl;
    }
    return 0;
}