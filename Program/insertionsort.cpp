#include <iostream>

using namespace std;

int main()
{

    int a[7]={31,3,21,10,15,13,27},n=7;

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        int j;
        for(j=i;j>0;j--)
        {
            if(a[j-1]<temp) break;
            a[j]=a[j-1];
        }
        a[j]=temp;
    }

    for(int i=0;i<n;i++)    cout<<a[i]<<" ";
    return 0;
}
