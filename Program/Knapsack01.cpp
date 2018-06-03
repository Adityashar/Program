#include<iostream>
using namespace std;
int **memo;

int knapsack(int weight[],int value[],int giv_wt,int n){
    memo=new int*[n+1];
    for(int i=0;i<=n;i++){
        memo[i]=new int[giv_wt+1];
        memo[i][0]=0;
    }
    for(int i=0;i<=giv_wt;i++){
        memo[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=giv_wt;j++){
            if(weight[i-1]>j)   memo[i][j]=memo[i-1][j];
            else
            {
                memo[i][j]=max(memo[i-1][j],memo[i-1][j-weight[i-1]]+value[i-1]);
            }
        }
    }
    return memo[n][giv_wt];
}

void printweight(int value[],int giv_wt,int weight[],int n){
    int i=n,j=giv_wt;
    int r=0,s=0;
    //int temp[n+1][giv_wt+1];
    while(i>0 &&j>0){
        if(memo[i-1][j]==memo[i][j]){
            i--;
        }
        else if(memo[i][j]!=memo[i-1][j]){
            cout<<endl<<memo[i][j];
            i--;
            j-=weight[i-1];
        }
    }

}

int main(){
    int n;
    cin>>n;
    int *weight=new int[n];
    int *value=new int[n];
    for(int i=0;i<n;i++)    cin>>weight[i];
    for(int i=0;i<n;i++)    cin>>value[i];
    int given_sum;
    cin>>given_sum;
    cout<<"Maximum value having the weight "<<given_sum<<" :"<<knapsack(weight,value,given_sum,n);
    printweight(value,given_sum,weight,n);
    return 0;
}
