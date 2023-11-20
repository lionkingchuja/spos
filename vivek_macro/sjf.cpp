#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"total no. of process: "<<endl;
    cin>>n;
    vector<vector<int>>v;
    int mx=INT_MIN;//kaha tk jana jai
    int mi=INT_MAX;//kaha se start hai
    for(int i=0;i<n;i++){
        vector<int>temp;
        int a,b;
        cin>>a>>b;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
        mx=max(mx,a);
        mi=min(mi,a);
    }
    int r=mi;
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(v[i][0]==r){
            vector<int>temp;
            temp.push_back(v[i][1]);
            temp.push_back(v[i][0]);
            temp.push_back(i);
            ans.push_back(temp);
        }
    }
    vector<int>ct(n);
    //vector<int>ct1;
    while(true){
        if(ans.size()==0 and r>mx) break;
        if(ans.size()==0) r++;// at ka gape 2 se 8 hai
        else{
            sort(ans.begin(),ans.end());
            ans[0][0] -=1;//1 sec chala rahe hai
            r++;//at ko increase kar rah hu
            if(ans[0][0]==0){
                ct[ans[0][2]]=r;
                //ct1.push_back(r); for gaint
                ans.erase(ans.begin());
            }
            for(int i=0;i<n;i++){
                if(v[i][0]==r){
                    vector<int>temp;
                    temp.push_back(v[i][1]);
                    temp.push_back(v[i][0]);
                    temp.push_back(i);
                    ans.push_back(temp);
                }
            }
        }
    }
    for(auto i:ct) cout<<i<<" ";
    cout<<endl;
    //for(auto i:ct1) cout<<i<<" ";
    return 0;
}