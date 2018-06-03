#include<iostream>
#include<vector>

using namespace std;
class Priority_Queue
{
    vector <int>v;
    int index;
public:
    Priority_Queue()
    {
        v.push_back(-1);index=1;
    }
    void push(int d)
    {
        v.push_back(d);index++;
        int child=index-1;
        int parent=child/2;
        while(v[parent]>v[child]&&child>1)
        {
            swap(v[parent],v[child]);
            child=parent;
            parent=child/2;
        }
    }
    int getMIN()
    {
        return v[1];
    }
    bool isEmpty()
    {
        if(index==1)   return true ;else return false;
    }
    void heapify(int i)
    {
        int left=2*i;
        int right=2*i-1;

        int min_index=i;
        if(left<index && v[left]<v[min_index])  min_index=left;
        if(right<index && v[right]<v[min_index]) min_index=right;
        if(min_index!=i)
        {
            swap(v[i],v[min_index]);
            heapify(min_index);
        }
    }

    void pop()
    {
        if(index==1)    return;
        index=index-1;
        swap(v[1],v[index]);
        heapify(1);
    }

};
int main()
{
    Priority_Queue PQ;
    int arr[]={10,4,5,3,2,6,1,7};
    for(int i=0;i<8;i++)
    {
        PQ.push(arr[i]);
    }
    while(!PQ.isEmpty())
    {
        cout<<PQ.getMIN()<<" ";
        PQ.pop();
    }
}
