#include <iostream>

using namespace std;

template <class anyclass>
class Node
{public:
    anyclass data;
    Node *next;
    Node (anyclass d):data(d),next(NULL){}
};
template <class anyclass>
class LinkedList
{
    Node<anyclass> *head;
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
        Node<anyclass> *NewNode= new Node<anyclass> (d);
        NewNode->next=head;
        head=NewNode;
    }
    void addinend(anyclass d)
    {
        if(head==NULL)
        {
            addinfront(d);return;
        }
        Node<anyclass> *N=head;
        Node<anyclass> *NewNode=new Node<anyclass>(d);
        while(N->next!=NULL)
        {
            N=N->next;
        }
        N->next=NewNode;
    }
    Node<anyclass> *returnhead()
    {
        return head;
    }

    void mergelist(Node<anyclass> *A,Node<anyclass> *B)
    {
        head=Merge(A,B);
    }
    Node<anyclass> *Merge(Node<anyclass> *A,Node<anyclass> *B)
    {
        if(A==NULL)
        {
            while(B!=NULL)
            {
                addinend(B->data);
                B=B->next;
            }
            return head;
        }
        if(B==NULL)
        {
            while(A!=NULL)
            {
                addinend(A->data);
                A=A->next;
            }
            return head;
        }
        Node<anyclass> *NewHead;
        if(A->data<B->data)
        {
            NewHead=A;
            addinend(NewHead->data);
            NewHead=Merge(A->next,B);

        }
        else
        {
            NewHead=B;
            addinend(NewHead->data);
            NewHead=Merge(A,B->next);

        }
        return NewHead;
    }
    int length()
    {
        int l=0;
        Node<anyclass> *N=head;
        while(N!=NULL)
        {
            N=N->next;l++;
        }
        return l;
    }

    void bubblesort()
    {
        int l=length();
        for(int i=0;i<l;i++)
        {
            Node<anyclass> *cur=head;
            Node<anyclass> *prev=NULL;

            while(cur!=NULL&&cur->next!=NULL)
            {
                Node<anyclass> *Nxt=cur->next;
                if(Nxt->data<cur->data)
                {
                    if(prev!=NULL)  prev->next=Nxt;
                    else head=NULL;
                    cur->next=Nxt->next;
                    Nxt->next=cur;
                }
                prev=cur;
                cur=Nxt;
            }
        }
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

        int n;cin>>n;

        for(int i=0;i<n;i++){
        int p,n1;cin>>n1;
         LinkedList <int>LL;
    LinkedList <int>LL1;
    LinkedList <int>LL2;
        for(int j=0;j<n1;j++)
        {
            cin>>p;
            LL1.addinend(p);
        }
        int n2;cin>>n2;
        for(int j=0;j<n2;j++)
        {
            cin>>p;
            LL2.addinend(p);
        }
        LL1.mergesort();
        LL2.mergesort();
        //LL1.printlist();
        //LL2.printlist();
        LL.mergelist(LL1.returnhead(),LL2.returnhead());
        LL.printlist();

        }
    return 0;
}
