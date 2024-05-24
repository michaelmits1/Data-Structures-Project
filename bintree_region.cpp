#include "region.h"
using namespace std;

node* insert_by_region(node* root, Region data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);

    //search left subtree for empty node
    if (data.region <= root->data.region) {
        root->left = insert_by_region(root->left, data);
        return root;
    }

        //search right subtree for empty node
    else {
        root->right = insert_by_region(root->right, data);
        return root;
    }
}