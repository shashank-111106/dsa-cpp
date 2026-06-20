//Implemenation of Queue using linked list
// the front is head and rear is tail. 

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
 
    Node(int val){
        data =  val;
        next = NULL;
    }
};
class QueueLL{
public:
    Node*head;
    Node*tail;
public:
  QueueLL(){
    head = tail = NULL;
  }

void push(int val){
    Node*newNode = new Node(val);
    if (empty())
    {
        head = tail = newNode;
    }
    tail -> next = newNode;
    tail = newNode;
}

void pop(){
    if (empty())
    {
        cout<<"Queue is EMPTY\n";
        return;
    }
    Node*temp = head;
    head = head -> next;
    delete temp;    
}

int front(){
    if (empty())
    {
        cout<<"Queue is EMPTY\n";
        return-1;
    }
    return head -> data;
}

bool empty(){
   return head == NULL;
}
};

int main(){
    QueueLL q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.push(4);
    

    if (q.empty())
    {
        cout<<"Queue is EMPTY\n";
        return 0;
    }
    Node*temp = q.head;
    while (temp != NULL)
    {
    cout<<temp -> data<<" -> ";
    temp = temp -> next;
    }
    cout<<endl;

    return 0;
}
