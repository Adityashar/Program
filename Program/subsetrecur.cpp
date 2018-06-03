#include <iostream>
using namespace std;

void print(int a[100],int s,int i,int k)
{
    cout<<a[s];
    cout<<a[i];
    cout<<endl;
    /*
    cout<<a[s];
    for(int j=0;j<k-1;j++)
    {
            cout<<a[j];

    }
    cout<<endl;
    /*
    if(i>=k-1)    return;
    cout<<a[i];
    print(a,s,i+1,k);
    cout<<endl;
*/}


void subset(int a[100],int n,int s,int k)
{
    if(s>=n-1)    return;
    for(int i=0;i<=n-k;i++)
    {
        if(s!=i)
        print(a,s,i,k);

    }
    subset(a,n,s+1,k);

}


int main()
{
    int n;cin>>n;int a[100];
    for(int i=0;i<n;i++)    cin>>a[i];
    int k;
    cin>>k;
    subset(a,n,0,k);

    return 0;
}
