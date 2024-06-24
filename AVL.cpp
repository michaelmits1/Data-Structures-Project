#include "region.h"
using namespace std;

int heightcalc(node* temp){
    if (temp==nullptr) return -1; //when you find empty node return -1
    return max(heightcalc(temp->left), heightcalc(temp->right)) + 1;
}

int b_factor(node *temp){
    int left_height = -1;
    int right_height = -1;

    if(temp->left != nullptr){
        left_height = temp->left->height;

        if(left_height == -1){
            left_height = heightcalc(temp->left);
        }
    }
    if(temp->right != nullptr) {
        right_height = temp->right->height;

        if(right_height == -1){
            right_height = heightcalc(temp->right);
        }
    }
    temp->height = max(left_height, right_height) + 1;
    return left_height - right_height;    //left.height-right.height
}

void rotate_left(node *a) {
    node* b = a->right;
    node* c = b->left;
    node* d = a->left;

    //make a copy of data of a
    Region data = a->data;
    node* equalnext = a->equalnext;

    //assign p as the parent of b
    a->data = b->data;
    a->right = b->right;
    a->left = b;
    a->equalnext = b->equalnext;

    //assign b as the parent of a
    b->right = c;
    b->left = d;
    b->data = data;
    b->equalnext = equalnext;
}
void rotate_right(node *a){
    node* b = a->left;
    node* c = b->right;
    node* d = a->right;

    // Make a copy of data of a
    Region data = a->data;
    node* equalnext = a->equalnext;

    // Assign p as the parent of b
    a->data = b->data;
    a->right = b;
    a->left = b->left;
    a->equalnext = b->equalnext;

    // Assign b as the parent of a
    b->right = d;
    b->left = c;
    b->data = data;
    b->equalnext = equalnext;
}

void balance_node(node* a){
    int bf = b_factor(a);

    if (bf > 1){
        if(b_factor(a->left) >= 0){
            rotate_right(a);
            heightcalc(a);
        }
        else {
            rotate_left(a->left);
            rotate_right(a);
            heightcalc(a);
        }
        return;
    }
    else if(bf < -1){
        if(b_factor(a->right) <= 0) {
            rotate_left(a);
            heightcalc(a);
        }
        else{
            rotate_right(a->right);
            rotate_left(a);
            heightcalc(a);
        }
    }
}


node* delete_node(node* root, const string& key) {
    if (root == nullptr) return root;

    if (key < root->data.region) root->left = delete_node(root->left, key);

    else if (key > root->data.region) root->right = delete_node(root->right, key);

    else{

        if (root->equalnext != nullptr){
            deletetree(root->equalnext);
        }

        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left == nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            node* temp = find_min(root->right);
            //copy data from the successor
            root->data = temp->data;
            //delete successor from the subtree
            root->right = delete_node(root->right, temp->data.region);
        }
    }
    balance_node(root);
    return root;
}



