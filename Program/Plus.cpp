#include <iostream>
#include <stdio.h>

using namespace std;

void pluks(int n)
{
    int i,j;

    for(i=0;i<(2*n+1);i++)
    {
        if(i==n)
        {
            for(j=0;j<(2*n-1);j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        else{
            for(j=0;j<(n-1);j++)
            {
                cout<<" ";

            }
            cout<<"*"<<endl;
        }

    }

}

int main()
{
    int n;
    cin>>n;
    pluks(n);
    return 0;

}
