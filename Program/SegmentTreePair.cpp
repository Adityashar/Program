#include<iostream>
#include<vector>
using namespace std;

void buildTree(int *arr, vector<pair<int, int> > &tree, int treeNode, int start, int end){
    if(start == end){
        if(arr[start] % 2 == 0){
            tree[treeNode].first = 1;
            tree[treeNode].second = 0;
        }
        else{
            tree[treeNode].first = 0;
            tree[treeNode].second = 1;
        }
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr, tree, treeNode*2, start, mid);
    buildTree(arr, tree, treeNode*2 + 1, mid + 1, end);
    tree[treeNode].first = tree[treeNode*2].first + tree[treeNode*2 + 1].first;
    tree[treeNode].second = tree[treeNode*2].second + tree[treeNode*2 + 1].second;
}
void updateTree(int *arr, vector<pair<int, int> > &tree, int start, int end, int curTN, int index, int val){
    if(start == end){
        arr[index] = val;
        if(val % 2 == 0){
            tree[curTN].first = 1;
            tree[curTN].second = 0;
        }
        else{
            tree[curTN].first = 0;
            tree[curTN].second = 1;
        }
        return;
    }
    int mid = (start + end)/2 ;
    if(index > mid){
        updateTree(arr, tree, mid + 1, end, 2*curTN + 1, index, val);
    }else{
        updateTree(arr, tree, start, mid, 2*curTN, index, val);
    }
    tree[curTN].first = tree[2*curTN].first + tree[2*curTN + 1].first;
    tree[curTN].second = tree[2*curTN].second + tree[2*curTN + 1].second;
}
int query_e(vector<pair<int, int> > &tree , int start, int end, int curTN, int left, int right){
    if(start > right || end < left)
        return 0;
    else if(start >= left && end <= right)
        return tree[curTN].first;
    int mid = (start + end)/2;
    int ans1 = query_e(tree, start, mid, 2*curTN, left, right);
    int ans2 = query_e(tree, mid + 1, end, 2*curTN + 1, left, right);
    return ans1 + ans2;
}
int query_o(vector<pair<int, int> > &tree, int start, int end, int curTN, int left, int right){
    if(start > right || end < left)
        return 0;
    else if(start >= left && end <= right)
        return tree[curTN].second;
    int mid = (start + end)/2;
    int ans1 = query_o(tree, start, mid, 2*curTN, left, right);
    int ans2 = query_o(tree, mid + 1, end, 2*curTN + 1, left, right);
    return ans1 + ans2;
}

int main(){
    int n , q;
    cin>>n;
    int *a = new int [n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<pair<int, int> > tree;
    for(int ip = 0; ip < 2*n; ++ip){
        tree.push_back(make_pair(0,0));
    }
    buildTree(a, tree, 1, 0, n - 1);
    //updateTree(a, tree, 0, n -1, 1, 2, 6);
    //cout<<endl;
    //for(int ip = 1; ip < 2*n; ++ip){
    //    cout<<tree[ip].first<<" "<<tree[ip].second<<endl;
    //}
    //cout<<endl;
    //cout<<query_o(tree, 0, n -1, 1, 1, 4);
    //cout<<endl<<query_e(tree, 0, n -1, 1, 1, 4);
    cin>>q;
     while(q--){
        int t, l, r;
        cin>>t>>l>>r;
        if(t == 0){
            updateTree(a, tree, 0, n -1, 1, l -1 , r);
        }
        else if(t == 1){
            cout<<query_e(tree, 0, n -1, 1, l-1, r-1)<<endl;
        }
        else if(t == 2){
            cout<<query_o(tree, 0, n -1, 1, l-1, r-1)<<endl;
        }
     }
    return 0;
}
