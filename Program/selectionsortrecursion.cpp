#include <iostream>

using namespace std;

void selection(int a[100],int n,int s)
{
    if(s>=n-1) return;
    int sm=0;
    for(int i=s+1;i<n;i++)
    {
        if(a[s]>a[i])  sm=i;
    }
    swap(a[s],a[sm]);
    selection(a,n,s+1);

}

int main()
{
    int a[100],n;
    cin>>n;

    for(int i=0;i<n;i++)    cin>>a[i];

    selection(a,n,0);
    for(int i=0;i<n;i++)    cout<<a[i];

    return 0;
}
