#include<iostream>
using namespace std;

int power(int a,int b,int c){
    if(b==0)
        return 1;
    if(!(b&1))
        return power((a*a)%c,b/2,c);
    return ((power((a*a)%c,b/2,c))*(a%c))%c;

}

int main(){
    long c=71;
    int a,b;
    cin>>a>>b;
    cout<<power(a,b,c);
}
