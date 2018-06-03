#include <iostream>
using namespace std;

template <class anyclass>
class Node
{
    public:
    anyclass data;
    Node *next;
    Node (anyclass d):data(d),next(NULL){}
};

template <class anyclass>
class LinkedList
{
    Node<anyclass> *head;

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
    void deletefromend()
    {
        Node<anyclass> *N=head;
        while(N->next!=NULL)
        {
            N=N->next;
        }
        delete N->next;
        N->next=NULL;
    }
    void deletefromfront()
    {
        Node<anyclass> *N=head;
        if(head==NULL)  return;
        head=head->next;
        delete N;
    }
    void deletefromposition(int p)
    {
        Node<anyclass> *N=head;
        if(head==NULL)  return;
        if(p==1)
        {
            deletefromfront();return;
        }
        int cnt=1;
        while(cnt<p-1&&N->next->next!=NULL)
        {
            N=N->next;cnt++;
        }
        Node<anyclass> *Nd;
        Nd=N->next;
        N->next=Nd->next;
        delete Nd;
    }
    void printL()
    {
        Node<anyclass> *N=head;
        while(N!=NULL)
        {
            cout<<N->data<<"->";
            N=N->next;
        }
        cout<<endl;
    }
    Node<anyclass>* printmidelement()
    {
        Node<anyclass> *N1=head->next;
        Node<anyclass> *N2=head;

        while(N1!=NULL&&N1->next!=NULL)
        {
            N1=N1->next->next;
            N2=N2->next;
        }
        return N2;
    }
    Node<anyclass>* printkthelement(int k)
    {
        Node<anyclass> *N=head;
        Node<anyclass> *Nd=head;
        int cnt=1;
        while(cnt<=k)
        {
            N=N->next;cnt++;
        }
        while(N!=NULL)
        {
            N=N->next;
            Nd=Nd->next;
        }
        return Nd;
    }
    void bubblesortlist()
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
    //Merge sort

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
    void reverseloop(Node<anyclass> *Root)
    {
        Node<anyclass> *prev=NULL;
        Node<anyclass> *cur=Root;
        Node<anyclass> *Nxt=NULL;
        while(cur!=NULL)
        {
            Nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Nxt;
        }
        head=prev;
    }
    Node<anyclass>* reverserecur(Node<anyclass> *Root)
    {
        if(Root==NULL||Root->next==NULL)    return Root;
        Node<anyclass> *Newhead=Root;
        Newhead=reverserecur(Root->next);
        Root->next->next=Root;
        Root->next=NULL;
        return Newhead;
    }
    Node<anyclass>* selectionrecur(Node<anyclass>* root)
    {
        if(root==NULL||root->next==NULL)    return root;
        Node<anyclass> *NewHead=NULL;
        Node<anyclass> *temp=root;
        Node<anyclass> *cur=root->next;
        while(cur!=NULL)
        {
            if(temp->data>cur->data)
                temp->data=cur->data;
            cur=cur->next;
        }
        swapnode(root,root->data,temp->data);

        NewHead=selectionrecur(root->next);
        return NewHead;
    }

    void swapnode(Node<anyclass>* root , int x, int y)
    {
        Node<anyclass> *curX=root;
        Node<anyclass> *prevX=NULL;
        Node<anyclass> *curY=root;
        Node<anyclass> *prevY=NULL;

        if (x==y)   return;
        while(curX->data!=x)
        {
            prevX=curX;
            curX=curX->next;
        }
        while(curY->data!=y)
        {
            prevY=curY;
            curY=curY->next;
        }
        if(curX==NULL||curY==NULL)  return;

        if(prevX!=NULL) prevX->next=curY;
        else root=curY;

        if(prevY!=NULL) prevY->next=curX;
        else root=curX;

        Node<anyclass> *temp;
        temp=curX->next;
        curX->next=curY->next;
        curY->next=temp;

    }
    Node<anyclass> *getLargest()
    {
        Node<anyclass> *L=head;
        Node<anyclass> *N=head->next;
        while(N!=NULL)
        {
            if(L->data<N->data)
            {
                swapnode(head,L->data,N->data);
            }
            N=N->next;
        }
        return L;
    }
    anyclass getSecLargest(Node<anyclass> *root)
    {
        Node<anyclass> *first;
        Node<anyclass> *second;
        first=second=root;
        Node<anyclass> *N=root;
        while(N!=NULL)
        {
            if(N->data>first->data)
            {
                second->data=first->data;
                first->data=N->data;
            }
            else if(N->data>second->data && N->data != first->data)
                second->data=N->data;
            N=N->next;
        }
        return second->data;
    }

public:
        LinkedList(){head=NULL;}
        void addinfront(anyclass d)
        {
            insertatfront(d);
        }
        void addinposition(anyclass d,int p)
        {
            insertatp(d,p);
        }
        void addinend(anyclass d)
        {
            insertatend(d);
        }
        void removefromposition(int p)
        {
            deletefromposition(p);
        }
        void printlist()
        {
            printL();
        }
        void printmid()
        {
            cout<<printmidelement()->data;
        }
        void printk(int k)
        {
            cout<<printkthelement(k)->data;
        }
        void bubblesort()
        {
            bubblesortlist();
        }
        void mergesort()
        {
            head=mergesortlist(head);
        }
        void reverselist()
        {
            reverseloop(head);
        }
        void reverselistrecur()
        {
            head=reverserecur(head);
        }
        void selectionsortrecur()
        {
            head=selectionrecur(head);
        }

        void swapnodelist(int k1,int k2)
        {
            swapnode(head,k1,k2);
        }
        void showLargest()
        {
            cout<<getLargest()->data;
        }
        void showsecLargest()
        {
            cout<<getSecLargest(head);
        }
};

int main()
{
    LinkedList<int> LL;
    int n,x,y;cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;cin>>p;
        LL.addinend(p);
    }
    //LL.bubblesort();
    LL.printlist();
    LL.mergesort();
    LL.printlist();
    cin>>x>>y;
    LL.swapnodelist(x,y);
    LL.printlist();
    LL.selectionsortrecur();
    LL.printlist();
    LL.showLargest();
    LL.showsecLargest();
    /*LL.reverselistrecur();
    LL.printlist();
    LL.removefromposition(3);
    LL.printlist();
    LL.printmid();
    LL.printk(1);
*/
    return 0;
}
