#include <iostream>

using namespace std;

int main()

{
    int i,j,a[7];
    int    n=7;
    for(i=0;i<7;i++)
    {
        cin>>a[i];
    }

    cout<<endl;

    for(i=0;i<n-1;i++)
    {
            bool flag=false;                ///Optimization of Bubble Sort / Reduces the number of iteration if another sorted array is added
        for(j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                swap(a[j+1],a[j]);
                flag=true;
            }
        }

        if(!flag)
        {
            break;
        }

    }
    for(i=0;i<n;i++)    cout<<a[i]<<" ";

    return 0;
}
