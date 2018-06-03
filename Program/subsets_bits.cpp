#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void subsets_bit(int a[],int n,int sum){
    for(int i=0;i<(1<<n);i++){
        stack<int> s;
        int sum_array=0;
        for(int j=0;j<n;j++){
            if(i& 1<<j){
                sum_array+=a[j];
                s.push(a[j]);
            }
        }
        if(sum_array==sum){
            while(!s.empty()){
                cout<<s.top()<<"  ";
                s.pop();
            }
            cout<<endl;
        }

    }
}

int main(){
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=0;i<n;i++)    cin>>a[i];
    int sum;
    cin>>sum;
    subsets_bit(a,n,sum);
}
