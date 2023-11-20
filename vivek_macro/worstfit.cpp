#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. of memory blocks: "<<endl;
    cin>>n;
    vector<int>mb(n);
    for(int i=0;i<n;i++) cin>>mb[i];

    int m;
    cout<<"Enter the no. of processor: "<<endl;
    cin>>m;
    vector<int>ps(m);
    for(int i=0;i<m;i++) cin>>ps[i];

    vector<int>ans(n);
    vector<bool>flag(n,false);
    for(int i=0;i<m;i++){
        int ma=INT_MIN;
        int in=-1;
        for(int j=0;j<n;j++){
            if(mb[j] >= ps[i] and flag[j]==false){
                int diff=mb[j]-ps[i];
                ma=max(diff,ma);
            }
        }
        for(int j=0;j<n;j++){
            if(ma+ps[i]==mb[j]) in=j;
        }
        if(in==-1){
            cout<<ps[i]<<" are not allocated"<<endl;
        }
        else{
            flag[in]=true;
            ans[in]=ps[i];
        }
    }
    for(int i=0;i<n;i++) cout<<i<<" "<<ans[i]<<endl;
    return 0;
}