#include<iostream>
#include<algorithm>
using namespace std;

class triplet{
    public:
    int x;
    int y;
    int gcd;
};

triplet euclidext(int a, int b){
    if(b == 0){
        triplet ans;
        ans.gcd = a;
        ans.y = 0;
        ans.x = 1;
        return ans;
    }

    triplet smallAns = euclidext(b, a%b);
    triplet largeAns;
    largeAns.gcd = smallAns.gcd;
    largeAns.x = smallAns.y;
    largeAns.y = smallAns.x - (a / b)*smallAns.y;
    return largeAns;
}

int gcd(int a, int b){
    if(a < b)   return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int a= 16, b= 10;
    triplet t = euclidext(a, b);
    cout<<t.gcd<<" "<<t.x<<"  "<<t.y;
    return 0;
}
