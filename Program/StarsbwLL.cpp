#include<iostream>
#include<cstring>
using namespace std;

void addstar(char str[100],int s,char outstr[100],int pos)
{
    if(str[s]=='\0')
    {
        outstr[pos]='\0';
        //cout<<outstr[pos];
        return;
    }
    if(s==0)   outstr[pos++]=str[s];
    else if(str[s]!=str[s-1])    outstr[pos++]=str[s];
    else
    {
        outstr[pos++]='*';
        outstr[pos++]=str[s];
    }
    addstar(str,s+1,outstr,pos);
}

int main()
{
    char str[100],outstr[100];
    cin.getline(str,100);
    addstar(str,0,outstr,0);
    cout<<outstr;
    return 0;
}
