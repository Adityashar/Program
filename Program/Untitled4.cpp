#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int partition(int *a,int s,int e)
{
    int pivot=a[e];
    int indexpivot=s;
    for(int i=s;i<e;i++)
    {
        if(a[i]<pivot)
        {
            swap(a[i],a[indexpivot]);
            indexpivot++;
        }
    }
    swap(a[indexpivot],a[e]);
    return indexpivot;
}

void quicksort(int *a,int s,int e)
{
    if(s>=e)    return;
    int indexpivot=partition(a,s,e);
    quicksort(a,s,indexpivot-1);
    quicksort(a,indexpivot+1,e);
}
int main(){
    int n;
    cin>>n;
    int *cost=new int[n];
    int *type=new int[n];
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    for(int i=0;i<n;i++){
        cin>>type[i];
    }
    quicksort(cost,0,n-1);

    for(int i=0;i<n;i++){
        if(type[i]==1)
            v1.push_back(cost[i]);
        else if(type[i]==2)
            v2.push_back(cost[i]);
        else if(type[i]==3)
            v3.push_back(cost[i]);
    }
    for(int i=0;i<v1.size();i++)    cout<<v1[i]<<" ";
    cout<<endl;
    for(int i=0;i<v2.size();i++)    cout<<v2[i]<<" ";
    cout<<endl;
    for(int i=0;i<v3.size();i++)    cout<<v3[i]<<" ";
    cout<<min(v1.front()+v2.front(),v3.front());

    return 0;
}

