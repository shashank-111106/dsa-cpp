#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class stackLL{
public:
    Node*head;
    Node*tail;

    stackLL(){
        head = NULL;
    }

void push(int val){
    Node*newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode -> next = head;
    head = newNode;
}

void pop(){
    if (empty())
    {
        cout<<"Stack is EMPTY\n";
        return;
    }
    Node*temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
}

bool empty(){
    return head == NULL;
}

int top(){
    if (empty())
    {
        return-1;
    }
    return head -> data;
}

void print(){
    if (head == NULL)
    {
        cout<<"NULL\n";
    }
    
    Node*temp = head;

    while (temp != NULL)
    {
    cout<<temp -> data<<" -> ";
    temp = temp -> next;
    } 
    cout<<"NULL\n";
}
};

int main(){
    stackLL s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();

    s.print();

    return 0;
}