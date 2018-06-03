#include <iostream>
using namespace std;

void inverse(int a[100],int m,int p)
{
        if(p>=m)    return ;

        int val=a[p];
        inverse(a,m,p+1);
        a[val]=p;
}

int main()
{
    int n,a[100],p=0;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];

    inverse(a,n,p);

    for(int i=0;i<n;i++)    cout<<a[i];

    return 0;
}

