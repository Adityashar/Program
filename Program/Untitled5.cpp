#include<iostream>
#include<string>
using namespace std;

int number(string s,char ch){
    int cnt=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==ch)   cnt++;
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        string s="";
        int n;
        cin>>s;
        cin.ignore();
        cin>>t;
        for(int i=0;i<n;i++){
            s=s+s;
        }
        cout<<s;/*
        int cnt=0;
        for(int i=0;s[i]!='\0';i++){
            for(int j=0;j<=i;j++){
                int na=number(s.substr(i,j),'a');
                int nb=number(s.substr(i,j),'b');
                if(na>nb)   cnt++;
            }
        }
        cout<<cnt;*/
    }
}
