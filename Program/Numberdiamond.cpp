#include <iostream>

using namespace std;

void number(int n)
{
    int i,j,k;

    for(i=1;i<=n;i++)
    {
        for(j=i;j<n;j++)
        {
            cout<<"  ";

        }
        k=i;
        for(j=1;j<=i;j++)
        {
            cout<<k<<" ";
            k++;
        }
        k=k-2;
        for(j=1;j<i;j++)
        {
            cout<<k<<" ";
            k--;
        }
cout<<endl;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<"  ";

        }
        k=n-i;
        for(j=n;j>i;j--)
        {
            cout<<k<<" ";
            k++;
        }
        k=k-2;
        for(j=(n-1);j>i;j--)
        {
            cout<<k<<" ";
            k--;
        }
cout<<endl;
    }


}

int main()
{
    int n;
    cin>>n;
    number(n);

    return 0;
}
