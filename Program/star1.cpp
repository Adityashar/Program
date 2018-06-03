#include <iostream>

using namespace std;

void star(int n)
{
    int i,j;

    for(i=1;i<=(n-1);i++)
    {
        cout<<"*"<<endl;
        for(j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

}


int main()
{
    int n;
    cin>>n;
    star(n);
    return 0;
}
