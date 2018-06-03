#include <iostream>
using namespace std;

template <class anyclass>
class Node
{
public:
    anyclass data;
    Node* next;
    Node (anyclass d):data(d),next(NULL){}

};
template <class anyclass>
class LinkedList                              ///chain k last->next null h
{
    Node<anyclass> *head;
public:
    LinkedList(){head=NULL;}
    void InsertAtFront(anyclass d)
    {
        Node<anyclass> *N=new Node<anyclass> (d);
        ///N.next=head;
        N->next=head;
        head=N;             ///????

    }
    void insertatposition(anyclass d , int p)
    {
        if(p==0)
        {
            InsertAtFront(d);
            return;
        }
        Node<anyclass>*NewNode=new Node<anyclass> (d);
        int cnt=1;
        Node<anyclass> *n=head;
        while(cnt<p && n->next!=NULL)
        {
            n=n->next;cnt++;
        }
        NewNode->next=n->next;
        n->next=NewNode;

    }
    void insertatend(anyclass d)
    {
        Node<anyclass>*NewNode=new Node<anyclass> (d);
        if(head==NULL)
        {
            head=NewNode;return;
        }
        Node<anyclass> *n=head;
        while(n->next!=NULL)
        {
            n=n->next;
        }
        n->next=NewNode;

    }
    int length()
    {

    }
    /*void removefromfront()
    {

    }
    void removefromend()
    {

    }
    void removefromposition(int p)
    {

    }*/
    void printlist()
    {
        Node<anyclass> *N=head;
        while(N!=NULL)
        {
            cout<<N->data<<"->";
            N=N->next;
        }
    }
};
int main()
{
    LinkedList<int> LL;
    LL.InsertAtFront(1);
    LL.InsertAtFront(2);
    LL.InsertAtFront(3);
    LL.InsertAtFront(4);
    LL.InsertAtFront(5);
    LL.printlist();
    LL.insertatend(2);
    LL.insertatposition(55,3);
    cout<<endl;
    LL.printlist();
    return 0;
}
