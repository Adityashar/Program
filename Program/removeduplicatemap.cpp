#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

unordered_map<char,int> map_string;
stack<char> s;

char *remove_duplicates(char *str){
    string outstr="";
    for(int i=0;str[i]!='\0';i++){
        map_string[str[i]]++;
    }
    for(auto ip=map_string.begin();ip!=map_string.end();ip++){
        outstr=ip->first+outstr;
    }
    int l=outstr.length();
    char *ch=new char [l+1];
    outstr.copy(ch,l);
    return ch;
}

int main(){
    char str[100];
    cin.getline(str,100);
    cout<<remove_duplicates(str);
}
