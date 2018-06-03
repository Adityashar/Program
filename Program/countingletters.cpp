#include<iostream>
#include<cstring>

using namespace std;

void sorting (char str[100])
{
    int cur=0;
    for(int i=0;str[i]!='\0';i++)
    {
        cur=i;
        for(int j=i+1;str[j]!='\0';j++)
        {
            if(str[cur]>str[j])
            {
                cur=j;
            }
        }
        swap(str[i],str[cur]);
    }

}
void countelement(char str[100])
{
    int temp[100];
    for(int i=0;i<100;i++)  temp[i]=-1;
    for(int i=0;str[i]!='\0';i++)
    {
        int count=1;
        for(int j=i+1;str[j]!='\0';j++)
        {
            if(str[j]==str[i])
            {
                count++;temp[j]=0;
            }
        }
        if(temp[i]!=0)
        {
            temp[i]=count;
        }
    }
    for(int i=0;str[i]!='\0';i++)
    {
        if(temp[i]!=0)
        {
            cout<<str[i]<<temp[i];
        }
    }
}

int main()
{
    char str[100];
    cin.getline(str,100);
    //sorting(str);

    countelement(str);

    return 0;
}
