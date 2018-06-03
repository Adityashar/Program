#include <iostream>

using namespace std;

bool issort(int a[100],int n)
{
    if(n<=1)    return true;

    return ((a[n-1]>=a[n-2])&&(issort(a,n-1)));
}

int main()
{
    int a[100],n;
    cin>>n;

    for(int i=0;i<n;i++)    cin>>a[i];

    if(issort(a,n)) cout<<"YES";
    else cout<<"NOT";

    return 0;
}
