#include <iostream>

using namespace std;

void k(int n)
{
    int i,j,ei,ej,k,hn=n/2+1;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i<=hn)   ei=i; else ei=n-i+1;
            if(j<=hn)   ej=j; else ej=n-j+1;

            /*for(int k=0;k<hn;k++)
            {
                if(ei==(1+k)||ej==(1+k))
                {
                    cout<<hn-k;
                }
            }*/


            if(ei==1||ej==1)    cout<<hn;
            else if(ei==2||ej==2)   cout<<hn-1;
            else if(ei==3||ej==3)   cout<<hn-2;
            else if(ei==4||ej==4)   cout<<hn-3;
            else cout<<hn-4;

        }cout<<endl;


    }

}


int main()
{
    int n;
    cin>>n;
    k(n);

    return 0;
}
