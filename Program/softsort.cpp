#include<iostream>
using namespace std;

int fact(int t)
{
    if(t<=0)    return 1;
    return t*fact(t-1);
}

long func(int t)
{
    int n=fact(t);
    int total=n+2*(n-1);
    return total;
}

int main()
{
    long n;
    cin>>n;
    for(long i=0;i<n;i++)
    {

        long t;
        cin>>t;
        long l=func(t);
        cout<<l+5<<endl;
    }
    return 0;
}
