#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int stringtonum(char str[100],int s,int p)
{
    if(str[s]=='\0') return 0;
    return((str[s]-'0')*p+stringtonum(str,s+1,p/10));

}

int main()
{
    char str[100];
    cin.getline(str,100);
    cout<<stringtonum(str,0,pow(10,strlen(str)-1));

    return 0;
}
