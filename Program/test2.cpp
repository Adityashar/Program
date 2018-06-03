#include<iostream>
#include <queue>
using namespace std;

class TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int d=0):data(d),left(NULL),right(NULL){}
	friend class BinaryTree;
};

class BinaryTree{
	TreeNode* root;
public:
	BinaryTree(){
		root=NULL;
	}

	TreeNode* levelOrderInput(){
		int d; cin>>d;
		queue<TreeNode*> q;

		TreeNode* n=new TreeNode(d);
		q.push(n);
		while (!q.empty()){
			TreeNode* f=q.front();
			q.pop();

			int ld,rd;
			cin>>ld>>rd;
			if(ld!=-1){
				f->left=new TreeNode(ld);
				q.push(f->left);
			}
			if(rd!=-1){
				f->right=new TreeNode(rd);
				q.push(f->right);
			}
		}
		return n;
	}

	void takeLOInput(){
		root=levelOrderInput();
	}
	void LevelOrderPrint(TreeNode* sNode){
		queue<TreeNode*> q;

		q.push(sNode);
		q.push (NULL);

		while(!q.empty()){
			TreeNode* f=q.front();
			q.pop();

			if (f==NULL){
				cout<<endl;
				if(!q.empty()) q.push(NULL);
			}
			else{
				cout<<f->data<<" ";
				if(f->left!=NULL){
					q.push(f->left);
				}
				if(f->right!=NULL){
					q.push(f->right);
				}
			}
		}

	}
	void printLO(){
		LevelOrderPrint(root);
	}

	void inOrderPrint(TreeNode* sNode){
		if(sNode==NULL) return;

		inOrderPrint(sNode->left);
		cout << sNode->data<<" ";
		inOrderPrint(sNode->right);
	}
	void preOrderPrint(TreeNode* sNode){
		if(sNode==NULL) return;

		cout << sNode->data<<" ";
		preOrderPrint(sNode->left);
		preOrderPrint(sNode->right);
	}
	void postOrderPrint(TreeNode* sNode){
		if(sNode==NULL) return;

		postOrderPrint(sNode->left);
		postOrderPrint(sNode->right);
		cout << sNode->data<<" ";
	}
	void print (string str){
		if (str=="inorder") inOrderPrint(root);
		else if (str=="preorder") preOrderPrint(root);
		else if(str=="postorder") postOrderPrint(root);
		else LevelOrderPrint(root);
	}
};

int main(){

	BinaryTree BT;
	BT.takeLOInput();
	cout<<endl<<"inorder-"; BT.print("inorder");
	cout<<endl<<"preorder-"; BT.print("preorder");
	cout<<endl<<"postorder-"; BT.print("postorder");
	cout<<endl<<"Levelorder-"; BT.print("LevelOrder");

}
