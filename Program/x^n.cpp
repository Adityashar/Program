#include <iostream>

using namespace std;
int power(int x,int n)
{
    if(n<=1)    return x;

    if(n%2!=0) return x*power(x,n/2)*power(x,n/2);
    else return power(x,n/2)*power(x,n/2);

}

int main()
{
    int x,n;
    cin>>x>>n;

    cout<<power(x,n);

    return 0;
}
