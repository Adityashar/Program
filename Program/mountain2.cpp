#include <iostream>

using namespace std;

void mount(int n)
{

    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<j;
        }
        for(j=1;j<=(2*n-1-2*i);j++)
        {
            cout<<" ";

        }
        for(j=i;j>0;j--)
        {
            if(j!=4)
                cout<<j;
        }
        cout<<endl;
    }

}

int main()

{
    int n;
    cin>>n;
    mount(n);
    return 0;
}
