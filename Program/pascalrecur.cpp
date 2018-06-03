#include <iostream>

using namespace std;

int fact(int n)
{
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}

int nCr(int n ,int i)
{
    int val=fact(n)/(fact(n-i)*fact(i));
    return val;
}


void pascal(int n)
{
    if(n<=0)    return;

    pascal(n-1);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<nCr(n,i)<<" ";
    }

}

int main()
{
    int n;
    cin>>n;
    pascal(n);

    return 0;
}
