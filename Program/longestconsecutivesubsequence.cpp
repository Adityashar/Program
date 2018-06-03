#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

unordered_map<int,int> map1;

void lng_sub(int *a,int n){

    int i=0,j=1,temp;
    while(i<n-1){
        if((i+j<n)&&a[i]+j==a[i+j]){
            j++;
        }
        else{
            map1.insert(make_pair(i,j+i-1));
            i=j+i;
            j=1;
        }
    }
    int diff=0;
    unordered_map<int,int>::iterator it;
    for(auto ip=map1.begin();ip!=map1.end();ip++){
        if(diff<= ip->second-ip->first){
            diff=ip->second-ip->first;
            it=ip;
        }
    }/*
    for(auto ip=map1.begin();ip!=map1.end();ip++){
        cout<<ip->first<<" "<<ip->second<<endl;
    }*/
    if(it->first==it->second){
        cout<<a[it->first];
    }
    else{
        for(int i=it->first;i<=it->second;i++){
            cout<<a[i]<<" ";
        }
    }
}

int main(){
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a,a+n);
  //  for(int i=0;i<n;i++)    cout<<a[i];
    lng_sub(a,n);
    return 0;
}
