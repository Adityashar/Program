#include<iostream>
#include <queue>
#include <stack>
using namespace std;
stack <int>s;
template<class anyclass>
class TreeNode
{
public:
    anyclass data;
    int child_count;
    TreeNode **children;
    TreeNode(anyclass d)
    {
        data=d;
        children=NULL;
        child_count=0;
    }
};
template<class anyclass>
class GenericTree
{
    TreeNode<anyclass> *root;

    TreeNode<anyclass>* inputTree()
    {
        int d,c;
    //    cout<<"Enter the NODE DATA : ";
        cin>>d;
        TreeNode<anyclass> *Node=new TreeNode<anyclass>(d);
      //  cout<<"Enter the number of children of the NODE : ";
        cin>>c;
        Node->child_count=c;
        if(c>0)
        {
            Node->children=new TreeNode<anyclass>* [c];
            for(int i=0; i<c; i++)
            {
                Node->children[i]=inputTree();
            }
        }
        return Node;
    }
    void preorder(TreeNode<anyclass> *root)
    {
        if(root==NULL)  return;
        cout<<root->data<<" ";
        for(int i=0; i<root->child_count; i++)
        {
            preorder(root->children[i]);
        }
    }
    void postorder(TreeNode<anyclass> *root)
    {
        if(root==NULL) return;
        for(int i=0; i<root->child_count; i++)
        {
            postorder(root->children[i]);
        }
        cout<<root->data<<" ";
    }
    TreeNode<anyclass>* fillLO()
    {
        queue<TreeNode<anyclass>*> q;
        int d,c;
        cout<<"Enter the data :";
        cin>>d;
        TreeNode<anyclass> *TN=new TreeNode<anyclass>(d);
        q.push(TN);
        while(!q.empty())
        {
            TreeNode<anyclass> *t=q.front();
            q.pop();
            int c;
            cout<<"Enter the number of children for "<<t->data<<" :";
            cin>>c;
            t->child_count=c;
            if(c>0)
            {
                t->children=new TreeNode<anyclass> *[c];
                for(int i=0; i<c; i++)
                {
                    cout<<"Enter the data for children "<<i<<" : of "<<t->data;
                    cin>>d;
                    t->children[i]=new TreeNode<anyclass> (d);
                    q.push(t->children[i]);
                }
            }
        }
        return TN;
    }
    void levelorder(TreeNode<anyclass> *TN)
    {
        queue<TreeNode<anyclass>*> q;
        q.push(TN);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode<anyclass> *t=q.front();
            q.pop();

            if(t!=NULL)
            {
                cout<<t->data<<" ";
                int c=t->child_count;
                for(int i=0; i<c; i++)
                {
                    q.push(t->children[i]);
                }
            }
            else
            {
                cout<<endl;
                if(!q.empty())  q.push(NULL);
            }
        }
    }
    int getlargest(TreeNode<anyclass> *TN)
    {
        if(TN==NULL)    return 0;
        int LR=TN->data;
        for(int i=0; i<TN->child_count; i++)
        {
            int CR=getlargest(TN->children[i]);
            if(CR>LR)   LR=CR;
        }
        return LR;
    }
    int countNodes(TreeNode<anyclass> *TN)
    {
        if(TN==NULL) return 0;
        int cnt=1;
        for(int i=0; i<TN->child_count; i++)
        {
            cnt+=countNodes(TN->children[i]);
        }
        return cnt;
    }
    void nodeatlevelk(TreeNode<anyclass> *TN,int k,int lvl)
    {
        if(TN==NULL)    return ;
        if(lvl==k)
        {
            cout<<TN->data<<" ";
            return;
        }
        for(int i=0; i<TN->child_count; i++)
        {
            nodeatlevelk(TN->children[i],k,lvl+1);
        }
    }
    int getlongest(TreeNode<anyclass> *TN)
    {
        if(TN==NULL)    return 0;
        int CH,MH=0;
        for(int i=0; i<TN->child_count; i++)
        {
            CH=getlongest(TN->children[i]);
            if(CH>MH)   MH=CH;
        }
        return MH+1;
    }
    void sumatK(TreeNode<anyclass> *TN,int k,int lvl,int &sum)
    {
        if(TN==NULL)    return ;
        if(k==lvl)
        {
            sum+=TN->data;
        }
        for(int i=0; i<TN->child_count; i++)
        {
            sumatK(TN->children[i],k,lvl+1,sum);
        }
    }
    int getleaf(TreeNode<anyclass> *TN)
    {
        int cnt=0;
        if(TN==NULL)    return 0;
        if(TN->child_count==0)  return 1;
        for(int i=0; i<TN->child_count; i++)
        {
            cnt+=getleaf(TN->children[i]);
        }
        return cnt;
    }
    int summ(TreeNode<anyclass> *TN)
    {
        int sum=0;
        if(TN==NULL)    return 0;
        sum+=TN->data;
        for(int i=0; i<TN->child_count; i++)
        {
            sum+=summ(TN->children[i]);
        }
        return sum;
    }
    void addinstack(int c)
    {
        if(s.empty()|| c>s.top())
        {
            s.push(c);
            return ;
        }
        int k=s.top();
        s.pop();
        addinstack(c);
        s.push(k);
    }

    void sortstack()
    {
        if(!s.empty())
        {
            int c=s.top();
            s.pop();
            sortstack();
            addinstack(c);
        }
    }
    void getStack(TreeNode<anyclass> *TN)
    {
        if(TN==NULL)    return ;
        s.push(TN->data);
        for(int i=0; i<TN->child_count; i++)
        {
            getStack(TN->children[i]);
        }
    }
    void printdepthvalue(TreeNode<anyclass> *TN,int lvl)
    {
        if(TN==NULL)    return ;
        cout<<lvl<<" => ";
        for(int i=0;i<TN->child_count;i++)
        {
            cout<<lvl+1<<", ";
        }
        cout<<"END"<<endl;
        for(int i=0;i<TN->child_count;i++)
        {
            printdepthvalue(TN->children[i],lvl+1);
        }
    }
