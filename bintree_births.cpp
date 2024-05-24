#include "region.h"
using namespace std;

node* insert_by_births(node* root,Region data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);
    //search left subtree for empty node
    if (data.cnt<root->data.cnt) {
        root->left=insert_by_births(root->left,data);
        return root;
    }
    //search right subtree for empty node
    else if(data.cnt>root->data.cnt) {
        root->right=insert_by_births(root->right,data);
        return root;
    }
    else {
        root->equalnext=insert_by_births(root->equalnext,data);
        return root;
    }
}

node* search_by_births(node* root,int key){
    if (root==nullptr) return nullptr ;
    //check if the node contains key
    if(root->data.cnt==key)return root;
    //search left subtree
    else if(key<root->data.cnt) return search_by_births(root->left,key);
    //search right subtree
    else return search_by_births(root->right,key);
}


