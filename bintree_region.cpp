#include "region.h"
using namespace std;

node* insert_by_region(node* root, Region data){
    //when you find empty child create a new node
    if (root == nullptr) return newNode(data);

    //search left subtree for empty node
    if (root->data.region > data.region) {
        root->left = insert_by_region(root->left, data);
        return root;
    }

    //search right subtree for empty node
    else if(root->data.region < data.region){
        root->right = insert_by_region(root->right, data);
        return root;
    }
    else {
        root->equalnext = insert_by_region(root->equalnext,data);
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

node* delete_node(node* root, const string& key) {
//    node *target = search_by_region(root, key);
//    if (target == nullptr) {
//        cout << "Region not found: " << key << endl;
//        return target;
//    }
//    if(target->right == nullptr && target->left == nullptr){
//        delete target;
//        return root;
//    }
//    //node with 1 child
//    if (target->left == nullptr) {
//        node *temp = target->right;
//        delete target;
//        return temp;
//    } else if (target->right == nullptr) {
//        node *temp = target->left;
//        delete target;
//        return temp;
//    }
//
//    //node with 2 sub-trees
//    node* sparent = target;
//    node* s = sparent->right;
//
//    while(s->left != nullptr){
//        sparent = s;
//        s = s->left;
//    }
//    //copy ta data tou successor sto target
//    target->data = s->data;
//
//    if(sparent->left == s && s->right != nullptr) sparent->left = s->right;    //an o successor exei node deksia tou tote ginete aristero node tou goniou tou
//
//    delete s;
//    return target;

//    node* temp = find_min(target->right);
//    target->data = temp->data;
//    target->right= delete_node(target->right, temp->data.region);
    if (root == nullptr) return root;

    if (key < root->data.region) {
        root->left = delete_node(root->left, key);
    } else if (key > root->data.region) {
        root->right = delete_node(root->right, key);
    } else {

        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        //Node with two children
        node* temp = find_min(root->right);

        //Copy the inorder successor's data to this node
        root->data = temp->data;

        //Delete the inorder successor
        root->right = delete_node(root->right, temp->data.region);
    }
    return root;
}
