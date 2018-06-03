#include<iostream>
using namespace std;

void stockSpan(int *a,int n){
    int *span_si=new int [n];
    for(int i=0;i<n;i++){
        span_si[i]=1;
    }
    int j=1,i=n-1,k=0;
    while(i>=1){
        if(i-j>=0&&a[i-j]<a[i]){
            j++;
            span_si[k]++;
        }
        else{
            i--;k++;j=1;
        }
    }
    int *span=new int[n];
    int p=0;
    for(int i=n-1;i>=0;i--){
        span[p++]=span_si[i];
    }
    for(int i=0;i<n;i++){
        cout<<span[i];
    }
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    stockSpan(a,n);
}
