#include<iostream>
#include<cstring>
using namespace std;

void removingx(string str,int s,string outstr,int pos,int &cnt)
{
    if(str[s]=='\0')
    {
        outstr[pos]='\0';
        return;
    }
    if(str[s]!='x') outstr[pos++]=str[s];
    else cnt++;
    removingx(str,s+1,outstr,pos,cnt);

}

int main()
{
    string  str;
    string strout;
    cin>>str;
    int cnt=0;
    removingx(str,0,strout,0,cnt);

    for(int i=0;i<cnt;i++)
    {
        strout=strout+'x';
    }
    cout<<strout;
}
