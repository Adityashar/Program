#include<iostream>

using namespace std;
template <class anyclass>
class Node
{
    public:
    anyclass data;
    Node* next;
    Node (anyclass d):data(d),next(NULL){}
    //friend class stack; /// Use Private Data Members of NODE class
};

template <class anyclass>
class stack
{
    Node<anyclass> *head;
    int currentsize;
public:
    stack()
    {
        head=NULL;
        currentsize=0;
    }
    ~stack()
    {
        while(!isEmpty())
        {
            pop();
        }
    }
    void push(anyclass d)
    {
        currentsize++;
        Node<anyclass> *NewNode= new Node<anyclass> (d);
        NewNode->next=head;
        head=NewNode;
    }
    anyclass pop()
    {
        currentsize--;
       // if(head==NULL)  return ;
        Node<anyclass> *delnode=head;
        head=head->next;
        return delnode->data;
        delete delnode;
    }
    anyclass top() const            ///READ-ONLY FUNCTIONS I.E. IT WONT CHANGE THE DATA MEMBERS
    {
        if(head!=NULL)
        {
            return head->data;
        }
    }
    bool isEmpty()
    {
        if(head==NULL) return true;
        else return false;
    }
    int size()
    {
        return currentsize;
    }
};
int main()
{
    stack <string>S;
    S.push("A");
    S.push("cd");
    S.push("C");
    cout<<S.pop();
    cout<<S.pop();
    S.push("E");
    cout<<S.pop();
}
