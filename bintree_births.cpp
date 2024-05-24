#include "region.h"
using namespace std;

node* insert_by_births(node* root, Region data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);

    //search left subtree for empty node
    if (data.cnt <= root->data.cnt) {
        root->left = insert_by_births(root->left, data);
        return root;
    }

    //search right subtree for empty node
    else {
        root->right = insert_by_births(root->right, data);
        return root;
    }
}

// Traverse Inorder
void traverseInOrder(node *temp) {
    if (temp != nullptr) {
        //left child
        traverseInOrder(temp->left);
        //parent
        cout <<" Period: " << temp->data.period << ", ";
        cout << "Region: " << temp->data.region << ", ";
        cout << "Births: " << temp->data.cnt << endl;
        //right child
        traverseInOrder(temp->right);
    }
}