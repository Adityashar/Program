#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

int counthi(char str[100],int s)
{
    string st;
    static int cnt=0;
    if(str[s]=='\0')    return 0;

    if(str[s+1]!='\0')
    {
        if(str[s]=='h'&&str[s+1]=='i')
            cnt++;
        counthi(str,s+1);
    }

    return cnt;

}

int main()
{
    char str[100];
    cin.getline(str,100);
    int k=counthi(str,0);
    cout<<k;
    return 0;
}
