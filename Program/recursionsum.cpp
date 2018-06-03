#include <iostream>

using namespace std;

int sum(int a[100],int n)
{
    if(n<=1)    return a[0];

    return (a[0]+sum(a+1,n-1));

}

int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];

    cout<<sum(a,n);

    return 0;
}
