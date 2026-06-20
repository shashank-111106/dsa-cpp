//Implementation of circular queue
//insertion is done at rear and deletion is done at front 

#include<iostream>
using namespace std;

class CircularQueue{
    int*arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size){
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0;
        r = -1;
    }

void push(int data){
    if (currSize == cap )
    {
        cout<<"Queue is Overflow\n";
        return;
    }
    r = (r+1)%cap;
    arr[r] = data;
    currSize++;
}

bool empty(){
    return currSize == 0;
}

void pop(){
    if (empty())
    {
        cout<<"Queue is Underflow\n";
        return;
    }
    f = (f+1)%cap;
    currSize--;    
}

int front(){
    if (empty())
    {
        cout<<"Queue is Empty\n";
        return -1;
    }
    return arr[f];
}
};

int main(){
    CircularQueue cq(3);
    
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);


    while(!cq.empty()){
        cout<<cq.front()<<" -> ";
        cq.pop();
    }
cout<<endl;

return 0;
}
