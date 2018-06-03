#include<iostream>
using namespace std;

void sorting(int a[1000],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
    //for(i=0;i<n;i++)    cout<<"\t"<<a[i];
    //cout<<endl;



}

int main() {

    int a1[1000],a2[1000],n,k=0,t[100];
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a1[i];
    for(int i=0;i<n;i++)    cin>>a2[i];
    sorting(a1,n);sorting(a2,n);
    int i=0,j=0;

    while(i<n && j<n)
    {
        if(a1[i]<a2[j]) i++;
        else if(a2[j]<a1[i])    j++;
        else
        {   t[k++]=a2[j++];i++;
        }
    }cout<<"[";
    for(i=0;i<k-1;i++)  cout<<t[i]<<", ";
    cout<<t[k-1]<<"]";
	return 0;
}