public:
    GenericTree()
    {
        root=NULL;
    }
    void filltree()
    {
        root=inputTree();
    }
    void printpreorder()
    {
        preorder(root);
    }
    void printpostorder()
    {
        postorder(root);
    }
    void filltreelevel()
    {
        root=fillLO();
    }
    void printlevelorder()
    {
        levelorder(root);
    }
    void showlargest()
    {
        cout<<getlargest(root);
    }
    void shownodes()
    {
        cout<<countNodes(root);
    }
    void showK(int k)
    {
        nodeatlevelk(root,k,1);
    }
    void printlongest()
    {
        cout<<getlongest(root);
    }
    void sumtK(int k)
    {
        int sum=0;
        sumatK(root,k,1,sum);
        cout<<sum;
    }
    void countleaf()
    {
        cout<<getleaf(root);
    }
    void sumnodes()
    {
        cout<<summ(root);
    }
    void seclargest()
    {
        getStack(root);
        sortstack();
        s.pop();                            ///CONDITION NEEDS TO BE ADDED IN ORDER TO INCREASE THE SPECIFICITY
        cout<<s.top();
    }
    void justlarger(int k)
    {
        int a[1000],i=0;
        getStack(root);
        sortstack();
        while(!s.empty())
        {
            a[i++]=s.top();
            s.pop();
        }
        cout<<endl;
       // for(int j=0;j<i;j++)    cout<<a[j]<<"   ";
        for(int j=0;j<i;j++)
        {
            if(k>=a[j+1] && k<a[j])
                cout<<a[j];

        }

    }
    void depthvalue()
    {
        printdepthvalue(root,0);
    }
};
int main()
{
    GenericTree <int>GT;
    GT.filltree();
  //  GT.printpreorder();
    //cout<<endl;
    //GT.printpostorder();
    //GT.printlevelorder();
    //GT.showlargest();
    //GT.shownodes();
    //GT.showK(3);
    //GT.sumtK(3);
    //GT.countleaf();
    //GT.printlongest();
    //GT.sumnodes();
    //GT.seclargest();
    //int k;cin>>k;
    //GT.justlarger(k);
    GT.depthvalue();
}
