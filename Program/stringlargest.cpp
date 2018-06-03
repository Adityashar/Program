#include<iostream>
#include<cstring>
using namespace std;

void stringlarge(string str[100],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int cur=i;
        for(j=i+1;str[j]!='\0';j++)
        {
            if(str[i][j]>str[i][j+1])
            {
                cur=j;
            }
        }
        swap(str[i],str[cur]);
    }
    cout<<endl;
    for(i=0;i<n;i++)    cout<<str[i]<<endl;
}

int main()
{
    string str[10];int n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>str[i];
    stringlarge(str,n);

    return 0;
}
