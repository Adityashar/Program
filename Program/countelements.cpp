#include <iostream>

using namespace std;

int main()
{
    int temp[100],a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];temp[i]=-1;
    }
    for(int i=0;i<n;i++)
    {       int count =1;
            for(int j=i+1;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    count++;
                    temp[j]=0;
                }
            }
            if(temp[i]!=0)
            {
                temp[i]=count;
            }
    }
    for(int i=0;i<n;i++)
    {
        if(temp[i]!=0)
        cout<<a[i]<<"-"<<temp[i]<<endl;
    }
    return 0;
}
