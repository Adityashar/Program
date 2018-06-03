#include<iostream>
#include<cstring>
using namespace std;

void Permutation (char ch[]){
    if (ch[s]=='\0'){
        cout<<ch<<endl;
    }
    for (int i=s;ch[i]!='\0';i++){
        swap(ch[s],ch[i]);
        Permutation(ch);
        swap(ch[s],ch[i]);
    }


}

int main(){
    char ch[]="ABC";
    char out[100];
    Permutation (ch);


}
