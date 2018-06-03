#include <iostream>

using namespace std;

void vpat(int n)
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(i-1);j++)
        {
            cout<<" ";
        }
        cout<<"*";
        for(j=1;j<(2*n-2*i);j++)
        {
            cout<<" ";
        }
        if(i!=n) cout<<"*";
        cout<<endl;
    }


}

int main()
{
    int n;
    cin>>n;
    vpat(n);
    return 0;
}
