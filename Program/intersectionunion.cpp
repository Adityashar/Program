//intersection&union
#include<iostream>
using namespace std;

int partition(int a[100],int s,int e)
{
    int pivot=a[e];
    int pivotindex=s;
    for(int i=s;i<e;i++)
    {
        if(a[i]<pivot)
        {
            swap(a[i],a[pivotindex]);
            pivotindex++;
        }
    }
    swap(a[e],a[pivotindex]);
        return pivotindex;
}

void quicksort(int a[100],int s,int e)
{
    if(s>=e)    return;
    int pivotindex=partition(a,s,e);
    quicksort(a,s,pivotindex-1);
    quicksort(a,pivotindex+1,e);
}

void intersection(int a[100],int n1,int b[100],int n2,int c[100])
{
    int i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
        if(a[i]<b[j])i++;
        else if(a[i]>b[j])j++;
        else
        {
            c[k++]=a[i++];j++;
        }
    }
    for(int i=0;i<k;i++)   cout<<c[i];
}
void union2(int a[100],int n1,int b[100],int n2,int c[100])
{
    int i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
        if(a[i]<b[j])   c[k++]=a[i++];
        else if(b[j]<a[i])  c[k++]=b[j++];
        else
        {
            c[k++]=a[i++];j++;
        }
    }
    while(i<n1)
    {
        c[k++]=a[i++];
    }
    while(j<n2)
    {
        c[k++]=b[j++];
    }
    quicksort(c,0,k-1);cout<<endl;
    for(int i=0;i<k;i++)   cout<<c[i];
}

int main()
{
    int a[100],b[100],n1,n2,c[100];
    cin>>n1;
    for(int i=0;i<n1;i++)   cin>>a[i];
    cin>>n2;
    for(int i=0;i<n2;i++)   cin>>b[i];
    quicksort(a,0,n1-1);
    quicksort(b,0,n2-1);
    intersection(a,n1,b,n2,c);
    //union2(a,n1,b,n2,c);
    return 0;
}
