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
                int ma=INT_MIN;
                for(int j=0;j<ans.size();j++){
                    bool flag1=true;
                    for(int k=i+1;k<n;k++){
                        if(ans[j]==v[k]){
                            flag1=false;
                            if(ma < k){
                                ma=k;
                                index=j;
                                break;
                            }
                            break;
                        }
                    }
                    if(flag1==true) {
                        index=j;
                        break;
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