#include <iostream>
using namespace std;

template <class anyclass>
class Node
{
public:
    anyclass data;
    Node *next;
    Node (anyclass d):data(d),next(NULL) {}
};
template <class anyclass>
class LinkedList
{
    Node<anyclass> *head;
public:
    LinkedList()
    {
        head=NULL;
    }

    int length()
    {
        int cnt=0;
        Node<anyclass> *N=head;
        while(N!=NULL)
        {
            N=N->next;
            cnt++;
        }
        return cnt;
    }
    void InsertAtFront(anyclass d)
    {
        Node<anyclass> *NewNode= new Node<anyclass> (d);
        NewNode->next=head;
        head=NewNode;
    }
    void insertatposition(anyclass d,int p)
    {
        Node<anyclass> *NewNode= new Node<anyclass> (d);
        Node<anyclass> *N=head;
        if(p==0)
        {
            InsertAtFront(d);
            return;
        }
        int cnt=1;
        while(cnt<p&&N->next!=NULL)
        {
            N=N->next;
            cnt++;
        }
        NewNode->next=N->next;
        N->next=NewNode;

    }
    void insertatend(anyclass d)
    {
        Node<anyclass> *NewNode= new Node<anyclass> (d);
        Node<anyclass> *N=head;
        if(head==NULL)
        {
            head=NewNode;
            return;
        }
        while(N->next!=NULL)
        {
            N=N->next;
        }
        N->next=NewNode;
    }
    void removefromfront()
    {
        Node<anyclass> *N=head;
        if(head==NULL)  return;
        head=head->next;
        delete N;

    }
    void removefromposition(int p)
    {
        if(head==NULL) return;
        if(p==1)
        {
            removefromfront();
            return;
        }
        Node<anyclass> *nodedel;
        Node<anyclass> *N=head;
        int cnt=1;
        while((cnt<p-1)&&(N->next->next!=NULL))
        {
            N=N->next;
            cnt++;
        }
        nodedel=N->next;
        N->next=nodedel->next;
        delete nodedel;
    }
    void removefromend()
    {
        Node<anyclass> *N=head;
        Node<anyclass> *delnode;
        while(N->next->next!=NULL)
        {
            N=N->next;
        }
        delnode=N->next;                       ///No need for a temporary pointer
        N->next=NULL;
        delete delnode;
    }
    void printlist()
    {
        Node<anyclass> *N=head;
        while(N!=NULL)
        {
            cout<<N->data<<"->";
            N=N->next;
        }
    }
    void bubblesort()           ///NOT WORKING
    {
        int l=length();
        for(int i=0; i<l; i++)
        {
            Node<anyclass> *cur=head;
            Node<anyclass> *prev=NULL;
            while(cur!=NULL && cur->next!=NULL)
            {
                Node<anyclass> *Next=cur->next;
                if(Next->data<cur->data)
                {
                    if(prev!=NULL) prev->next=Next;
                    else    head=NULL;
                    cur->next=Next->next;
                    Next->next=cur;
                    prev=cur;
                    cur=Next;
                }
                else
                {   ///Move to next step
                    prev=cur;
                    cur=Next;
                }
            }
        }
    }

    ///Find the mid element
    ///Find the kth element from the Last
    void midelement()
    {
        int cnt=1;int l=length();
        Node<anyclass> *ReqNode=head;
        Node<anyclass> *N=head;
        while(cnt<=l/2+1)
        {
            N=N->next;
            cnt++;
        }
        while(N!=NULL)
        {
            N=N->next;
            ReqNode=ReqNode->next;
        }
        cout<<endl<<ReqNode->data;

    }
    void lastkelement(int k)
    {
        int cnt=1;
        Node<anyclass> *ReqNode=head;
        Node<anyclass> *N=head;
        while(cnt<=k)
        {
            cnt++;
            N=N->next;
        }
        while(N!=NULL)
        {                               ///ReqNode Now would be K elements behind
            N=N->next;
            ReqNode=ReqNode->next;
        }
        cout<<endl<<ReqNode->data;
    }

    Node<anyclass> *Midpoint()
    {
        if(head==NULL|| head->next==NULL)  return head;
        Node<anyclass> *N=head->next;
        Node<anyclass> *ReqN=head;
        while(N!=NULL && N->next!=NULL)
        {
            N=N->next->next;
            ReqN=ReqN->next;
        }
        return ReqN;
    }///Merging Two LISTS
    Node<anyclass>* Merge(Node<anyclass> *a, Node<anyclass> *b)
    {
        if(a==NULL) return b;
        if(b==NULL) return a;
        Node<anyclass> * NewHead;                 ///BASIC TASK - FINDING THE HEADER OF NEW LINKED LIST
        if(a->data<b->data)
        {
            NewHead=a;
            NewHead->next=Merge(a->next,b);
        }
        else
        {
            NewHead=b;
            NewHead->next=Merge(a,b->next);
        }
        return NewHead;
    }

    Node<anyclass>* Mid(Node<anyclass> * root)
    {
        if(root==NULL || root->next==NULL)  return root;
        Node<anyclass> *N=root->next;
        Node<anyclass> *ReqN=root;
        while(N!=NULL && N->next!=NULL)
        {
            N=N->next->next;
            ReqN=ReqN->next;
        }
        return ReqN;
    }

    Node<anyclass>* MergeSortRec (Node<anyclass> *Root)
    {
        if(Root==NULL || Root->next==NULL)  return Root;
        Node<anyclass> *mid=Mid(Root);
        Node<anyclass> *a=Root;
        Node<anyclass> *b=mid->next;
        mid->next=NULL;

        a=MergeSortRec(a);
        b=MergeSortRec(b);

        return Merge(a,b);

    }

    void MergeSort()
    {
        head= MergeSortRec(head);
    }
    /*void reverselist()
    {
        Node<anyclass> *Prev=NULL;
        Node<anyclass> *cur=head;
        while(cur->next!=NULL)
        {



        }


    }*/
};
///identify a node where a cyclic linked list starts from -
///Reverse a linked list
int main()
{
    LinkedList<int> LL;
    LL.InsertAtFront(1);
    LL.InsertAtFront(2);
    LL.InsertAtFront(3);
    LL.InsertAtFront(4);
    LL.InsertAtFront(5);
    LL.insertatposition(6,4);
    LL.printlist();
    LL.insertatend(2);
    LL.insertatposition(4,10);
    LL.insertatposition(7,3);
    cout<<endl;
    LL.printlist();
    /*cout<<endl<<LL.length();
    cout<<endl;
    LL.removefromfront();
    */LL.removefromposition(3);cout<<endl;
    LL.printlist();
    /*cout<<endl;
    LL.removefromend();
    LL.printlist();/*
    LL.bubblesort();
    cout<<endl;
    LL.printlist();*/
    //LL.midelement();
    LL.lastkelement(2);
    LL.midelement();cout<<endl;
    //cout<<LL.Mid();

    LL.MergeSort();
    LL.printlist();
    return 0;
}
