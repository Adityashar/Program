#include <iostream>
using namespace std;

void selectionsort(int a[100],int n)
{
    if(n<=1)    return;
    int i,cur=0;
    for(i=1;i<n;i++)
    if(a[0]>a[i]) cur=i;
    swap(a[cur],a[0]);
    selectionsort(a+1,n-1);

}

int main() {
 int n;
 cin>>n;
 int a[100];
 for(int i=0;i<n;i++)   cin>>a[i];

 selectionsort(a,n);

 for(int i=0;i<n;i++)   cout<<a[i];

 return 0;
}
