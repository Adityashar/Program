#include<iostream>
using namespace std;
///n log log n
void eulertotient(int n){
    int *a=new int[n+1];
    for(int i=0;i<=n;i++)   a[i]=i;
    for(int i=2;i<=n;i++){
        if(a[i]==i){
            a[i]=i-1;
            for(int j=i*2;j<=n;j+=i){
                a[j]=(a[j]*(i-1))/i;
            }
        }
    }
    for(int i=2;i<=n;i++)
        cout<<i<<"  "<<a[i]<<endl;
}

int main(){
    int n;
    cin>>n;
    eulertotient(n);
}
