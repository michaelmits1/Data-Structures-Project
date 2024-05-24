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
    else if(data.region > root->data.region){
        root->right = insert_by_region(root->right, data);
        return root;
    }
    else {
        root->equalnext = insert_by_births(root->equalnext,data);
        return root;
    }
}
node* search_by_region(node* root, string region){
    if(root == nullptr) return nullptr ;

    //check if the node contains key
    if(root->data.region == region) return root;

    //search left subtree
    else if(region < root->data.region) return search_by_region(root->left, region);

    //search right subtree
    else return search_by_region(root->right, region);
}
