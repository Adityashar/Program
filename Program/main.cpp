#include <iostream>
#include <stdio.h>
using namespace std;

void digit(int n)
{
    int i,rem,sum1=0,sum2=0;

    i=1;
    int temp = n;
    while(temp!=0)
    {
            if(i%2!=0)
            {
                sum1+=temp%10;
                temp=temp/10;

            }
            else
            {
                sum2+=temp%10;
                temp/=10;
            }
            i++;
    }
    cout<<sum1<<endl<<sum2;
}

int main()
{
    int n;
    cin>>n;
    digit(n);

    return 0;
}
