///Take as input N, the size of array. Take N more inputs and store that in an array.
///Take as input M, a number. Write a recursive function which selection sorts the given array. Print all the values in the sorted array.
#include <iostream>
using namespace std;

void selectionsort(int a[100],int n)
{
    if(n<=1)return;
    int j,cm=0;
    for(j=1;j<n;j++)
    {
        if(a[j]<a[j+1])
        {
            cm=j;
        }
    }
    swap(a[cm],a[0]);
    selectionsort(a+1,n-1);


}

int main()
{
    int n ,a[100];
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];

    selectionsort(a,n);
    for(int i=0;i<n;i++)    cout<<a[i];
    return 0;
}
