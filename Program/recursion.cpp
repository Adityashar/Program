#include <iostream>

using namespace std;

int factorial(int n)
{
    //base case
    if(n==1)    return 1;           ///BADA AND CHHOTA FUNCTION ///BADA : code to be written for only the nth test case CHHOTA :Recursive call to be made for (n-1)th term
    int cs=factorial(n-1);
    return n*cs;
}
void print1 (int n)
{
    if(n<=0)    return;

    print1 (n-1);
    cout<<n<<endl;

}
void print2(int n)
{
    if(n<=0)    return ;

    cout<<n<<endl;
    print2 (n-1);

}
int fibonnaci(int n)
{
    if(n==0) return 0;///BASE CASE #1  ///Required to stop the recursive function

    if(n==1) return 1;///BASE CASE #2
     return fibonnaci(n-1)+fibonnaci(n-2); ///FIBONNACI RECURSION CALL

}
int main()
{
    int n;
    cin>>n;

    int k=factorial(n);
    cout<<k<<endl;

    print1(n);
    print2(n);
    int j=fibonnaci(n);
    cout<<endl<<j;
    return 0;

}
