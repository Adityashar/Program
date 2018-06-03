#include <iostream>

using namespace std;

void swas(int n)
{

    int i,j,hn;
    hn=n/2+1;

    for(i=1;i<=n;i++)
    {
        if(i<hn)
        {

            if(i==1)
            {
                cout<<"*";

                for(j=0;j<(hn-2);j++)
                {
                    cout<<" ";
                }
                for(j=0;j<=(hn-1);j++)
                {
                    cout<<"*";
                }

            }

            else
            {

                cout<<"*";

                for(j=0;j<(hn-2);j++)
                {
                    cout<<" ";
                }
                cout<<"*";

            }


        }
        else if(i==hn)
        {
            for(j=0;j<n;j++)
            {
                cout<<"*";
            }
        }

        else
        {
            if(i==(n))
            {
                for(j=0;j<=(hn-1);j++)
                {
                    cout<<"*";
                }

                for(j=0;j<(hn-2);j++)
                {
                    cout<<" ";
                }
                cout<<"*";


            }

            else
            {

                for(j=0;j<=(hn-2);j++)
                {
                    cout<<" ";
                }
                cout<<"*";
                for(j=0;j<(hn-2);j++)
                {
                    cout<<" ";
                }
                cout<<"*";

            }


        }cout<<endl;

    }

}


int main()

{
    int n;
    cin>>n;
    swas(n);

    return 0;
}
