#include<iostream>
using namespace std;
typedef long long ll;
ll power(ll a,ll m,ll c){
    if(m==0)    return 1;
    if(!(m&1))  return power((a*a)%c,m/2,c);
    return (power((a*a)%c,m/2,c)*(a%c))%c;
}

int main(){
    int t;
    cin>>t;
    while(t-- >0){
    ll n,p;
    cin>>n>>p;
    ll r=1;
    for(ll i=n+1;i<=p-1;i++){
        r*=power(i,p-2,p);
    }
    r=-1*(r%p)+p;
    cout<<r;
    }
}
