#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

void smallestsum(vector<int> v1,vector<int> v2,int n,int k){
    int *index2=new int [n];
    for(int i=0;i<n;i++){
        index2[i]=0;
    }
    while(k>0){
        int min_sum=INT_MAX;
        int min_index=0;

        for(int i=0;i<n;i++){
            if(index2[i]<n && (v1[i]+v2[index2[i]] < min_sum))
            {
                min_sum=v1[i]+v2[i];
                min_index=i;
            }
        }
        cout<<v1[min_index]<<"\t"<<v2[index2[min_index]]<<endl;
        index2[min_index]++;
        k--;
    }
}

int main(){
    vector<int> v1;
    vector<int> v2;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int p;cin>>p;
        v1.push_back(p);
    }
    for(int i=0;i<n;i++){
        int p;cin>>p;
        v2.push_back(p);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    smallestsum(v1,v2,n,3);
}
