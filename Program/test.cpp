#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<pair<char,int>,int> map;

void permutations(pair<char,int> *p,int s,int cnt,int e){
    if(p[s]->first=='\0'){
        cnt++;
        map.insert(make_pair(p,cnt));
        return ;
    }
    for(int i=s;i<=e;i++){
        swap(p[i],p[s]);
        permutations(str,s+1);
        swap(p[i],p[s]);
    }
}

int main(){
    int t;
    cin>>t;
    while(t-- >0){
        string str;
        cin>>str;
        pair<string,int> *p1;
        int l=str.length();
        p1=new pair<char,int> [l+1];
        for(int i=0;str[i]!='\0';i++){
            p1[i].make_pair(str[i],i+1);
        }
        for(auto ip=p1.begin();ip!=p1.end();ip++){
            cout<<p1->first<<" "<<p1->second<<endl;
        }
      //  permutations(p1,0,0,l-1);
    }
    return 0;
}
