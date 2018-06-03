#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[100],ch[100];

    cin.getline(str,100);
    cin.getline(ch,100);
    int l1=strlen(str);
    int l2=strlen(ch);
    bool flag=false;
    for(int i=0;i<=l1-l2;i++)
    {   int j,k=0;
        for(j=i;j<l2;j++)
        {
            if(str[j]!=ch[k++]) break;
        }
        if(j==l2)   flag=true;
    }if(flag) cout<<ch;
    else cout<<"NOT";

    return 0;
}
