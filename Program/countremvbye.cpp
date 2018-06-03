#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

void removehi(char str[100],int s,char outstr[100],int pos)
{
    static int cnt=0;
    if(str[s]=='\0')
    {
        outstr[pos]='\0';
        return ;
    }
    if(str[s+1]!='\0')
    {
        if(str[s]=='h'&&str[s+1]=='i')  s++;
        else  outstr[pos++]=str[s];
    }
    removehi(str,s+1,outstr,pos);
}

int counthi(char str[100],int s,char outstr[100],int pos)
{
    static int cnt=0;
    if(str[s]=='\0')
    {
        outstr[pos]='\0';
        //cout<<outstr[pos];
        return 0;
    }
    if(str[s+1]!='\0')
    {
        if(str[s]=='h'&&str[s+1]=='i')
        {
            outstr[pos++]='b';
            outstr[pos++]='y';
            outstr[pos++]='e';
            cnt++;
            s++;
        }

        else
        {
            outstr[pos++]=str[s];
        }
    }
    counthi(str,s+1,outstr,pos);
    return cnt;

}

int main()
{
    char str[100],outstr[100],strout[100];
    cin.getline(str,100);
    int k=counthi(str,0,outstr,0);
    removehi(str,0,strout,0);
    cout<<k<<endl<<strout<<endl<<outstr;
    return 0;
}
