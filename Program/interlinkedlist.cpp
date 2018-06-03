#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node (int d):data(d),next(NULL){}
};

class LinkedList
{
    Node* head;

    void addinfront(int d)
    {
        Node* NewNode=new Node(d);
        NewNode->next=head;
        head=NewNode;
    }
    void addinend(int d)
    {
        if(head==NULL)
        {
            addinfront(d);return ;
        }
        Node* N=head;
        Node* NewNode=new Node (d);
        while(N->next!=NULL)
        {
            N=N->next;
        }
        N->next=NewNode;
    }
    void intersection(Node* A,Node* B)
    {

        while(A!=NULL&&B!=NULL)
        {
            if(A->data<B->data) A=A->next;
            else if(A->data>B->data) B=B->next;
            else
            {
                addinend(A->data);
                A=A->next;B=B->next;
            }
        }
    }

    Node *mergelinkedlist(Node *A,Node *B)
    {
        if(A==NULL) return B;
        if(B==NULL) return A;
        Node *NewHead;

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

    Node *findmid(Node *Root)
    {
        Node *N=Root->next;;
        Node *mid=Root;

        while(N!=NULL&&N->next!=NULL)
        {
            N=N->next->next;
            mid=mid->next;
        }
        return mid;
    }

    Node *mergesortlist(Node *Root)
    {
        if(Root==NULL||Root->next==NULL)    return Root;
        Node *mid=findmid(Root);
        Node *A=Root;
        Node *B=mid->next;
        mid->next=NULL;

        A=mergesortlist(A);
        B=mergesortlist(B);

        return mergelinkedlist(A,B);
    }
    void duplicate(Node *root)
    {
        Node *N=root;
        Node *DN;
        while(N!=NULL&&N->next!=NULL)
        {
            Node *NN=N;
            while(NN->next!=NULL)
            {
                if(N->data==NN->next->data)
                {
                        DN=NN->next;
                        NN->next=NN->next->next;
                        delete DN;
                }
                else NN=NN->next;
            }
            N=N->next;
        }
    }

public:
    LinkedList()
    {
        head=NULL;
    }
    void insertinend(int d)
    {
        addinend(d);
    }
    void inter(Node *A,Node *B)
    {
        intersection(A,B);
    }
    Node* returnhead()
    {
        return head;
    }
    void printf()
    {
        Node* N=head;
        while(N!=NULL)
        {
            cout<<N->data<<"->";
            N=N->next;
        }
        cout<<endl;
    }
    void mergesort()
    {
        head=mergesortlist(head);
    }
    void duplicatelist()
    {
        duplicate(head);
    }
};

int main()
{
    LinkedList LL,LL1,LL2;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;cin>>p;
        LL1.insertinend(p);
    }
    LL1.printf();
    LL1.mergesort();
    LL1.printf();
    LL1.duplicatelist();
    LL1.printf();
    /*cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;cin>>p;
        LL2.insertinend(p);
    }
    LL2.mergesort();
    LL2.printf();
    LL.inter(LL1.returnhead(),LL2.returnhead());
    LL.printf();
    return 0;
*/}
