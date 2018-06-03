#include <iostream>
using namespace std;

class TreeNode
{
    public:
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int d):data(d),right(NULL),left(NULL){}
};
class BST
{
    TreeNode *root;

    TreeNode* takeinput()
    {
        int d;
        cin>>d;
        TreeNode *tn=NULL;
        while(d!=-1)
        {
            tn=insert(tn,d);
            cin>>d;
        }
        return tn;
    }
    TreeNode *insert(TreeNode* tn,int d)
    {
        if(tn==NULL)
        {
            TreeNode *n=new TreeNode(d);
            return n;
        }
        else
        {
            if(d<=tn->data)
            {
                tn->left=insert(tn->left,d);
            }
            else
            {
                tn->right=insert(tn->right,d);
            }
        }
        return tn;
    }
    void preorder(TreeNode *tn)
    {
        if(tn==NULL)    return;
        cout<<tn->data<<"  ";
        preorder(tn->left);
        preorder(tn->right);
    }
    void inorder(TreeNode *tn)
    {
        if(tn==NULL)    return;
        inorder(tn->left);
        cout<<tn->data<<"  ";
        inorder(tn->right);
    }
    void postorder(TreeNode *tn)
    {
        if(tn==NULL)    return;
        postorder(tn->right);
        postorder(tn->left);
        cout<<tn->data<<"  ";
    }
    /*TreeNode* searchtree(TreeNode *tn,int d)
    {
        if(tn==NULL)    return;
    }
*/
public:
    BST(){root=NULL;}
    void insertinput()
    {
        root=takeinput();
    }
    void preorderprint()
    {
        preorder(root);
    }
    void inorderprint()
    {
        inorder(root);
    }
    void postorderprint()
    {
        postorder(root);
    }
    /*void searchnode(int d)
    {
        TreeNode *n=searchtree(root,d);
        cout<<n->data;
    }*/
};
int main()
{
    BST B;
    B.insertinput();
    B.preorderprint();
    cout<<endl;
    B.inorderprint();
    cout<<endl;
    B.postorderprint();
    return 0;
}
