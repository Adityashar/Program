#include <iostream>

using namespace std;

int fact(int n)
{   int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}

int ncr(int n ,int r)
{
    int val=fact(n)/(fact(n-r)*fact(r));
    return val;

}

void pattern(int n)

{
        int i,j;

        for(i=0;i<n;i++)
        {
            for(j=1;j<(n-i);j++)
            {
                cout<<" ";
            }
            for(j=0;j<=i;j++)
            {
                cout<<ncr(i,j)<<" ";
            }
            cout<<endl;
        }

}


int main()
{
    int  n;
    cin>>n;
    pattern(n);

    return 0;
}
