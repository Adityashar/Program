#include <iostream>
#include <string.h>

using namespace std;

void ispallindrome(char str[100])
{

    int i=0,j=strlen(str)-1;
    bool check=true;

    while(i<j)
    {

        if(str[i]!=str[j])
        {
            check=false;
            break;
        }
        i++;j--;

    }
    if(check)   cout<<"Pallindrome";
    else cout<<"Not";


}

int main()
{
    char str[100];
    char ch,delim='\n';
    int i=0;

    ch=cin.get();

    while(ch!='\n')
    {
        str[i]=ch;
        i++;
        ch=cin.get();


    }
    str[i]='\0';

    ispallindrome(str);



    return 0;
}
