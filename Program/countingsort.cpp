#include <iostream>
#include <cstring>
using namespace std;

int main(){

    int arr[100];
    int n,c=0; cin>>n;
    ///to take input
    for (int i=0;i<n;i++) cin>>arr[i];

    int cnt[4]={0};

    ///to actual count occurance of each number
    for (int i=0;i<n;i++) cnt[arr[i]]++;

    ///now updating the array based on count
    for (int i=0;i<n;i++){
        for (int j=0;j<cnt[i];j++,c++) arr[c]=i;
    }
    ///print the sorted array
    for (int i=0;i<n;i++) cout<<arr[i];
}
