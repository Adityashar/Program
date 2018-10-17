#include<iostream>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int curTN){
    if(start == end){
        tree[curTN] = arr[start];
        return ;
    }
    int mid = (start + end)/2;

    buildTree(arr, tree, start, mid, 2*curTN);
    buildTree(arr, tree, mid + 1, end, 2*curTN + 1);
    tree[curTN] = tree[curTN *2 + 1] + tree[2*curTN];
}
void updateTree(int *arr, int *tree, int start, int end, int curTN, int index, int val){
    if(start == end){
        arr[index] = val;
        tree[curTN] = val;
        return;
    }
    int mid = (start + end)/2 ;
    if(index > mid){
        updateTree(arr, tree, mid + 1, end, 2*curTN + 1, index, val);
    }else{
        updateTree(arr, tree, start, mid, 2*curTN, index, val);
    }
    tree[curTN] = tree[2*curTN] + tree[2*curTN + 1];
}
int query(int *tree, int start, int end, int curTN, int left, int right){
    if(start > right || end < left)
        return 0;
    else if(start >= left && end <= right)
        return tree[curTN];
    int mid = (start + end)/2;
    int ans1 = query(tree, start, mid, 2*curTN, left, right);
    int ans2 = query(tree, mid + 1, end, 2*curTN + 1, left, right);
    return ans1 + ans2;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int *tree = new int[10];
    buildTree(arr, tree, 0, 4, 1);
    updateTree(arr, tree, 0, 4, 1, 2, 10);
    for(int i= 1; i<10 ; i++){
        cout<<tree[i]<<endl;
    }
    int ans = query(tree, 0, 4, 1, 2, 4);
    cout<<ans;
}
