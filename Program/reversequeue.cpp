#include <iostream>
#include <queue>
using namespace std;

queue <int>q1;

void reversequeue(int n)
{
    if(n<=0)    return ;
    int k=q1.front();
    q1.pop();
    reversequeue(n-1);
    q1.push(k);
}

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;cin>>p;
        q1.push(p);
    }
    reversequeue(n);
    while(!q1.empty())
    {
        cout<<q1.front()<<"     ";
        q1.pop();
    }cout<<"END";
}
