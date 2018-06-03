#include <iostream>
using namespace std;

bool palindrome(int k)
{
    if(k<=0)    return true;

    return palindrome(k/10);
}

int main()
{
    int n;

    cout<<"Enter the number of test cases :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k=0;
        cin>>k;
        if(pallindrome(k))cout<<"YES";
        else cout<<"NO";
    }

    return 0;
}
