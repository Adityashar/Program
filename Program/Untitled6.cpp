#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

ll numbofint(int x,int n,int m){
    if(n==0)    return 1;
    else if (n%2==0)
        return numbofint((x*x)%m,n/2,m);
    return (x*numbofint((x*x)%m,(n-1)/2,m))%m;
}

int main(){
    ll t;
    cin>>t;
    while(t-- >0){
        ll n;
        int w;
        cin>>n>>w;
        if(w<-9 || w>8) return 0;
        if(w<0) w+=18;
        int a[18];
        for(int i=0;i<18;i++){
            if(i>=0&&i<=8) a[i]=10-i-1;
            else    a[i]=i-8;
        }
        ll m=1000000007;
        ll k=numbofint(10,n-2,m);
        ll output=((k%m)*(a[w]%m))%m;
        cout<<output;
    }
}
