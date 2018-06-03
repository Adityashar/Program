#include<iostream>
using namespace std;

void builtTree(int *arr, int *tree, int s,int e,int TreeNode){
    if(s==e){
        tree[TreeNode]=arr[s];
        return ;
    }
    int mid=(s+e)/2;
    builtTree(arr,tree,s,mid,TreeNode*2);
    builtTree(arr,tree,mid+1,e,TreeNode*2+1);

    tree[TreeNode]=min(tree[TreeNode*2],tree[TreeNode*2+1]);
}
void update_tree(int *arr,int *tree,int s,int e,int TreeNode,int idx,int value){
    if(s==e){
        arr[idx]=value;
        tree[TreeNode]=value;
        return ;
    }
    int mid=(s+e)/2;
    if(idx>mid)
        update_tree(arr,tree,mid+1,e,TreeNode*2+1,idx,value);
    else
        update_tree(arr,tree,s,mid,TreeNode*2,idx,value);

    tree[TreeNode]=min(tree[TreeNode*2],tree[TreeNode*2+1]);
}
int min_element(int *tree,int s,int e,int TreeNode,int left,int right){
    //if completely outside the range - tree node
    if(s>right || e<left)
        return INT_MAX;
    //if completely inside the range -tree node
    if(s>=left && e<=right)
        return tree[TreeNode];
    //if partially inside or outside
    int mid=(s+e)/2;
    int ans1=min_element(tree,s,mid,TreeNode*2,left,right);
    int ans2=min_element(tree,mid+1,e,TreeNode*2+1,left,right);
    return min(ans1,ans2);
}

int main(){
    int N,Q,L,R;
    cin>>N>>Q;
    int *arr=new int[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int *tree=new int [4*N];
    builtTree(arr,tree,0,N-1,1);

    while(Q-- >0){
        char ch;
        cin>>ch;
        cin.ignore();
        cin>>L>>R;
        if(ch=='q'){
            int m_arr=min_element(tree,0,N-1,1,L-1,R-1);
            cout<<m_arr<<endl;
        }
        else if(ch=='u'){
            update_tree(arr,tree,0,N-1,1,L,R);
        }
    }
}
