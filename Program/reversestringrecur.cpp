#include <iostream>
#include <cstring>
using namespace std;

bool reserv(char str1[100],int s,char str2[100],int e)
{
    if(str1[s]=='\0'&&str2[e]=='\0') return true;

    return (str1[s]==str2[e] && reserv(str1,s+1,str2,e-1));

}

int main()
{
    char str1[100],str2[100];
    cin.getline(str1,100);
    cin.getline(str2,100);
    if(reserv(str1,0,str2,strlen(str2)-1)) cout<<"true";
    else cout<<"false";

    return 0;
}
