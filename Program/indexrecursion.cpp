#include <iostream>
#include <cstring>

using namespace std;

int findn1(int a[100], int n,int l,int cnt)
{
    if(n==0)    return -1;

    if(a[0]==l) return cnt;

    return findn1(a+1,n-1,l,cnt+1);


}

int findn2(int a[100], int n,int s,int l)
{
    if(s>=n)    return -1;

    if(a[s]==l) return s;

    return findn2(a,n,s+1,l);

}
int findn3(int a[100], int n,int l)
{
    if(n==0)    return -1;

    if(a[0]==l) return 0;

    int res=findn3(a+1,n-1,l);

    if(res==-1) return -1 ; else return res+1;
}

int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];

    int l;
    cin>>l;
    cout<<findn1(a,n,l,0);
    cout<<findn2(a,n,0,l);
    cout<<findn3(a,n,l);
    return 0;
}
