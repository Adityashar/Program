#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

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
    if(n==0 || n==1)    return ;
    power(A,n/2);
    multiply(A,A);
    if(n&1){
        ll m[2][2]={{1,1},{1,0}};
        multiply(A,m);
    }
}

ll fib(ll n){
    if(n==0)    return 1;
    ll A[2][2]={{1,1},{1,0}};
    power(A,n-1);
    return A[0][0];
}

ll powmodulo(ll a,ll b,ll c){
    if(b==0)    return 1;
    if(!(b&1)) return powmodulo((a*a)%c,b/2,c);
    return (((a*a)%c)*powmodulo((a*a)%c,b/2,c))%c;
}

ll term (ll n,ll a,ll c){
    ll k=fib(n)%(c-1);
    ll p=powmodulo(a,k,c);
    return p;
}

ll problem(ll a,ll b,ll n){
    if(n==0)    return a;
    if(n==1)    return b;
    ll c=1000000007;
    ll gn=term(n-1,a,c)*term(n,b,c);
    return gn%c;
}

int main(){
    ll a,b,n;                                ///f(0)=a and f(1)=b;
    cin>>a>>b>>n;
    // g=a^f(n-1)*b^f(n)
    ll gn=problem(a+1,b+1,n);
    cout<<gn-1;
    return 0;
}
