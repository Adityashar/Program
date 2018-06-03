#include <iostream>
#include <cmath>
using namespace std;

int primefactor(int n)
{
    int i=2;
    for(;i<=sqrt(n);i++){
        while(n%i==0){
            n/=i;
            if(n==1)    break;
        }
    }
    if(n==1) return i;
    else return n;
}

int main()
{
    int n;
    cin>>n;
    int p=primefactor(n);
    cout<<p;
    return 0;
}
