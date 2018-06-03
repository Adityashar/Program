#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

void count(char str[20])
{
    int cn1=0,cn2=0;

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='N') cn1++;
        else if (str[i]=='S') cn1--;
        else if (str[i]=='E') cn2++;
        else if (str[i]=='W') cn2--;

    }
    cout<<cn1<<"\t"<<cn2;

    if(cn1>0)
    {
        for(int i=0;i<cn1;i++)  cout<<"N";
    }
    else if(cn1<0)
    {
        for(int i=0;i>cn1;i--)  cout<<"S";
    }
     if(cn2>0)
    {
        for(int i=0;i<cn2;i++)  cout<<"E";
    }
     if(cn2<0)
    {
        for(int i=0;i>cn2;i--)  cout<<"W";
    }







}


int main()
{
    char str[20];
    gets(str);

    count(str);

    return 0;
}
