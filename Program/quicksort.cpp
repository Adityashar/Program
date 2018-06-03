#include<iostream>
#include<cstring>

using namespace std;

int partition(int a[100],int s,int e)
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

void quicksort(int a[100],int s,int e)
{
    if(s>=e)    return;
    int indexpivot=partition(a,s,e);
    quicksort(a,s,indexpivot-1);
    quicksort(a,indexpivot+1,e);
}

int main()
{
    int a[100],n;cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)    cout<<a[i];
    return 0;
}
