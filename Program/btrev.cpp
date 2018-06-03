#include<cstring>
#include<queue>
#include<stack>
#include <iostream>
using namespace std;

stack<int> s;
queue<int> q1;
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
    /*
    TreeNode *filtreelevel()
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
            cout<<"Childs - ";
            cin>>c;
            int rd,ld;
            if(c==1)
            {
                cout<<"Left- ";
                cin>>ld;
                TN->left=new TreeNode(ld);
                q.push(TN->left);
            }
            if(c==2)
            {
                cout<<"Left- ";
                cin>>ld;
                TN->left=new TreeNode(ld);
                q.push(TN->left);
                cout<<"Right- ";
                cin>>rd;
                TN->left=new TreeNode(rd);
                q.push(TN->left);
            }
        }
        return T;
    }*/
    TreeNode* filltreelevel()
    {
        queue<TreeNode*>    q;
        int d;
        cout<<"Enter the data :";
        cin>>d;
        TreeNode *TN=new TreeNode(d);
        q.push(TN);
        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();
            int rd,ld;
            cin>>ld>>rd;
            if(ld!=-1)
            {
                t->left=new TreeNode (ld);
                q.push(t->left);
            }
            if(rd!=-1)
            {
                t->right=new TreeNode (rd);
                q.push(t->right);
            }
        }
        return TN;
    }
    TreeNode* InAndPre(int In[100],int Pre[100],int s,int e)
    {
        static int preindex=0;
        if(s>e)    return NULL;
        TreeNode *t=new TreeNode(Pre[preindex++]);
        if(s==e)   return t;
        int inindex=searchin(In,s,e,t->data);
        t->left=InAndPre(In,Pre,s,inindex-1);
        t->right=InAndPre(In,Pre,inindex+1,e);
    }
    TreeNode* InAndPost(int In[100],int Pre[100],int s,int e)
    {
        static int preindex=e;
        if(s>e)    return NULL;
        TreeNode *t=new TreeNode(Pre[preindex--]);
        if(s==e)   return t;
        int inindex=searchin(In,s,e,t->data);
        t->right=InAndPost(In,Pre,inindex+1,e);
        t->left=InAndPost(In,Pre,s,inindex-1);             //  7 4 5 2 6 7 3 1 7 4 2 5 1 6 3 7
    }
    int searchin(int In[100],int s,int e, int d)
    {
        for(int i=s; i<=e; i++)
        {
            if(In[i]==d)    return i;
        }
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
        q.push(TN);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *t=q.front();
            q.pop();
            if(t==NULL)
            {
                cout<<endl;
                if(!q.empty())  q.push(NULL);           //1 2 2 2 4 1 8 0 5 1 9 0 3 2 6 0 7 0
            }
            else
            {
                cout<<t->data<<" ";
                if(t->left!=NULL)
                {
                    q.push(t->left);
                }
                if(t->right!=NULL)
                {
                    q.push(t->right);
                }
            }
        }
    }
    TreeNode *LCA(TreeNode *TN,int n1,int n2)
    {
        if(TN==NULL)    return NULL;
        if(TN->data==n1||TN->data==n2)  return TN;

        TreeNode *Left_TN=LCA(TN->left,n1,n2);
        TreeNode *Right_TN=LCA(TN->right,n1,n2);
        if(Left_TN && Right_TN) return TN;
        if(Left_TN!=NULL)   return Left_TN;
        else return Right_TN;
    }
    ///print spiral
    void alternateorder(TreeNode *TN)
    {
        if(TN==NULL)    return ;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s2.push(TN);
        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                TreeNode *temp=s1.top();
                s1.pop();
                cout<<temp->data<<" ";

                if(temp->right) s2.push(temp->right);
                if(temp->left) s2.push(temp->left);
            }
            while(!s2.empty()){
                TreeNode *temp=s2.top();
                s2.pop();
                cout<<temp->data<<" ";

                if(temp->left) s1.push(temp->left);
                if(temp->right) s1.push(temp->right);
            }
        }
    }
    void arraylist(TreeNode *TN){
        queue<TreeNode *> q;
        q.push(TN);q.push(NULL);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t==NULL){
                cout<<"],[";
                if(!q.empty())q.push(NULL);
            }
            else{
                cout<<t->data<<", ";
                if(t->left!=NULL)    q.push(t->left);
                if(t->right!=NULL)   q.push(t->right);
            }
        }
    }
    void countLeaf(TreeNode* TN)
    {
        int cnt=0;
        if(TN==NULL)    return;
        if(TN->left==NULL &&TN->right==NULL)
        {
            cout<<TN->data<<" ";
        }
        countLeaf(TN->left);
        countLeaf(TN->right);
    }
  /*  TreeNode* min_node(TreeNode *TN)
    {
        if(TN==NULL)    return TN;
        TreeNode *MIN=TN;
        TreeNode *MIN_L=min_node(TN->left);
        TreeNode *MIN_R=min_node(TN->right);
        if(MIN_L->data<MIN->data)   MIN->data=MIN_L->data;
        if(MIN_R->data<MIN->data)   MIN->data=MIN_R->data;
        return MIN;
    }
    int min_node(TreeNode* Root)
{
    if (Root == NULL)   return INT_MAX;
    int res = Root->data;
    int lres = min_node(Root->left);
    int rres = min_node(Root->right);
    if (lres < res) res = lres;
    if (rres < res) res = rres;
    return res;
}*/
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

    TreeNode* inputtree(TreeNode *TN)
    {
        int d;
        cin>>d;
        cin.ignore();
        TN=new TreeNode(d);

        string l;
        cin>>l;
        if(l=="true")
            TN->left=inputtree(TN->left);
        string r;
        cin>>r;
        if(r=="true")
            TN->right=inputtree(TN->right);
        return TN;
    }
    int sum_node(TreeNode *TN)
    {
        int l=0,r=0;
        if(TN==NULL)  return 0;
        if(TN->left==NULL && TN->right==NULL)   return TN->data;
        l=sum_node(TN->left);
        r=sum_node(TN->right);
        return l+r+TN->data;
    }
    bool identicaltree(TreeNode *A,TreeNode *B)
    {
        if(A==NULL && B==NULL)  return true;
        if(A->data==B->data){
            if(identicaltree(A->left,B->left) && identicaltree(A->right,B->right))
                return true;
        }
        return false;
    }
    void sibling(TreeNode *TN)
    {
        if(TN==NULL)    return;
        if(TN->left==NULL && TN->right!=NULL)   cout<<TN->right->data<<" ";
        if(TN->left!=NULL && TN->right==NULL)   cout<<TN->left->data<<" ";
        sibling(TN->left);
        sibling(TN->right);
    }
