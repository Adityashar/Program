#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class worker{
public:
    int cost;
    int type;
};

int partition(worker *w,int s,int e){
    int pivot=w[e].cost;
    int indexpivot=s;
    for(int i=s;i<=e;i++){
        if(w[i].cost<pivot){
            swap(w[i],w[indexpivot]);
            indexpivot++;
        }
    }
    swap(w[indexpivot],w[e]);
    return indexpivot;
}

void sort_object(worker *w,int s,int e){
    if(s>=e)    return ;
    int indexpivot=partition(w,s,e);
    sort_object(w,s,indexpivot-1);
    sort_object(w,indexpivot+1,e);
}

int main(){
    int n;
    cin>>n;
    worker *w=new worker[n];
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for(int i=0;i<n;i++){
        int p;cin>>p;
        w[i].cost=p;
    }
    for(int i=0;i<n;i++){
        int t;cin>>t;
        w[i].type=t;
    }
    sort_object(w,0,n-1);
    for(int i=0;i<n;i++){
        if(w[i].type==1)
            v1.push_back(w[i].cost);
        else if(w[i].type==2)
            v2.push_back(w[i].cost);
        else if(w[i].type==3)
            v3.push_back(w[i].cost);
    }
    cout<<min(v1[0]+v2[0],v3[0]);

    return 0;
}

