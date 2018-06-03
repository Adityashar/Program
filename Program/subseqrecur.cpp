#include <iostream>
#include <cstring>

using namespace std;

int subseq(char ch[100],int s,string str[100])
{
    if(ch[s]=='\0')
    {
        str[0]="";
        return 1;
    }
    int cnt=subseq(ch,s+1,str);
    for(int i=0;i<cnt;i++)
    {
             str[cnt+i]=ch[s]+str[i];
    }
    return 2*cnt;
}


int main()
{
    char ch[100];
    cin.getline(ch,100);
    string str[100];
    int l=strlen(ch);
    int c=subseq(ch,0,str);cout<<c<<endl;
    for(int i=0;i<c;i++)    cout<<str[i]<<" ";
    return 0;
}
