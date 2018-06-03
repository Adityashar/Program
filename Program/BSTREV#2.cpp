#include<iostream>
#include<queue>
using namespace std;

class TreeNode
{public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int d):data{d},left(NULL),right(NULL){}
};

class BST
{
    TreeNode *root;

    /*TreeNode *filltree()
    {
        int d;
        cout<<"ENTER THE DATA :";
        cin>>d;
        TreeNode *tn=NULL;
        tn=insertnode(tn,d);
        return tn;
    }*/
    TreeNode *filltree()
    {
        int n,i=0;
        cout<<"ENter the number of elements :";
        cin>>n;
        TreeNode *tn=NULL;
        while(i<n)
        {
            int d;
            cout<<"Enter the data :";
            cin>>d;
            tn=insertnode(tn,d);
            i++;
        }
        return tn;
    }
    TreeNode *insertnode(TreeNode* tn ,int d)
    {
        if(tn==NULL)
        {
            TreeNode* tn=new TreeNode(d);
            return tn;
        }
        if(tn->data>d)  tn->left=insertnode(tn->left,d);
        else    tn->right=insertnode(tn->right,d);
        return tn;
    }
    void showlevel(TreeNode *TN)
    {
        queue<TreeNode *> q;
        q.push(TN);q.push(NULL);
        while(!q.empty())
        {
            TreeNode *t=q.front();
            q.pop();
            if(t!=NULL)
            {
                cout<<t->data<<" ";
                if(t->left!=NULL)q.push(t->left);
                if(t->right!=NULL)q.push(t->right);
            }
            else
            {
                cout<<endl;if(!q.empty()) q.push(NULL);
            }
        }
    }
    void DISPLAY(TreeNode *TN)
    {
        queue<TreeNode*> q;
        q.push(TN);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *t=q.front();
            q.pop();
            if(t!=NULL && t->left!=NULL &&t->right!=NULL)
            {
                cout<<t->left->data<<" => "<<t->data<<" <= "<<t->right->data<<endl;
                if(t->left!=NULL)
                {
                    q.push(t->left);
                }
                if(t->right!=NULL)
                {
                    q.push(t->right);
                }
            }
            else if(t!=NULL && t->left!=NULL &&t->right==NULL)
            {
                cout<<t->left->data<<" => "<<t->data<<" <= END"<<endl;
                if(t->left!=NULL)
                {
                    q.push(t->left);
                }
            }
            else if(t!=NULL && t->right!=NULL && t->left==NULL)
            {
                cout<<"END => "<<t->data<<" <= "<<t->right->data<<endl;
                if(t->right!=NULL)
                {
                    q.push(t->right);
                }
            }
            else if(t!=NULL && t->right==NULL && t->left==NULL)
            {
                cout<<"END => "<<t->data<<" <= END"<<endl;
            }
            else
            {
                if(!q.empty())  q.push(NULL);
            }
        }
    }
    TreeNode *LeastAncestor(TreeNode *TN,int n1,int n2)
        {
            if(TN==NULL||(TN->data>=n1&&TN->data<=n2)||(TN->data<=n1&&TN->data>=n2))
                return TN;
            if(TN->data>n1&&TN->data>n2) return LeastAncestor(TN->left,n1,n2);
            if(TN->data<n1&&TN->data<n1) return LeastAncestor(TN->right,n1,n2);
        }/*
        TreeNode *DELETENODE(TreeNode *TN,int d)
        {
            if(TN==NULL)    return TN;
            if(d<TN->data)  TN->left=DELETENODE(TN->left,d);
            else if(d>TN->data) TN->right=DELETENODE(TN->right,d);
            else//(TN->data=d)
            {
                if(TN->left!=NULL)
                {
                    TreeNode *temp=TN->left;
                    delete TN;
                    return temp;
                }
                else if(TN->right!=NULL)
                {
                    TreeNode *temp=TN->right;
                    delete TN;
                    return temp;
                }///if left and right are present
                TreeNode *Temp=nextnode(TreeNode *TN,d);
                TN->data=Temp->data;
                TN->right=delete(TN ->right,Temp->data);
            }
        }*/
        TreeNode* nextnode(TreeNode *TN,d)
        {
            TreeNode *temp=TN;
            while(temp->data)

        }
public:
    BST (){root=NULL;}
    void input()
    {
        root=filltree();
    }
    void levelorder()
    {
        showlevel(root);
    }
    void Display()
    {
        DISPLAY(root);
    }
    void LCA(int n1,int n2)
    {
        cout<<LeastAncestor(root,n1,n2)->data;
    }
    void deletenode(int d)
    {
        root=DELETENODE(root,d);
    }
  /*  void showinorder()
    {
        inorder(root);
    }*/
};
int main()
{
    BST B;
    B.input();
    B.levelorder();
 //   cout<<"1";
    //B.Display();
    int n1,n2,n;
    //cin>>n1>>n2;
    //B.LCA(n1,n2);
    B.deletenode(n);
//    B.showinorder();
}
