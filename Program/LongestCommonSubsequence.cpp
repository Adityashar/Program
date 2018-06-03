#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<char> s;
int **memo;

int longsubseq(string s1,string s2,int l1,int l2){
    memo=new int*[l1+1];
    for(int i=0;i<=l1;i++){
        memo[i]=new int[l2+1];
        memo[i][0]=0;
    }
    for(int i=0;i<=l2;i++){
        memo[0][i]=0;
    }
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i]==s2[j])
                memo[i][j]=memo[i-1][j-1]+1;
            else
                memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
        }
    }
    return memo[l1][l2];
}
void printsubseq(string s1,string s2,int l1,int l2){
    int i=l1+1,j=l2+1;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.push(s1[i-1]);
            i--;j--;
        }
        else{
            if(memo[i-1][j]>memo[i][j-1]) i--;
            else    j--;
        }
    }
    cout<<endl;
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int l1=s1.length();
    int l2=s2.length();
    cout<<"The Longest Subsequence : "<<longsubseq(s1,s2,l1,l2);
    printsubseq(s1,s2,l1,l2);
    return 0;
}
