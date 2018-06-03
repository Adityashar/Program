#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int a[100][100];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {cout<<a[i][j]<<"\t";
    }cout<<endl;
    }

    int rs=0,re=n-1,ce=m-1,cs=0;

    while(cs<=ce && rs<=re)
    {


        for(int i=cs;i<=ce;i++)
            cout<<a[rs][i];
        rs++;

        for(int i=rs;i<=re;i++)
            cout<<a[i][ce];
        ce--;
        if(rs<=re){
            for(int i=ce;i>=cs;i--)
                cout<<a[re][i];
        re--;
        }
        if(cs<=ce)
        {
                for(int i=re;i>=rs;i--)
                    cout<<a[i][cs];
                cs++;
        }



   }

    return 0;
}
