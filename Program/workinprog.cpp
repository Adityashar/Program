#include <iostream>

using namespace std;

int inv(int a[50],int n)
{
    int j;
    int temp;
    for(int i=0,j=n-1;i<n/2;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        return temp;

    }

}

int main()

{
    int n,a[100],j,y[50];

    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        y[i]=inv(a,n);
    }

    //y=inv(a,n);
    for(int i=0;i<n;i++)    cout<<y[i]<<endl;


    return 0;
}


