#include <iostream>
using namespace std;

int brecur(int a[100],int s,int e,int l)
{
    int mid = (s+e)/2;
    //if(mid<=1)  return 1;

    if(a[mid]>l)   e=mid-1;
    else if(a[mid]<l)   s=mid+1;
    else
            return mid;
    brecur(a,s,e,l);
}

int main()
{
    int n,a[100],l;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    cin>>l;
    cout<<brecur(a,0,n,l);

    return 0;
}
