// Circular Linked List Implementation

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
class Circularll{
    Node*head;
    Node*tail;
public:
    Circularll(){
        head = tail = NULL;
    }


void push_front(int val){
    Node*newNode = new Node(val);
    if (tail == NULL)
    {
        head = tail = newNode;
        tail -> next = head;
    }
    else{
        newNode -> next = head;
        head = newNode;
        tail -> next = head;
    }
}

void push_back(int val){
    Node*newNode = new Node(val);
    if (tail == NULL)
    {
        head = tail = newNode;
        tail -> next = head;
    }
    newNode -> next = head;
    tail -> next = newNode;
    tail = newNode;
}

void pop_front(){
    if (head == NULL) // if node is empty
    {
     return;
    }else if (head == tail)  // if only one node is present
    {   
        delete head;
        head =  tail = NULL;
    }
    else{
    Node*temp = head;
    head = temp -> next;
    tail  -> next = head;
    temp -> next = NULL;
    delete temp;
}
}
void pop_back(){
    if (head == NULL)
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = tail = NULL;
    }
    else{
    Node* temp = tail;
    Node* prev = head;

    while (prev -> next != tail)
    {
        prev = prev -> next;
    }
    tail = prev;
    tail -> next = head;

    temp -> next = NULL;
    delete temp;
   }
 }

 void printLL(){
    if (head == NULL)
    {
        return;
    }
    Node* temp = head;
    do
    {
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    while (temp != head);
    cout<<endl;
}
};

int main(){
  Circularll cll;

  cll.push_front(4);
  cll.push_front(3);
  cll.push_front(2);
  cll.push_front(1);
  cll.pop_back();

  cll.printLL();
  return 0;
}
