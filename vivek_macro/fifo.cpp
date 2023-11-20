#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter total number of pages: "<<endl;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int m;
    cout<<"Enter the frame sizes: "<<endl;
    cin>>m;

    vector<int>ans(m,-1);
    int index=-1;
    for(int i=0;i<n;i++){
        if(i<m){
            ans[i]=v[i];
            cout<<ans[i]<<" adding in the frame.frame contents:";
            for(int j:ans) cout<<j<<" ";
            cout<<endl;
        }
        else{
            //cout<<i<<" "<<v[i]<<endl;
            bool flag=false;
            int temp=v[i];
            for(int i=0;i<ans.size();i++){
                if(temp==ans[i]){
                    cout<<temp<<" already in the frame.frame contents:";
                    for(int j:ans) cout<<j<<" ";
                    cout<<endl;
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                index=(index+1)%m;
                ans[index]=v[i];
                cout<<ans[index]<<" adding in the frame.frame contents:";
                for(int j:ans) cout<<j<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}