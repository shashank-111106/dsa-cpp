#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//insert nodes in BST
Node*insert(Node*root, int val){
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

//search in BST
bool search(Node*root, int key){
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (root->data > key)
    {
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
}

// delete in BST
Node*getInorderSuccessor(Node*root){ // this function finds the smallest node in the right subtree and it is basically used in 2 children case
    while (root != NULL && root -> left != NULL) //move left until no more child exists 
    {
       root = root -> left; //keep moving left
       return root; // return smallest node
    }
}

Node*deleteNode(Node*root, int key){
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root -> data)
    {
        root -> left = deleteNode(root -> left, key);
    }
    else if (key > root -> data){
        root -> right = deleteNode(root -> right, key);
    }
    else{
        //root == key;
        if (root -> left == NULL) // 0 child
        {
            Node*temp = root -> right; //store the value of right node
            delete root;  // delete root
            return temp; //return the value 
        }
        else if (root -> right == NULL) // 1 child
        {
            Node*temp = root -> left; //stores the value of left node
            delete root;
            return temp; //return the value 
        }
        else{ // 2 children 
            Node*IS = getInorderSuccessor(root -> right);
                root -> data = IS -> data; //swap data of root with inorder successor( it means the left most node of the right subtree)
                root -> right = deleteNode(root -> right, IS -> data); // now delete the original value
            }
            return root;
        }
    }
