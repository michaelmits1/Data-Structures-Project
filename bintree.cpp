#include "region.h"
using namespace std;

// New node creation
node* newNode(Region key) {
    node* node =  new struct node;
    if (node == nullptr) {
        cerr << "Memory allocation failed\n";
        exit(1);
    }
    node->data=key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

node* insert(node* root,Region data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);
    //search left subtree for empty node
    if (data.cnt<=root->data.cnt) {
        root->left=insert(root->left,data);
        return root;
    }
        //search right subtree for empty node
    else {
        root->right=insert(root->right,data);
        return root;
    }
}

// Traverse Inorder
void traverseInOrder( node *temp,int counter) {
    if (temp != nullptr) {
        traverseInOrder(temp->left,counter);
        cout <<" Period: " << temp->data.period << ", ";
        cout << "Event: " << (temp->data.event ? "Births" : "Deaths") << ", ";
        cout << "Region: " << temp->data.region << ", ";
        cout << "Count: " << temp->data.cnt << endl;
        traverseInOrder(temp->right,counter);
    }
}