public:
    BinaryTree()
    {
        root=NULL;
    }
    void FILLTREE()
    {
        root=filltree();
    }
    void FILLLEVELORDER()
    {
        root=filltreelevel();
    }
    void LEAFSHOW()
    {
        countLeaf(root);
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
    void INPRE(int In[100],int Pre[100],int s,int e)
    {
        root=InAndPre(In,Pre,s,e);
    }
    void INPOST(int In[100],int Pre[100],int s,int e)
    {
        root=InAndPost(In,Pre,s,e);
    }
    void display()
    {
        DISPLAY(root);
    }
    void boolpreorder()
    {
        root=inputtree(root);
        cout<<"[";
       arraylist(root);
       cout<<"]";
        //sibling(root);
       // int n1,n2;                        50 true 12 true 18 false false false true 13 false false
       // cin>>n1>>n2;
        //cout<<LCA(root,n1,n2)->data;
    }/*
    void alternate(){
        alternateorder(root);
    }*/
    TreeNode *returnhead(){
        return root;
    }
    void identical(TreeNode *A,TreeNode *B){
        if(identicaltree(A,B))  cout<<"true";
        else cout<<"false";
    }
};
int main()
{
    BinaryTree BT,BT1,BT2;
    // BT.FILLTREE();
    // BT.FILLLEVELORDER();
    //BT.preorder();
    // int n,m,In[100],Pre[100];cin>>n;
    // for(int i=0;i<n;i++)    cin>>Pre[i];
    // cin>>m;
    // for(int i=0;i<m;i++)    cin>>In[i];
    // BT.INPRE(In,Pre,0,n-1);
    // BT.INPOST(In,Pre,0,n-1);
    //BT.LEVELORDER();
    //cout<<endl;
    //cin>>n>>m;
    BT1.boolpreorder();
   // BT2.boolpreorder();
   // BT.identical(BT1.returnhead(),BT2.returnhead());
    // BT.preorder/();
    //BT1.LEVELORDER();
    //cout<<endl;
    // BT.LEAFSHOW();
    // BT.display();
   // BT.minnode();
  // BT.alternate();
    return 0;//
}
