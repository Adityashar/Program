#include <iostream>
using namespace std;

int multiply(int n,int m)
{
    if(m==0)    return 0;
    return (n+multiply(n,m-1));

}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<multiply(n,m);

    return 0;
}
