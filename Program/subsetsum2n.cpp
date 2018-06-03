#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

unordered_map<int,int> map1;
list<int> *l;
void subset_sum(int a[],int n,int sum){
    int t=0;
    l=new list<int>[n];
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & 1<<j)
             // cout<<a[j];
                l[i].push_back(a[j]);
        }
    }

    for(int i=0;i<(1<<n);i++){
        int sum_list=0;
        for(auto ip=l[i].begin();ip!=l[i].end();ip++){
            sum_list+=*ip;
        }
        if(sum==sum_list){
            for(auto ip=l[i].begin();ip!=l[i].end();ip++){
                cout<<*ip<<"  ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n,sum;cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    cin>>sum;
    subset_sum(a,n,sum);
    return 0;
}
