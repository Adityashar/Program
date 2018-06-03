#include <iostream>
#include <cstring>

using namespace std;

bool palindrome(char str[100])
{
    int i=0,j=strlen(str)-1;

    while(i<=j)
    {
        if(str[i]!=str[j])
        {
            break;
        }
        i++;j--;
    }
    if(i>j)
        return true;
    else return false;

}

int main()
{
    char str[100],ch[100];

    cin.getline(str,100);

    if(palindrome(str))
        cout<<"YES";
    else
        cout<<"Noo";


    return 0;
}
