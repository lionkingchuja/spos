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

    vector<int>ans(m,-1);int cnt=0;
    for(int i=0;i<n;i++){
        if(i<m){
            ans[i]=v[i];
            cout<<ans[i]<<" adding in the frame. frame contents: ";
            for(auto it:ans) cout<<it<<" ";
            cout<<endl;
            cnt++;
        }
        else{
            int temp=v[i];
            bool flag=true;
            for(int j=0;j<ans.size();j++){
                if(temp==ans[j]){
                    cout<<temp<<" already in the frame. frame contents: ";
                    for(auto it:ans) cout<<it<<" ";
                    cout<<endl;
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                int index=-1;
                int mi=INT_MAX;
                for(int j=0;j<ans.size();j++){
                    for(int k=i-1;k>=0;k--){
                        if(ans[j]==v[k]){
                            if(mi > k){
                                mi=k;
                                index=j;
                                //cout<<index<<endl;
                                break;
                            }
                            break;
                        }
                    }
                
                }
                cnt++;
                ans[index]=temp;
                cout<<ans[index]<<" adding in the frame. frame contents: ";
                for(auto it:ans) cout<<it<<" ";
                cout<<endl;
            }
        }
    }
    cout<<"Total number of page fault: "<<cnt;
    return 0;
}