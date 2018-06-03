#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],flag[n],sum[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        flag[i]=-1;
        sum[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int count=1;
        for(int j=0;j<n;j++)
        {
            if(a[i]!=a[j]){
                sum[i]+=a[j];
            }
            else{
                count++;
                flag[i]=0;
            }
        }
        if(flag[i]==0){
            flag[i]=count;
        }
    }
    for(int i=0;i<n;i++)    cout<<sum[i]<<" ";

    return 0;
}
