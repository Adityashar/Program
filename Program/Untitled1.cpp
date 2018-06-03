#include<iostream>
using namespace std;

void multiply(int A[2][2],int B[2][2]){
    int ovalue=A[0][0]*B[0][0]+A[0][1]*B[1][0];
    int svalue=A[0][0]*B[0][1]+A[0][1]*B[1][1];
    int tvalue=A[1][0]*B[0][0]+A[1][1]*B[1][0];
    int fvalue=A[1][0]*B[0][1]+A[1][1]*B[1][1];
    A[0][0]=ovalue;
    A[0][1]=svalue;
    A[1][0]=tvalue;
    A[1][1]=fvalue;
}

void power(int A[2][2],int n){
    if(n==0||n==1)  return ;
    power(A,n/2);

    multiply(A,A);
    if(n&1){
        int M[2][2]={{1,1},{1,0}};
        multiply(A,M);
    }
}

int fib(int n){
    if(n==0) return 0;
    int A[2][2]={{1,1},{1,0}};
    power(A,n-1);
    return A[0][0];
}

int main(){
    int n;
    cin>>n;

    cout<<fib(n);

}
