#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    cout << endl;

   int i,j;

   for(i=0;i<n;i++)
   {
       for(j=i;j<(n-1);j++)
       {
           cout<<" ";
       }
       int k=1,num=i,denom=1;

       for(j=0;j<=i;j++)
       {
           cout<<k<<" ";
           k*=num;
           k/=denom;
           num--;
           denom++;
       }
        cout<<endl;
   }
   for(i=0;i<n;i++)
   {
       for(j=0;j<=i;j++)
       {
           cout<<" ";
       }
       int k=1 ,num=n/2-i+1,denom=1;

       for(j=(n-1);j>(i);j--)
       {
           cout<<k<<" ";
           k*=num;
           k/=denom;
           num--;
           denom++;
       }
        cout<<endl;
   }


    return 0;
}
