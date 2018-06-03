#include <iostream>
#include <cstring>

using namespace std;

void decode(char str[100],int s,char outstr[100],int pos)
{
    if(str[s]=='\0')
    {
        outstr[pos]='\0';
        cout<<outstr<<endl;
        return;
    }
    if(str[s]=='0') return;

    outstr[pos]=str[s]-'1'+'A';
    decode(str,s+1,outstr,pos+1);

    if(str[s+1]!='\0')
    {
        int n=(str[s]-'0')*10+(str[s+1]-'0');
        if(n<=26)
        {
            outstr[pos]=n+'A'-1;
            decode(str,s+2,outstr,pos+1);
        }
    }
}

int main()
{
    char str[100],outstr[100];
    cin.getline(str,100);

    decode(str,0,outstr,0);
    return 0;
}
