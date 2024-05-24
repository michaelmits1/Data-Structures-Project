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
    node->equalnext=nullptr;
  return node;
}

node* find_min(node* root){
   if (root->left==nullptr) return root ;
    //check if the node contains key
    return find_min(root->left);
}

node* find_max(node* root){
   if (root->right==nullptr) return root ;
    //check if the node contains key
    return find_max(root->right);
}

// Traverse Inorder
void traverseInOrder( node *temp) {
  if (temp != nullptr) {
    traverseInOrder(temp->left);
    print_node_equal_list(temp);
    traverseInOrder(temp->right);
  }
}

void print_node_equal_list(node* temp){
    while(temp!=nullptr){
        print_node(temp);
        temp=temp->equalnext;
    }
}

void print_node(node *temp){
    if (temp==nullptr){
        cout<<"Key not found\n";
        return;
    }
    cout << "Period: " << temp->data.period << ", ";
    cout << "Event: " << (temp->data.event ? "Births" : "Deaths") << ", ";
    cout << "Region: " << temp->data.region << ", ";
    cout << "Count: " << temp->data.cnt << endl;
}