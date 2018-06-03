#include <iostream>

using namespace std;

void mergef(int a[100],int n,int b[50],int m)
{
    int i,j,k;
    i=m-1; j=n-1;k=m+n-1;

    while (i>=0 || j>=0){
        if (a[i]>b[j]){
            a[k]=a[i];
            k--;i--;
        }
        else {
            a[k]=b[j];
            j--;k--;
        }
    }

   while (j>=0)
    {
        a[k]=b[j];
        j--;k--;
    }


}


int main()
{
    int a[100],b[50],n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<m;i++)    cin>>b[i];

    mergef(a,n,b,m);

    for(int i=0;i<n+m;i++)    cin>>a[i];

    return 0;
}
