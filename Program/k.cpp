#include <iostream>

using namespace std;

void dtob(int n)
{
    int i,j,hn=n/2+1;

    for(i=1;i<=hn;i++)
    {
        cout<<"*";
        for(j=i;j<hn;j++)
        {
            cout<<" ";

        }
        cout<<"*";
        cout<<endl;


    }
    for(i=hn;i>1;i--)
    {
        cout<<"*";
        for(j=i;j<=hn;j++)
        {
            cout<<" ";

        }
        cout<<"*";
        cout<<endl;


    }


}

int main()
{
    int n;
    cin>>n;
    dtob(n);
    return 0;
}
