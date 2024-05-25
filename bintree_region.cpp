#include "region.h"
using namespace std;

node* insert_by_region(node* root, Region data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);

    //search left subtree for empty node
    if (data.region <= root->data.region) {
        root->left = insert_by_region(root->left, data);
    }

    //search right subtree for empty node
    else if(data.region > root->data.region){
        root->right = insert_by_region(root->right, data);
    }
    else {
        root->equalnext=insert_by_region(root->equalnext,data);
        return root;
    }
}
node* search_by_region(node* root, string region){
    if(root == nullptr) return nullptr;

    //check if the node contains key
    if(root->data.region == region) return root;

    //search left subtree
    else if(region < root->data.region) return search_by_region(root->left, region);

    //search right subtree
    else return search_by_region(root->right, region);
}

//node* delete_node(node* root, const string& key){
//    node* target = search_by_region(root, key);
//    if(target == nullptr){
//        cout << "Region not found: " << key << endl;
//        return root;
//    }
//
//    if(target->equalnext != nullptr){
//        node* temp = target->equalnext;
//        delete target;
//        return temp;
//    }
//
//    //node 1 or 0 children
//    if(target->left == nullptr){
//        node* temp = target->right;
//        delete target;
//        return temp;
//    }
//    else if(target->right == nullptr){
//        node* temp = target->left;
//        delete target;
//        return temp;
//    }
//
//    //node with 2 sub-trees
//    node* temp = find_min(root->right);
//    target->data = temp->data;
//
//    delete target->right;
//
//    return target;
//
//}
