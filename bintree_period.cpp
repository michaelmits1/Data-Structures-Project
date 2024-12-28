#include "region.h"
using namespace std;

node* insert_by_period(node* root,Region data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);
    //search left subtree for empty node
    if (data.period <root->data.period) {
        root->left=insert_by_period(root->left,data);
    }
    //search right subtree for empty node
    else if(data.period>root->data.period) {
        root->right=insert_by_period(root->right,data);
    }
    else {
        root->equalnext=insert_by_period(root->equalnext,data);
        return root;
    }
    lilwayne(root);
    return root;
}

node* search_by_period(node* root,string period){
    if (root==nullptr) return nullptr ;
    //check if the node contains key
    if(root->data.period==period)return root;
    //search left subtree
    else if(period < root->data.period) return search_by_period(root->left,period);
    //search right subtree
    else return search_by_period(root->right,period);
}//
