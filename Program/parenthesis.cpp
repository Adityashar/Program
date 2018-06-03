#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

void print (char str[100],int s,char strout[100])
{
    static int j=0;
    if(str[s]=='\0')
    {
        strout[j]='\0';
        return ;
    }
    if(str[s]=='(')
    {
        strout[j]=str[s+j+1];
        j++;
        if(str[s+j+1]==')') return;
        print(str,s,strout);
    }
    print(str,s+1,strout);



}

int main()
{
    char str[100],strout[100];
    cin.getline(str,100);

    print(str,0,strout);
    cout<<strout;
    return 0;
}
