#include <iostream>

using namespace std;

void pascal(int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=i;j<(n-1);j++)
        {
            cout<<" ";
        }
        int first=1,num=i,denom=1;
        for(j=0;j<=i;j++)
        {
            cout<<first<<" ";

            first*=num;
            first/=denom;
            num--;
            denom++;
        }
        cout<<endl;
    }


}

int main ()
{
    int n;
    cin>>n;
    pascal(n);

    return 0;
}
