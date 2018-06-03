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
        for(j=0;j<n;j++)
        {
            if((i==0)||(j==0)||(i==(n-1))||(j==(n-1)))
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
    rhombus(n);
    return 0;
}
