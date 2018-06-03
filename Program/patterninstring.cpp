#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
unordered_map<string,int> permtt;

void permutation(string str,int s,int &cnt){
    if(str[s]=='\0'){
        cnt++;
        permtt.insert(make_pair(str,cnt));
        return;
    }
    for(int i=s;str[i]!='\0';i++){
        swap(str[s],str[i]);
        permutation(str,s+1,cnt);
        swap(str[s],str[i]);
    }
}

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t-->0){
        string str="chef",input_str;
        cin>>input_str;
        int cnt=0;
        permutation(str,0,cnt);

        for(auto ip=permtt.begin();ip!=permtt.end();ip++){
            cout<<ip->first<<"  "<<ip->second<<endl;
        }/*
        int l=input_str.length()-4,k=0;
        cout<<l;
        for(int i=0;i<=l;i++){
            if(permtt.find(input_str.substr(i,4))!=permtt.end()){
                ++k;
            }
        }
        if(k!=0){
                cout<<"lovely "<<k<<endl;
        }
        else cout<<"normal"<<endl;*/
    }

}
