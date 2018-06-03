#include <iostream>

using namespace std;

void num(int n)
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if((j==1)||(i==j))
            {
                cout<<"1";
            }
            else
            {
                cout<<i%2;
            }


        }cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    num(n);

    return 0;
}
