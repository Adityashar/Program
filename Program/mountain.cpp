#include <iostream>

using namespace std;

void mount(int n)
{
    int i,j,k=0;

    for(i=1;i<=n;i++)
    {
        if(i==n)
        {
            for(j=1;j<=(2*n-1);j++)
            {
                if(j<=n)
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
        }
        else{
        for(j=1;j<=(i);j++)
        {
            cout<<j<<" ";
        }
        for(j=(2*n-3);j>=(2*i-1);j--)
        {
            cout<<"  ";
        }
        for(j=0;j<i;j++)
        {
            cout<<(i-j)<<" ";
        }}
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
