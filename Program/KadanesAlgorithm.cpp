#include<iostream>
#include<list>
using namespace std;

list<int> l;
int MAX_SUM(int a[],int n){
    int max_iteration,max_global;
    max_iteration=max_global=a[0];
    for(int i=1;i<n;i++){
        max_iteration=max(max_iteration+a[i],a[i]);
        if(max_iteration>max_global){
            max_global=max_iteration;
            l.push_back(i);
        }
    }
    for(int i=l.front();i<=l.back();i++){
        cout<<a[i]<<"  ";
    }
    return max_global;
}

int main(){
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=0;i<n;i++)    cin>>a[i];

    cout<<endl<<MAX_SUM(a,n);
}
