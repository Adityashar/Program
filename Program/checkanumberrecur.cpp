#include <iostream>

using namespace std;

bool check(int a[100],int n,int l)
{
    if(n==0) return false;

    return ((l==a[0])||check(a+1,n-1,l));


}

int main()
{
    int a[100],n;
    cin>>n;
    int l;

    for(int i=0;i<n;i++)    cin>>a[i];
    cin>>l;
    if(check(a,n,l)) cout<<"YES";
    else cout<<"NOT";

    return 0;
}
