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
    int j=0;
    for(int i=0;i<m;i++){
        int l=n;
        while(l>0){
            if(ps[i]<=mb[j] and flag[j]==false){
                flag[j]=true;
                ans[j]=ps[i];
                break;
            }
            //j=(j+1)%n;
            j++;
            l--;
        }
    }
    for(int i=0;i<n;i++) cout<<i<<" "<<ans[i]<<endl;
    return 0;
}