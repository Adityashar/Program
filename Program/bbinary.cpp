#include <iostream>
#include <math.h>

using namespace std;

void binary(int n)
{
    int p=1,temp=n,num=0,d;

    while(temp>0)
    {
        d=temp%2;
        num+=d*p;
        p*=10;
        temp/=2;
    }
    cout<<num;
}
void octal(int n)
{

    int temp=n,p=1,d=0;
    int num=0;
    while(temp>0)
    {
        d=temp%8;
        num=num+d*p;
        p*=10;
        temp/=8;
    }
    cout<<num;

}
void decimal(int n)
{

    int temp=n,i=0,d=0;
    int sum=0;
    while(temp>0)
    {
        d=temp%10;
        sum+=d*(pow(2,i));
        i++;
        temp/=10;
    }
    cout<<sum;


}


int main ()
{
    int num;
    cin>>num;
    binary(num);
    octal(num);
    int num2;cout<<endl;
    cin>>num2;
    decimal(num2);
    return 0;
}
