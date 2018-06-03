#include <iostream>

using namespace std;

int main()
{   int n;
    char str[100][10];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin.getline(str,100);

    }
    char ch[100];
    cin.getline(ch);
    for(int i=0;i<n;i++)
    {
        if(strcmp(str[i],ch)==0)
        {
            cout<<ch;
        }
    }


}
