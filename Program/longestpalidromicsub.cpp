#include <iostream>
#include <string>
#include <stack>
using namespace std;
int **memo;
stack<char> s;
int palin_sub(string s,int l){
    memo=new int*[l];
    for(int i=0;i<l;i++){
        memo[i]=new int[l];
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(i==j)   memo[i][j]=1;
            else memo[i][j]=0;
        }
    }
    for(int sl=2;sl<=l;sl++){
        for(int i=0;i<l-sl+1;i++){
                int j=i+sl-1;
                if(s[i]==s[j])  memo[i][j]=2+ memo[i+1][j-1];
                else    memo[i][j]=max(memo[i+1][j],memo[i][j-1]);
        }
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return memo[0][l-1];
}
void printpalindrome(string s,int l){
    int i=0,j=l-1,k=0,p=memo[0][l-1]-1;
    while(memo[i][j]!=0 &&k==p){
        if(memo[i+1][j]!=memo[i][j] && memo[i][j-1]!=memo[i][j]){
            s.push(a[j]);
            i++;j--;
        }
        else{
            if(memo[i+1][j]>=memo[i][j])    i++;
            else    j--;
        }
    }
}

int main(){
    string str;
    cin>>str;
    int l=str.length();
    cout<<"The Longest palindromic subsequence has the length :"<<palin_sub(str,l);
    printpalindrome(str,l);
    return 0;
}
