#include <iostream>

using namespace std;

void fibo(int n)
{

    int i,j,num;
    int first=0,second=1;
    num=first+second;
    cout<<first<<" "<<second<<" ";
    while(num<=n)
    {
        cout<<num<<" ";

        first=second;
        second=num;
        num=first+second;


    }
    if(second==n)
    {
        cout<<"Y";
    }

}

int main()
{
    int n;
    cin>>n;
    fibo(n);
    return 0;
}
