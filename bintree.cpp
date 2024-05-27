#include "region.h"
using namespace std;

// New node creation
node* newNode(Region key) {
    node* node =  new struct node;
    if (node == nullptr) {
        cerr << "Memory allocation failed\n";
        exit(1);
    }
    node->data = key;
    node->left = nullptr;
    node->right = nullptr;
    node->equalnext = nullptr;
    return node;
}
// Traverse Inorder
void traverseInOrder(node *temp) {
    if (temp != nullptr) {
        //left child
        traverseInOrder(temp->left);
        //equals list
        print_node_equal_tree(temp);
        //right child
        traverseInOrder(temp->right);
    }
}

node* find_min(node* root){
    if(root->left == nullptr) return root;
    else return find_min(root->left);
}

node* find_max(node* root){
    if (root->right==nullptr) return root ;
    else return find_max(root->right);
}

void print_node_equal_tree(node* temp){
    print_node(temp);
    temp = temp->equalnext;
    traverseInOrder(temp);
}

void print_node(node *temp){
    if (temp==nullptr){
        cout<<"Key not found\n";
        return;
    }
    cout << "Period: " << temp->data.period << ", "
         << "Region: " << temp->data.region << ", "
         << "Births: " << temp->data.cnt << endl;
}



