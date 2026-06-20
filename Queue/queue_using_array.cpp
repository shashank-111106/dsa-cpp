//implementations of queue using array

#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int cap;
    int front ,rear;

    public:
    Queue(int size){
        cap = size;
        arr = new int[cap];
        front = 0;
        rear = -1;
    }
    void push(int data){
        if (rear == cap - 1)
        {
            cout<<"Queue is FULL\n";
            return;
        }
        rear++;
        arr[rear] = data;
    }

    void pop(){
        if (empty()){
            cout<<"Queue is EMPTY\n";
            return;
        }
        front++;
        // reset queue when empty 
        if (front > rear)
        {
            front = 0;
            rear = -1;
        }
    }

    int frontElement(){
        if (empty())
        {
            cout<<"Queue is EMPTY\n";
            return-1;
        }
        return arr[front];
    }

    bool empty(){
        return front > rear;
    }
};
int main(){
    Queue q(3);

    q.push(1);
    q.push(2);
    q.pop();
    q.push(3);

    while (!q.empty())
    {
        cout<<q.frontElement()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
    
}

