#include <iostream>

using namespace std;

void number(int n)
{
    int i,j,k;

    for(i=1;i<=n;i++)
    {
        for(j=i;j<=(n-1);j++)
        {
            cout<<"  ";
        }
        k=i-1;
        for(j=1;j<=(2*i-1);j++)
        {

            if(j<=i)
            {
                    k++;
                    cout<<k<<" ";

            }
            else
            {
                k--;
                cout<<k<<" ";
            }

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
