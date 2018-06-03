#include<iostream>
using namespace std;

bool palin(int a[100],int s,int e)
{
    if(s>=e) return false;

    if(a[s]==a[e])  return true;
    palin(a,s+1,e-1);

}

int main()
{
    int n, a[100];
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];

    if(palin(a,0,n-1))  cout<<"true";
    else cout<<"false";

    return 0;
}
