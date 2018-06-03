#include <iostream>

using namespace std;

void rhombus(int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            cout<<" ";
        }
        if((i==0)||i==(n-1))
        {
            for(j=0;j<n;j++)
            {
                cout<<"*";
            }
        }
        else
        {
                cout<<"*";
                for(j=0;j<(n-2);j++)
                {
                    cout<<" ";
                }
                cout<<"*";

        }
        cout<<endl;
    }

}


int main()
{
    int n;
    cin>>n;
    rhombus(n);

        return 0;
}
