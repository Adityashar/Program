#include <iostream>

using namespace std;

void armstrong(int n)
{
    int rem,i,j,sum=0,temp;

    for(i=2; i<=n; i++)
    {
        temp=i;rem=0;sum=0;

        while(temp>0)
        {
            rem=temp%10;
            sum+=rem*rem*rem;
            temp/=10;
        }
        if(sum==i)
            cout<<i<<endl;;
    }
}

int main()
{
    int n;
    cin>>n;
    armstrong(n);
    return 0;
}
