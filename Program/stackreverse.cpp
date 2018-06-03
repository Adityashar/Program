#include<iostream>
#include <stack>
#include <cstring>
using namespace std;
string ns;
stack <int>s;
void addinstack(int t)
{
    if(s.size()==0)
    {
        s.push(t); return;
    }
    int c=s.top();
    s.pop();
    addinstack(t);
    s.push(c);
}

void reversestack(int n)
{
    if(n<=0)    return;
    int t=s.top();
    s.pop();
    reversestack(n-1);
    addinstack(t);
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;cin>>p;
        s.push(p);
    }
    reversestack(n);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
