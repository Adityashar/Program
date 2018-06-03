#include <iostream>

using namespace std;


int main()

{
    int a=100,b=3;
    float c;
    c=float(a/b);
    cout<<c;  ///Implicit Type Conversion
    char ch='A',ch1='B';

    cout<<int(ch);
    cout<<ch+ch1;
    cout<<ch+3;
    cout<<char(ch+3);

    int i=5,j,k;

    cout<<i;
    j=i++; ///b=++a;
    cout<<i<<j;
    return 0;
}
