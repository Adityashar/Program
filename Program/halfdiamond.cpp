#include <iostream>

using namespace std;

void half(int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=i;j<(n-1);j++)
        {
            cout<<" ";

        }
        for(j=0;j<=i;j++)
        {
            cout<<"*";
        }cout<<endl;
    }
    for(i=0;i<(n-1);i++)
    {
        for(j=0;j<=i;j++)
        {
            cout<<" ";

        }
        for(j=(n-1);j>i;j--)
        {
            cout<<"*";
        }cout<<endl;
    }

}

int main()
{
    int n;
    cin>>n;
    half(n);

    return 0;
}
