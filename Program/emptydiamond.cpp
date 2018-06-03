#include <iostream>

using namespace std;

void hdia(int n)
{
    int i,j,hn=n/2+1;

    for(i=0;i<hn;i++)
    {

            if((i==0))
            {
                for(j=0;j<n;j++)
                {
                    cout<<" * ";
                }
            }
            else
            {
                    for(j=0;j<=(n/2-i);j++)
                    {
                        cout<<" * ";
                    }
                    for(j=1;j<=(2*i-1);j++)
                    {
                        cout<<"   ";
                    }
                    for(j=0;j<=(n/2-i);j++)
                    {
                        cout<<" * ";
                    }


            }cout<<endl;


    }

    for(i=0;i<(hn-1);i++)
    {

            if((i==(hn-2)))
            {
                for(j=0;j<n;j++)
                {
                    cout<<" * ";
                }
            }
            else
            {
                    for(j=0;j<=(i+1);j++)
                    {
                        cout<<" * ";
                    }
                    for(j=(2*hn-5);j>(2*i);j--)
                    {
                        cout<<"   ";
                    }
                    for(j=0;j<=(i+1);j++)
                    {
                        cout<<" * ";
                    }


            }
            cout<<endl;

    }


}


int main()
{
    int n;
    cin>>n;
    hdia(n);

    return 0;
}
