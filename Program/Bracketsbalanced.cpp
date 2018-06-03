#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack <int>s;
    char str[100];
    cin.getline(str,100);

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            s.push(str[i]);
        else if(str[i]==')')
        {
            if(s.top()!='('){cout<<"NOT BALANCED";return 0;}
            s.pop();
        }
        else if(str[i]=='}')
        {
            if(s.top()!='{'){cout<<"NOT BALANCED";return 0;}
            s.pop();
        }
        else if(str[i]==']')
        {
            if(s.top()!='['){cout<<"NOT BALANCED";return 0;}
            s.pop();
        }
    }
    if(s.empty())   cout<<"BALANCED";
    else cout<<"NOT BALANCED";
    return 0;
}
