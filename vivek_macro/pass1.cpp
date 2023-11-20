#include<bits/stdc++.h>
using namespace std;
int main(){
    fstream inp,mdt,mnt,ic,ala;
    inp.open("input.txt",ios::in);
    mdt.open("mdt.txt",ios::out);
    mnt.open("mnt.txt",ios::out);
    ic.open("ic.txt",ios::out);
    ala.open("ala.txt",ios::out);
    string line;
    int ct=0;int flag=0;
    map<string,string>m;
    while(getline(inp,line)){
        ct++;
        if(line=="MACRO"){
            flag=1;
            ct--;
        }
        else if(line=="MEND"){
            flag=0;
            ct--;
        }
        else if(flag==1){
            mdt<<line<<endl;
            string temp="";
            for(auto ch:line){
                if(ch !=' '){
                    temp +=ch;
                }
                else{
                    mnt<<temp<<" "<<ct<<endl;
                    break;
                }
            }
            bool check=0;
            int cnt=0;
            temp="";
            for(auto ch:line){
                if(ch=='='){
                    break;
                }
                else if(ch==' '){
                    check=1;
                }
                else if(ch==','){
                    m[temp]='#'+to_string(cnt);
                    cnt++;
                    temp="";
                }
                else if(check){
                    temp +=ch;
                }
            }
            m[temp]='#'+to_string(cnt);
            flag=2;
        }else if(flag==2){
            string temp="";
            for(auto ch:line){
                if(ch !=' '){
                    temp +=ch;
                }
                else{
                    mdt<<temp<<" ";
                    break;
                }
            }
            temp="";
            bool check=0;
            for(auto ch:line){
                if(ch ==' '){
                    check=1;
                }
                else if(ch==','){
                    mdt<<m[temp]<<",";
                    temp="";
                }
                else if(check==1){
                    temp +=ch;
                }
            }
            mdt<<m[temp]<<endl;
        }
        else{
            ic<<line<<endl;
        }
    }
    for(auto i:m) cout<<i.first<<" "<<i.second<<endl;
  
    inp.close();
    mdt.close();
    mnt.close();
    ic.close();
    return 0;
}