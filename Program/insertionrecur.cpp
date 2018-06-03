#include <iostream>
using namespace std;

void insertsort(int a[100],int n,int s)
{
    if(n<=1)    return ;
    int j,temp=a[s+1];
    for(int j=s+1;j>0;j--)
    {
        if(a[j-1]<temp) break;
        a[j]=a[j-1];
    }
    a[j]=temp;
    insertsort(a,n-1,s+1);

}

int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)  cin>>a[i];

    insertsort(a,n,0);
    for(int i=0;i<n;i++)  cout<<a[i];
    return 0;
}
