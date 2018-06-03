#include <iostream>
#include <cstring>
using namespace std;

void numto(int n)
{
    char strings[][100]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(n==0)    return;
int d;
    numto(n/10);
    d=n%10;
    cout<<" "<<string0s[d];

}

int main()
{
    int n;
    cin>>n;

    numto(n);

    return 0;
}
