#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*prev;

    Node(int val){
        data =  val;
        next = prev = NULL;
    }
};
class doublyList{
    Node*head;
    Node*tail;

    doublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node * newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode -> next = head;
        head ->prev = newNode;
        head = newNode;
    }
    void push_back(int val){
        Node*newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail ->next = newNode;
        newNode ->prev = tail;
        tail = newNode;
    }
    
    void pop_front(){
        if (head == NULL)
        {
            cout<<"DLL is EMPTY\n";
            return ;
        }
        Node*temp = head;
        head = head ->next;

        while (head != NULL)
        {
            head -> prev = NULL;
        }
        temp -> next =NULL;
        delete temp;
    }

    void pop_back(){
        if (head == NULL)
        {
            cout<<"DLL is EMPTY\n";
            return;
        }
        Node*temp = tail;
        tail ->prev = tail;
        
        while (tail != NULL)
        {
            tail ->next = NULL;
        }
        temp -> next = NULL;
        delete temp;
    }
    
    void print(){
        Node*temp = head;

        while (temp != NULL)
        {
            cout<<temp -> data<<" <=> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
    }
};

int main(){
    doublyList ;
}