#include <queue>
#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode ** children;
    int child_count;
    TreeNode(int d)
    {
        data=d;
        children=NULL;
        child_count=0;
    }
};
class MaxOutput
{
    TreeNode *node;
    int maxsum;
    int sum;
};

class GenericTree
{
    TreeNode *root;

    TreeNode* takeinput()
    {
        int d,c;
        cout<<"Enter the Node Data :";cin>>d;
        TreeNode* n= new TreeNode (d);
        cout<<"Enter the Children Count for "<<d<<" :";cin>>c;
        n->child_count=c;
        if(c>0)
        {
            n->children=new TreeNode *[c];
            for(int i=0;i<c;i++)
            {
                n->children[i]=takeinput();
            }
        }
        return n;
    }

    void preorder(TreeNode *n)
    {
        if(n==NULL) return;
        cout<<n->data<<", ";

        for(int i=0;i<n->child_count;i++)
        {
            preorder(n->children[i]);
        }
    }

    TreeNode * FillTreeLO()
    {
        queue<TreeNode*> q;
        int d;
        cout<<"Enter the data :";cin>>d;
        TreeNode *n=new TreeNode(d);
        q.push(n);

        while(!q.empty())
        {
            TreeNode *tn=q.front();
            q.pop();
            int c;
            cout<<"Enter the number of children for Node "<<tn->data<<" :";cin>>c;
            tn->child_count=c;
            if(c>0)
            {
                tn->children= new TreeNode *[c];
                for(int i=0;i<c;i++)
                {
                    cout<<"Enter data of child#"<<i<<" of "<<tn->data<<" :";cin>>d;
                    tn->children[i]=new TreeNode (d);
                    q.push(tn->children[i]);
                }
            }
        }
        return n;
    }
    void levelorder(TreeNode* n)
    {
        queue<TreeNode*> q;
        q.push(n);q.push(NULL);

        while(!q.empty())
        {
            TreeNode *tn=q.front();
            q.pop();

            if(tn!=NULL)
            {
                cout<<tn->data<<" ";

                int c=tn->child_count;
                for(int i;i<c;i++)
                {
                    q.push(tn->children[i]);
                }
            }
            else
            {
                cout<<endl;
                if(!q.empty()) q.push(NULL);
            }
        }
    }
    int getLargest(TreeNode *n)
    {
       int Largest=n->data;
       for(int i=0;i<n->child_count;i++)
       {
           int childlargest=getLargest(n->children[i]);
           if(childlargest>Largest) Largest=childlargest;
       }
       return Largest;
    }
    void preorderwithlevel(TreeNode *n,int lvl)
    {
        if(n==NULL) return;
        cout<<n->data<<"("<<lvl<<"), ";

        for(int i=0;i<n->child_count;i++)
        {
            preorderwithlevel(n->children[i],lvl+1);
        }
    }

    int getHeight(TreeNode* n)
    {
        if(n==NULL) return 0;
        int CH,MH=0;
        for(int i=0;i<n->child_count;i++)
        {
            CH=getHeight(n->children[i]);
            if(CH>MH)   MH=CH;
        }
        return MH+1;
    }
    int getCount(TreeNode *n)
    {
        if(n==NULL) return 0;
        int cnt=1;    ///FOR THE ROOT.
        for(int i=0;i<n->child_count;i++)
        {
            cnt+=getCount(n->children[i]);
        }
        return cnt;
    }

    void getPRINTATK(TreeNode *n,int k,int lvl)
    {
        if(n==NULL) return;
        if(lvl==k) { cout<<n->data<<" "; return ;}
        for(int i=0;i<n->child_count;i++)
        {
            getPRINTATK(n->children[i],k,lvl+1);
        }
    }
    void sumatK(TreeNode *n,int k,int lvl,int &sum)
    {
        if(n==NULL) return;
        if(lvl==k)
        {//cout<<n->data<<" ";
            sum+=n->data;
            return;
        }
        for(int i=0;i<n->child_count;i++)
        {
            sumatK(n->children[i],k,lvl+1,sum);
        }
    }

    MaxOutput Maxsum(TreeNode *n)
    {
        MaxOutput mout;
        if(n==NULL)
        {
            mout.node=NULL;
            mout.sum=0;
            mout.maxsum=0;
            return mout;
        }
        MaxOutput *coArr=new MaxOutput[tn->child_count];
        int mySum=tn->data;
        for(int i=0;i<n->child_count;i++)
        {
            coArr[i]=Maxsum(n->children[i]);
            mySum+=coArr[i].sum;
        }

        mout.node=n;
        mout.sum=mySum;
        mout.maxsum=mySum;
        for(int i=0;i<n->child_count;i++)
        {
            if(coArr[i].maxsum>mout.maxsum)
                mout=coArr[i];
        }
        mout.sum=mySum;

    }
public:
    void FillTree()
    {
        root=takeinput();
    }

    void printpreorder()
    {
        preorder(root);
    }
    void FillTreeLevel()
    {
        root=FillTreeLO();
    }
    void printlevelorder()
    {
     //  levelorder(root);
    }
    void PrintLargest()
    {
        cout<<getLargest(root);
    }
    void prelevel()
    {
        preorderwithlevel(root,0);
    }
    int height()
    {
        return getHeight(root);
    }
    int count()
    {
        return getCount(root);
    }
    void PRINTATK(int k)
    {
        getPRINTATK(root,k,0);
    }
    int sumatk(int k)
    {
        int cnt=0;
        sumatK(root,k,0,cnt);
        return cnt;
    }
};


int main()
{
    GenericTree gt;
    //gt.FillTree();

    gt.FillTreeLevel();
   // gt.printlevelorder();
    cout<<endl;
    gt.printpreorder();
    gt.PrintLargest();
    gt.prelevel();
    cout<<gt.height();
    cout<<gt.count();
    //gt.PRINTATK(2);
    cout<<gt.sumatk(2);
    return 0;
}
