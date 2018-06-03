#include <iostream>
#include <vector>
using namespace std;
int **dp;

void printsubset(int a[],int n,int sum){
    dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[sum+1];
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]>j)
                dp[i][j]=dp[i-1][j];
            if(a[i-1]<=j)
                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
}
///

int main(){
    int n,Given_Sum;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>Given_Sum;
    printsubset(a,n,Given_Sum);
    return 0;
}
