#include<iostream>
using namespace std;

template <class anyclass>
class Node
{
public:
    int data;
    Node* next;
    Node (int d):data(d),next(NULL){}
};
template <class anyclass>
class LinkedList
{
    Node<anyclass>* head;
    void insertatfront(anyclass d)
    {
        Node<anyclass> *NewNode=new Node<anyclass>(d);
        NewNode->next=head;
        head=NewNode;
    }
    void insertatp(anyclass d,int p)
    {
        if(head==NULL)
        {
            insertatfront(d);return;
        }
        Node<anyclass> *n=head;
        Node<anyclass> *NewNode= new Node<anyclass>(d);
        int cnt=1;
        while(cnt<p&&n->next!=NULL)
        {
         n=n->next;cnt++;
        }
        NewNode->next=n->next;
        n->next=NewNode;

    }
    void insertatend(anyclass d)
    {
        Node<anyclass> *NewNode= new Node<anyclass>(d);
        if(head==NULL)
        {
            insertatfront(d);return;
        }
        Node<anyclass> *N=head;
        while(N->next!=NULL)
        {
            N=N->next;
        }
        N->next=NewNode;
    }
    void mergelistiteration(Node<anyclass> *A,Node<anyclass> *B)
    {
        while(A!=NULL&&B!=NULL)
        {
            if(A->data<B->data)
            {
                addinend(A->data);
                A=A->next;
            }
            else if(A->data<B->data)
            {
                addinend(B->data);
                B=B->next;
            }
            else
            {
                addinend(A->data);A=A->next;B=B->next;
            }
        }
        while(A!=NULL)
        {
            addinend(A->data);
            A=A->next;
        }
        while(B!=NULL)
        {
            addinend(B->data);
            B=B->next;
        }

    }
    Node<anyclass> *mergelinkedlist(Node<anyclass> *A,Node<anyclass> *B)
    {
        if(A==NULL) return B;
        if(B==NULL) return A;
        Node<anyclass> *NewHead;

        if(A->data>B->data)
        {
            NewHead=B;
            NewHead->next=mergelinkedlist(A,B->next);
        }
        else
        {
            NewHead=A;
            NewHead->next=mergelinkedlist(A->next,B);
        }
        return NewHead;
    }

    Node<anyclass> *findmid(Node<anyclass> *Root)
    {
        Node<anyclass> *N=Root->next;;
        Node<anyclass> *mid=Root;

        while(N!=NULL&&N->next!=NULL)
        {
            N=N->next->next;
            mid=mid->next;
        }
        return mid;
    }

    Node<anyclass> *mergesortlist(Node<anyclass> *Root)
    {
        if(Root==NULL||Root->next==NULL)    return Root;
        Node<anyclass> *mid=findmid(Root);
        Node<anyclass> *A=Root;
        Node<anyclass> *B=mid->next;
        mid->next=NULL;

        A=mergesortlist(A);
        B=mergesortlist(B);

        return mergelinkedlist(A,B);
    }
public:
    LinkedList(){head=NULL;}
    void addinfront(anyclass d)
    {
        insertatfront(d);
    }
    void addinend(anyclass d)
    {
        insertatend(d);
    }
    void mergelist(Node<anyclass> *A,Node<anyclass>* B)
    {
        mergelistiteration(A,B);
    }
    Node<anyclass> *returnhead()
    {
        return head;
    }
    void printlist()
    {
        Node<anyclass> *N=head;
        while(N!=NULL)
        {
            cout<<N->data<<" ";
            N=N->next;
        }
    }
    void mergesort()
    {
        head=mergesortlist(head);
    }

};

int main()
{
    LinkedList <int>LL1;
    LinkedList <int>LL2;
    LinkedList <int>LL3;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;cin>>p;
        LL1.addinend(p);
    }
    LL1.mergesort();//LL1.printlist();
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;cin>>p;
        LL2.addinend(p);
    }
    LL2.mergesort();//LL2.printlist();
    LL3.mergelist(LL1.returnhead(),LL2.returnhead());
    LL3.mergesort();
    LL3.printlist();
}
