#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,m,a[100][100],k=1;
    cin>>n>>m;
    int rs=0,cs=0,ce=m-1,re=n-1;

    while(rs<=re&&cs<=ce)
    {
        for(int i=cs;i<=ce;i++)
        {
            a[rs][i]=k;
        }
        rs++;
        for(int i=rs;i<=re;i++)
        {
            a[i][ce]=k;

        }
        ce--;
        if(rs<=re)
        {
            for(int i=ce;i>=cs;i--)
            {
                a[re][i]=k;
            }
            re--;
        }
        if(cs<=ce)
        {
            for(int i=re;i>=rs;i--)
            {
                a[i][cs]=k;
            }
            cs++;

        }
        k=1-k;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cout<<a[i][j];}cout<<endl;}
    return 0;
}
