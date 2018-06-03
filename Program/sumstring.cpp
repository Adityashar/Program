#include <iostream>
#include <cstring>

using namespace std;

int sum(char str[100],int s)
{
        if(str[s]=='\0')    return 0;
        return (str[s]-'0'+sum(str,s+1));
}

int main()
{
    char str[100];
    cin.getline(str,100);
    cout<<sum(str,0);
    return 0;
}
