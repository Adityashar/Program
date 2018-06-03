#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    stack <int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    cout<<S.top();S.pop();
    cout<<S.top();S.pop();
    S.push(5);
    cout<<S.top();

    queue <int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    cout<<Q.front();Q.pop();
    cout<<Q.front();Q.pop();
    Q.push(5);
    cout<<Q.front();
}
