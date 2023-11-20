#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<" Enter total number of processor: "<<endl;
    cin>>n;
    int q;cin>>q;
    vector<vector<int>>v;
    int mx=INT_MIN;
    int mi=INT_MAX; 
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vector<int>temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
        mx=max(a,mx);
        mi=min(a,mi);
    }
    int r=mi;
    vector<int>ans;
    vector<int>ct(n);
    for(int i=0;i<n;i++){
        if(mi==v[i][0]) ans.push_back(i);
    }
    while(true){
        if(ans.size()==0 and r>mx) break;
        if(ans.size()==0){
            r=r+q;
            for(int i=0;i<n;i++){
                if(v[i][0]> r-q and v[i][0]<=r) ans.push_back(i);
            }
        }
        else{
            int top=ans[0];//index of ready queue
            if(v[top][1]-q >0){
                v[top][1] -=q;
                r +=q;
                for(int i=0;i<n;i++){
                    if(v[i][0] > r-q and v[i][0] <=r) ans.push_back(i);
                }
                ans.push_back(top);
                ans.erase(ans.begin());
            }
            else{// agar quantum time se kam hua
                r +=v[top][1];//burst time
                v[top][1]=0;
                for(int i=0;i<n;i++){
                    if(v[i][0]> r-v[top][1] and v[i][0] <=r) ans.push_back(i);
                }
                ct[top]=r;
                ans.erase(ans.begin());
            }
        }
    }
    for(auto i:ct) cout<<i<<" ";
    return 0;
}