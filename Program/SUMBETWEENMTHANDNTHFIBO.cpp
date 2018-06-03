#include<iostream>
using namespace std;
typedef unsigned long long ll;
void multiply(ll A[2][2],ll B[2][2]){
    ll ovalue=A[0][0]*B[0][0]+A[0][1]*B[1][0];
    ll svalue=A[0][0]*B[0][1]+A[0][1]*B[1][1];
    ll tvalue=A[1][0]*B[0][0]+A[1][1]*B[1][0];
    ll fvalue=A[1][0]*B[0][1]+A[1][1]*B[1][1];
    A[0][0]=ovalue;
    A[0][1]=svalue;
    A[1][0]=tvalue;
    A[1][1]=fvalue;
}

void power(ll A[2][2],ll n){
    if(n==0||n==1)  return ;
    power(A,n/2);

    multiply(A,A);
    if(n&1){
        ll M[2][2]={{1,1},{1,0}};
        multiply(A,M);
    }
}

ll fib(ll n){
    if(n==0) return 0;
    ll A[2][2]={{1,1},{1,0}};
    power(A,n-1);
    return A[0][0];
}

ll sum(ll n,ll m){
    ll sum=0;
    ll c=1000000007;
    sum=(fib(m+2)-fib(n+1))%c;
    return sum;
}

int main(){
    ll n,m;
    cin>>n>>m;
    cout<<sum(n,m);
}
