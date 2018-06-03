#include<iostream>
#include<queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d):data(d),left(NULL),right(NULL){}
};
class BST
{
    TreeNode *root;
    TreeNode* inputtree()
    {
        int d;
        cout<<"ENTER THE DATA :";
        cin>>d;
        TreeNode *tn=NULL;
        while(d!=-1)
        {
            tn=insert(tn,d);
            cin>>d;
        }
        return tn;
    }
    TreeNode *insert(TreeNode *TN ,int d)
    {
        if(TN==NULL)
        {
            TreeNode *TN=new TreeNode(d);
            return TN;
        }
        if(d<=TN->data) TN->left=insert(TN->left,d);
        else    TN->right=insert(TN->right,d);
        return TN;
    }
    ///HOW DO WE ADD A NEW NODE ?????
    void preorder(TreeNode *TN)
    {
        if(TN==NULL) return ;
        cout<<TN->data<<" ";
        preorder(TN->left);
        preorder(TN->right);
    }
    void postorder(TreeNode *TN)
    {
        if(TN==NULL) return ;
        postorder(TN->left);
        postorder(TN->right);
        cout<<TN->data<<" ";
    }
    void inorder(TreeNode *TN)
    {
        if(TN==NULL)    return ;
        inorder(TN->left);
        cout<<TN->data<<" ";
        inorder(TN->right);
    }
    void levelorder(TreeNode *TN)
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
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL)  q.push(t->right);
            }
            else
            {
                cout<<endl;
                if(!q.empty())  q.push(NULL);
            }
        }
    }
    TreeNode *searchtree(TreeNode *TN,int k)
    {
        if(TN==NULL||TN->data==k)   return TN;
        if(TN->data>k)  return searchtree(TN->right,k);
        else   return searchtree(TN->left,k);
    }
public:
    BST(){root=NULL;}
    void filltree()
    {
        root=inputtree();
    }
    void showpreorder()
    {
        preorder(root);
    }
    void showpostorder()
    {
        postorder(root);
    }
    void showinorder()
    {
        inorder(root);
    }
    void showlevelorder()
    {                                                   /// 50 20 40 30 60 70 80 -1
        levelorder(root);
    }
    void searcht(int k)
    {
        TreeNode *TN;
        TN=searchtree(root,k);
        cout<<TN->data;
       // if(TN->data==k) cout<<"TRUE";
       // else cout<<"FALSE";
       // if(searchtree(root,k))   cout<<"TRUE";
       // else    cout<<"FALSE";
    }
    void insertnewnode()
    {
        insertnode(root);
    }
};
int main()
{
    BST B;
    B.filltree();
    B.showlevelorder();
   // cout<<endl;
  //  int k;cin>>k;
   // B.searcht(k);

}
