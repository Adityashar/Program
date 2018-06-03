#include <iostream>
#include <stack>
using namespace std;
stack <int>st;
class Node
{
public:
    int data;
    Node *next;
    Node (int d):data(d),next(NULL){}
};
class LinkedList
{
    Node *head;
public:
    LinkedList(){head=NULL;}

     void insertatfront(int d)
    {
        Node *NewNode=new Node(d);
        NewNode->next=head;
        head=NewNode;
    }
    void insertatend(int d)
    {
        Node *NewNode= new Node(d);
        if(head==NULL)
        {
            insertatfront(d);return;
        }
        Node *N=head;
        while(N->next!=NULL)
        {
            N=N->next;
        }
        N->next=NewNode;
    }
    void addinstack()
    {
        Node *N=head;
        while(N!=NULL)
        {
            st.push(N->data);
            N=N->next;
        }
    }
    bool palindrome()
    {
        Node *N=head;
        while(N!=NULL)
        {
            if((st.top())!=(N->data)) return false;
            st.pop();
            N=N->next;
        }
        return true;
    }
    void printL()
    {
        Node *N=head;
        while(N!=NULL)
        {
            cout<<N->data<<"->";
            N=N->next;
        }
        cout<<endl;
    }
    void showstack()
    {
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
};
int main()
{
    LinkedList L;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;cin>>p;
        L.insertatend(p);
    }
    L.addinstack();
    L.printL();
    L.showstack();
    //if(L.palindrome())    cout<<"YES";
   // else cout<<"NO";
}
