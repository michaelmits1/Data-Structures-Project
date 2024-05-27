#include "region.h"
using namespace std;

int heightcalc(node* temp){
    if (temp==nullptr) return -1; //when you find empty node return -1
    return max(heightcalc(temp->left), heightcalc(temp->right)) + 1;
}

int geth(node* node){
    if(node == nullptr) return -1;
    else return node->height;
}

int b_factor(node *temp) {
    int left_height = -1;
    int right_height = -1;

    if(temp->left != nullptr){
        if(temp->left->height == -1) left_height = heightcalc(temp->left);
        else left_height = temp->left->height;
    }
    if(temp->right!=nullptr) {
        if(temp->right->height == -1) left_height = heightcalc(temp->right);
        else left_height = temp->right->height;
    }
    return left_height - right_height;
}

void rotate_left(node *a){
    node* b = a->right;
    node* c = b->left;

    //make a copy of data of a
    Region data = a->data;
    node* equalnext = a->equalnext;

    //rotation
    b->left = a;
    a->right = c;

    b->data = data;
    b->equalnext = equalnext;
}

void rotate_right(node *a){
    node* b = a->left;
    node* c = b->right;

    //make a copy of data of a
    Region data = a->data;
    node* equalnext = a->equalnext;

    //rotation
    b->right = a;
    a->left = c;

    b->data = data;
    b->equalnext = equalnext;
}


void balance_node(node* a){
    int bf = b_factor(a);

    if (bf > 1){
        if(b_factor(a->left) >= 0){
            rotate_right(a);
            heightcalc(a);
            cout<<"right rotate\n";
        }
        else {
            rotate_left(a->left);
            rotate_right(a);
            heightcalc(a);
            cout<<"left right rotate\n";
        }
        return;
    }
    else if(bf < -1){
        if(b_factor(a->right)<=0) {
            rotate_left(a);
            heightcalc(a);
            cout<<"left rotate\n";
        }
        else{
            rotate_right(a->right);
            rotate_left(a);
            heightcalc(a);
            cout<<"right left rotate\n";
        }
    }
}

node* insert_by_region_avl(node* root, const Region& data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);

    //search left subtree for empty node
    if (data.region < root->data.region) {
        root->left = insert_by_region_avl(root->left, data);
        root->height = -1;
    }

        //search right subtree for empty node
    else if(data.region > root->data.region) {
        root->right = insert_by_region_avl(root->right,data);
        root->height = -1;
    }
    else if(data.region == root->data.region) {
        root->equalnext = insert_by_region_avl(root->equalnext,data);
        return root;
    }
    balance_node(root);
    return root;
}


// Function to delete a node in the AVL tree
node* delete_node_avl(node* root, const string& key) {
    if (root == nullptr)
        return root;

    if (key < root->data.region) {
        root->left = delete_node_avl(root->left, key);
    } else if (key > root->data.region) {
        root->right = delete_node_avl(root->right, key);
    } else {
        if (root->equalnext != nullptr) {
            root->equalnext = nullptr; // If there is an equalnext node, it is removed
            return delete_node_avl(root, key); // Call delete again to handle the main node
        }

        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        node* temp = find_min(root->right);

        // Copy the inorder successor's content to this node
        root->data.region = temp->data.region;

        // Delete the inorder successor
        root->right = delete_node_avl(root->right, temp->data.region);
    }

    // Update the height of the current node
    root->height = 1 + max(geth(root->left), geth(root->right));

    return root;
}