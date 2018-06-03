#include<iostream>
#include <cstring>
using namespace std;

bool palindrome(char str[100],int s , int e)
{
    if(s>=e)    return true;
    return ((str[s]==str[e])&&(palindrome(str,s+1,e-1)));
}


int main() {

    char str[100];
    cin.getline(str,100);
    int l=strlen(str);

    if(palindrome(str,0,l-1))   cout<<"true";
    else cout<<"false";

	return 0;
}
