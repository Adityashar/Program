#include <iostream>

using namespace std;

int main()
{
    int i,j,a[7]={31,3,20,15,13,27};
    int n=6;
    for(i=0;i<n;i++)    cout<<a[i]<<"\t";

    for(i=0;i<n-1;i++)
    {
        int cur=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[cur])
            {
                cur=j;
            }
        }
        int temp=a[cur];
        a[cur]=a[i];
        a[i]=temp;

    }
    for(i=0;i<n;i++)    cout<<a[i];

    return 0;
}
