#include <iostream>

using namespace std;

void swastika(int n)
{
    int i,j,hn=n/2+1;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {

            if((i==hn)||(j==hn))//||((i==1)&&(j>hn))||((i==n)&&(j<hn))||((i<hn)&&(j==1))||((j==n)&&(i>hn)))
            {
                cout<<"*";
            }
            else
            {
                    cout<<" ";
            }
        }cout<<endl;
    }



}

int main()

{
    int n;
    cin>>n;
    swastika(n);

    return 0;
}
