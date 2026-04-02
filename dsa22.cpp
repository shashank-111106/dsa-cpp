//stacks implementation using array

#include<iostream>
using namespace std;

class stack{
    int arr[100]; //array to store elements 
    int topIndex; // acts like top

    public:
    stack(){
        topIndex =-1; //initially empty
    }

    //push operation
    void push(int val){
        if (topIndex == 99)
        {
            cout<<"Stack Overflow\n";
            return;
        }
        topIndex++;
        arr[topIndex] = val;
    }

    //pop operation
    void pop(){
        if (topIndex == -1)
        {
            cout<<"stack underflow\n";
            return;
        }
        topIndex--; 
    }

    //top operation
    int top(){
        if (topIndex == -1)
        {
            cout<<"stack is empty\n";
            return-1;
        }

        return arr[topIndex];
    }
    
    //empty check
    bool empty(){
        return topIndex ==-1;
    }
};

int main(){
    stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl; 
    
return 0;
}