#include <iostream>

using namespace std;

void sear(int a[100][100],int n,int m,int l)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {
                if(l==a[i][j])
                    cout<<"Number found at : (" <<i<<","<<j<<")";

            }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[100][100];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    int l;
    cin>>l;
    sear(a,n,m,l);


    return 0;
}
