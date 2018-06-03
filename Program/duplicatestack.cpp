#include<iostream>
#include<stack>
using namespace std;

bool duplicate(char str[100])
{
    stack <char>s;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]!=')') s.push(str[i]);
        else
        {
            char top=s.top();
            s.pop();
            if(top=='(') return true;
            else
            {
                while(top!='(')
                {
                    top=s.top();
                    s.pop();
                }
            }
        }
    }
    return false;
}

int main()
{
    char str[100];
    int n;
    cin>>n;
    cin.ignore();   ////important to consider
    for(int i=0; i<n; i++)
    {
        cin.getline(str,100);
        if(duplicate(str)) cout<<"Duplicate Found"<<endl;
        else cout<<"No Duplicates Found "<<endl;
    }
        return 0;
}
