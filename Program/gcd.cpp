#include <iostream>
using namespace std;
int main() {

    int n,m,a[100],b[100];
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++)    cin>>b[i];


    int sum=0,i=n-1,j=m-1,k=0,temp[100]={0};

    while(i>=0&&j>=0)
    {
        sum=a[i]+b[j];
        if(sum<10)
        {
            temp[k++]=sum;
        }
        else
        {
            temp[k++]=sum-10;
            a[i-1]+=1;
        }
        i--;j--;
    }
    while(i>=0)
    {
        if(a[i-1]+b[j-1]<10)
        temp[k++]=a[i];
        else
            temp[k++]=a[i]+1;

        i--;
    }
    while(j>=0)
    {
        if(a[i-1]+b[j-1]<10)
        temp[k++]=b[j];
        else
            temp[k++]=b[j]+1;
        j--;
    }
    for(i=k-1;i>=0;i--)    cout<<temp[i]<<", ";
    cout<<"END";

}
