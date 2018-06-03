#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        v.push_back(i);
    }
    vector<int>::iterator ip;
    for(ip=v.begin();ip!=v.end();ip++){
        cout<<*ip;
    }
    return 0;
}
