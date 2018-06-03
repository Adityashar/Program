#include <iostream>
using namespace std;

void mergearray(int a[100],int s,int e)
{
    int arr[100];
    for(int i=s;i<=e;i++)   arr[i]=a[i];
    int mid=(s+e)/2;

    int i=s,j=mid+1,k=s;
    while(i<=mid&&j<=e)
    {

        if(arr[i]<arr[j])   a[k++]=arr[i++];
        else    a[k++]=arr[j++];
    }
    while(i<=mid)
        a[k++]=arr[i++];
    while(j<=e)
        a[k++]=arr[j++];
}

void mergesort(int a[100],int s,int e)
{
    if(s>=e)    return;
    int mid=(s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    mergearray(a,s,e);

}

int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)    cout<<a[i];

    return 0;
}
