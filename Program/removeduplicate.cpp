#include <iostream>
#include <vector>
using namespace std;


int partition(int a[],int s,int e){
    int ip=s;
    int pivot=a[e];
    for(int i=s;i<e;i++){
        if(a[i]<pivot){
            swap(a[i],a[ip]);
            ip++;
        }
    }
    swap(a[ip],a[e]);
    return ip;
}

void quicksort(int a[],int s,int e){
    if(s>=e)    return;
    int ip=partition(a,s,e);
    quicksort(a,s,ip-1);
    quicksort(a,ip+1,e);
}/*
void removeduplicate(int a[],int n){
    int p,k=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        p=a[i]^a[i+1];
        if(!p)  i++;
        v.push_back(a[i]);
    }
    if(!v.empty()){
        for(auto ip=v.begin();ip!=v.end();ip++) cout<<*ip;
    }
    cout<<endl;
}*/

void removeduplicate(int a[],int n){
    int p=a[0],i=1;
    vector<int> v;
    v.push_back(p);
    while(i<n){
        int q=p^a[i];
        if(!q)  i++;
        else{
            v.push_back(a[i]);
            //cout<<a[i];
            p=a[i];
            i++;

        }
    }
    if(!v.empty()){
        for(auto ip=v.begin();ip!=v.end();ip++) cout<<*ip;
    }
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
    removeduplicate(a,n);
    return 0;
}
