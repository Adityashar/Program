#include<iostream>
using namespace std;

class Queue
{
        int *arr;
        int maxsize;
        int front;
        int rear;
        int cursize;
    public:
       Queue(int s=4)
       {
           maxsize=s;
           front=0;
           rear=maxsize-1;
           cursize=0;
           arr=new int[maxsize];
       }
    void push(int d)
    {
        if(cursize!=maxsize)
        {
            rear=(rear+1)%maxsize;
            arr[rear]=d;
            cursize++;
        }
    }
    int pop()
    {
        if(cursize!=0)
        {
            int d=arr[front];
            front=(front+1)%maxsize;
            cursize--;
            return d;
        }
    }
    int getfront()
    {
        if(cursize!=0)
        {
            return arr[front];
        }
    }
    bool isEmpty()
    {
        if(cursize==0)return false; else return true;
    }
    ~Queue()
    {
        delete [] arr;
    }
};

int main()
{
    Queue Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    cout<<Q.pop();
    cout<<Q.pop();
    Q.push(5);
    cout<<Q.pop();
}
