#include<iostream>
#include<vector>
using namespace std;

void builtTree(int *arr,int *tree,int s,int e,int tree_index){
    if(s==e){
        tree[tree_index]=arr[s];
        return;
    }
    int mid=(s+e)/2;

    builtTree(arr,tree,s,mid,2*tree_index);
    builtTree(arr,tree,mid+1,e,2*tree_index+1);

    tree[tree_index]=tree[2*tree_index]+tree[2*tree_index+1];
}
void updateTree(int *arr,int *tree,int s,int e,int treeNode,int upd_idx,int value){
    if(s==e){
        arr[upd_idx]=value;
        tree[treeNode]=value;
        return ;
    }
    int mid=(s+e)/2;
    if(upd_idx > mid)
        updateTree(arr,tree,mid+1,e,treeNode*2+1,upd_idx,value);
    else
        updateTree(arr,tree,s,mid,treeNode*2,upd_idx,value);

    tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
}
int query(int *tree,int s,int e,int right,int left,int treeNode){
    //Completely outside the range treeNode element
    if(s>right || e<left)
        return 0;
    else if(s>=left && e<=right)
        return tree[treeNode];
    int mid=(s+e)/2;
    int ans1=query(tree,s,mid,right,left,treeNode*2);
    int ans2=query(tree,mid+1,e,right,left,treeNode*2+1);
    return ans1+ans2;
}

int main(){
    int arr[]={1,2,3,4,5};
    int *tree=new int [10];

    builtTree(arr,tree,0,4,1);
    for(int i=1;i<10;i++){
        cout<<tree[i]<<"   ";
    }
    updateTree(arr,tree,0,4,1,2,10);
    int ans=query(tree,0,4,4,2,1);
    cout<<endl<<ans;
}
