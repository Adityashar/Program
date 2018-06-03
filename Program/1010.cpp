#include <iostream>

using namespace std;

void binary(int n)
{

    int i,j,p=1;

    for(i=0;i<n;i++)
    {   p=1;
        for(j=0;j<=i;j++)
        {
            if(i%2==0)
            {
                     cout<<p<<" ";
                     p=1-p;
            }
            else
            {
                cout<<(1-p)<<" ";
                p=1-p;


            }
        }cout<<endl;
    }
}


int main()

{
    int n;
    cin>>n;
    binary(n);

    return 0;
}
