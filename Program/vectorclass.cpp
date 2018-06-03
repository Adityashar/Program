#include <iostream>
using namespace std;
template <class anyclass>
class vector
{
    anyclass *arr;           ///for minimum size of the array we'll use constructors
    int index;
    int maxsize;        ///maximum size that can reached

public:
    vector(int size=4)
    {
        arr = new anyclass [size];
        index=0;
        maxsize =size;
    }
    ~vector()
    {
        delete [] arr; ///object=STATIC Memory
    }
    void push_back(anyclass a)
    {
        if(index==maxsize)
        {
            anyclass *temp=new anyclass [2*maxsize];
            maxsize*=2;
            for(int i=0;i<index;i++) temp[i]=arr[i];
            delete [] arr;
            arr=temp;
        }
        arr[index]=a;
        index++;
    }
    anyclass pop_back()
    {
        if(index==0)    return -1;
        return arr[--index];
    }
    anyclass getElementByID(int i)
    {
        if(i<0||i>=index)   return -1;
        return arr[i];
    }
    int size()
    {
        return index;
    }
    int getMaxSize()
    {
        return maxsize;
    }
    anyclass &operator [] (int i)
    {
        return arr[i];
    }
    void operator+ (vector v)
    {
        for(int i=0;i<v.size();i++)
        {
            push_back(v[i]); ///Adding the second Vector object into the first
        }
    }
    ///friend ostream & operator<< (ostream &os, vector<anyclass> v);
};

int main()
{
    vector <int>v;
    cout<<v.size()<<endl;
    for(int i=0;i<10;i++)   v.push_back(i*i);
    cout<<v.size()<<endl;
    for(int i=0;i<10;i++)   cout<<v.pop_back()<<" ";
    cout<<endl;
    for(int i=0;i<10;i++)   cout<<v[i]<<" ";
    cout<<endl;

    vector <int>v1;
    for(int i=0;i<10;i++)   v1.push_back(i*i*i);
    cout<<endl;
    for(int i=0;i<5;i++)   cout<<v1[i]<<" ";
    v+v1;  ///?????????
    cout<<endl<<v1.size()<<endl;
    v[5]=22;
    for(int i=0;i<10;i++)   cout<<v[i]<<" ";
    return 0;
}
