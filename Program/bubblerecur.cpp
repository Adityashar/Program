#include <iostream>

using namespace std;

void bubble(int a[100],int n)
{
        if(n<=1)
        {
            return;
        }
        int j=0;
        for(;j<n-1;j++)
        {
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
        bubble(a,n-1);

}

int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];

       bubble(a,n);
    for(int i=0;i<n;i++)    cout<<a[i];
    return 0;
}
