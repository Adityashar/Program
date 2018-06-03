#include<queue>
#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode (int d)
    {
        data=d;
        right=NULL;
        left=NULL;
    }
};

class BinaryTree
{
    TreeNode *root;

    TreeNode *filltree()
    {
        int d,c;
        cout<<"Enter the data :";
        cin>>d;
        TreeNode *TN=new TreeNode(d);
        cout<<"Enter the number of children of "<<TN->data<<" :";
        cin>>c;
        if(c==1||c==2)
        {
            if(c==1)    TN->left=filltree();
            else
            {
                TN->left=filltree();
                TN->right=filltree();
            }
        }
        return TN;
    }
    TreeNode *filltreelevel()
    {
        queue<TreeNode*> q;
        int c,d;
        cout<<"Enter the data: ";
        cin>>d;
        TreeNode *T=new TreeNode(d);
        q.push(T);
        while(!q.empty())
        {
            TreeNode *TN=q.front();
            q.pop();
            cout<<"Childs - ";cin>>c;
            int rd,ld;
            if(c==1)
            {
                cout<<"Left- ";cin>>ld;
                TN->left=new TreeNode(ld);
                q.push(TN->left);
            }
            if(c==2)
            {
                cout<<"Left- ";cin>>ld;
                TN->left=new TreeNode(ld);
                q.push(TN->left);
                cout<<"Right- ";cin>>rd;
                TN->left=new TreeNode(rd);
                q.push(TN->left);
            }
        }
        return T;
    }
    void Inorder(TreeNode *TN)
    {
        if(TN==NULL)    return;
        Inorder(TN->left);
        cout<<TN->data<<" ";
        Inorder(TN->right);
    }
    void Preorder(TreeNode *TN)
    {
        if(TN==NULL)    return;
        cout<<TN->data<<" ";
        Preorder(TN->left);
        Preorder(TN->right);
    }
    void Postorder(TreeNode *TN)
    {
        if(TN==NULL)    return;
        Postorder(TN->left);
        Postorder(TN->right);
        cout<<TN->data<<" ";
    }
    void Levelorder(TreeNode *TN)
    {
        queue<TreeNode*> q;
        q.push(TN);q.push(NULL);
        while(!q.empty())
        {
            TreeNode *t=q.front();q.pop();
            if(t==NULL)
            {
                cout<<endl;
                if(!q.empty())  q.push(NULL);           //122241805190326070
            }
            else
            {
                cout<<t->data<<" ";
                if(t->left!=NULL) { q.push(t->left);}
                if(t->right!=NULL) {q.push(t->right);}
            }
        }
    }
public:
    BinaryTree() {root=NULL;}
    void FILLTREE()
    {
        root=filltree();
    }
    void FILLLEVELORDER()
    {
        root=filltreelevel();
    }
    void LEVELORDER()
    {
        Levelorder(root);
    }
    void inorder()
    {
        Inorder(root);
    }
    void preorder()
    {
        Preorder(root);
    }
    void postorder()
    {
        Postorder(root);
    }
};
int main()
{
    BinaryTree BT;
    BT.FILLTREE();
   // BT.FILLLEVELORDER();
    BT.preorder();
    BT.LEVELORDER();
    return 0;
}
