#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double fact(float n)
{
    if(n<=1)    return 1;
    return n*fact(n-1);
}

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        vector <int>v;
        float n,k;
        double f;
        int j=0;
        cin>>n>>k;
        f=fact(n);
        while(true)
        {
            float p=pow(k,j);
            if(fmod(f,p)!=0) break;
            if(fmod(f,p)==0)    v.push_back(j);
            j++;
        }
                cout<<v.back()<<endl;
    }
    return 0;
}
