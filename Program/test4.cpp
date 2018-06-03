#include<iostream>
#include<string>
using namespace std;

char * remove_duplicates(char *ss){
    string str(ss);
    int *temp=new int [str.length()];
    int i,j;
    string outstr="";
    for(int i=0;str[i]!='\0';i++)   temp[i]=-1;
    for(i=0;str[i]!='\0';i++){
        for(j=i+1;str[j]!='\0';j++){
            if(str[i]==str[j]){
                temp[j]=0;
            }
        }
        if(temp[i]!=0){
            outstr+=str[i];
        }
    }
    int l=outstr.length();
    char *ch=new char[l];
    outstr.copy(ch,l);
    return ch;
}

int main(){
    char str[100];
    cin.getline(str,100);

    cout<<remove_duplicates(str);

}
