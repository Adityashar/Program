#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void checkpattern(int j,int l, string patt,string str){
	int flag=0;
	for(int i=0;i<l;i++){
		if(str[j+i]!=patt[i]) {
			flag=1;	break;
		}
	}
	if(!flag){
        for(int i=0;i<l;i++)   cout<<str[i+j];
	}
}

void hashgen(string str,string patt, int l){
	long prime=99,hash_ini=0;
	long h_patt=0;
	for(int i=0;i<l;i++){
		h_patt+=patt[i]*pow(prime,i);
	}
	cout<<h_patt<<endl;
	for(int i=0;i<l;i++){
		hash_ini+=str[i]*pow(prime,i);
	}
	//cout<<hash_ini;
	int l2=str.length();
	for(int j=1;j<=l2-l;j++){
		long hash_sub=(hash_ini-str[j-1])/prime +str[j+l-1]*pow(prime,l-1);
		if(hash_sub==h_patt){
            cout<<hash_sub;
			checkpattern(j,l,patt,str);
		}
	}
}

int main(){
	string str, patt;
	cin>>str;
	cin>>patt;
    int l=patt.length();
	hashgen(str,patt,l);

}
