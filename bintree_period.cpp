#include "region.h"
using namespace std;

node* search_by_period(node* root, const string& key){
    if (root == nullptr) return nullptr ;

    //check if the node contains key
    if(root->data.period == key) return root;

        //search left subtree
    else if(key < root->data.period) return search_by_period(root->left, key);

        //search right subtree
    else return search_by_period(root->right, key);
}

node* insert_by_period(node* root, const Region& data){
    //when you find empty child create a new node
    if (root == nullptr) return newNode(data);

    //search left subtree for empty node
    if (data.period < root->data.period){
        root->left = insert_by_period(root->left, data);
        return root;
    }
        //search right subtree for empty node
    else if (data.period > root->data.period){
        root->right = insert_by_period(root->right, data);
        return root;
    }
    else {
        root->equalnext = insert_by_period(root->equalnext, data);
        return root;
    }
}