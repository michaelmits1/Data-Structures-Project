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

    if(temp->left!=nullptr) left_height = temp->left->height;
    if(temp->right!=nullptr) right_height = temp->right->height;

    return left_height-right_height;    //left.height-right.height
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

    a->height = max(geth(a->left), geth(a->right)) + 1;
    b->height = max(geth(b->left), geth(b->right)) + 1;

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

    a->height = max(geth(a->left), geth(a->right)) + 1;
    b->height = max(geth(b->left), geth(b->right)) + 1;

    b->data = data;
    b->equalnext = equalnext;
}


void balance_node(node* a){
    int bf = b_factor(a);

    if (bf > 1){
        if(b_factor(a->left) >= 0){
            rotate_right(a);
            cout<<"right rotate\n";
        }
        else {
            rotate_left(a->left);
            rotate_right(a);
            cout<<"left right rotate\n";
        }
        return;
    }
    else if(bf < -1){
        if(b_factor(a->right)<=0) {
            rotate_left(a);
            cout<<"left rotate\n";
        }
        else{
            rotate_right(a->right);
            rotate_left(a);
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
    }

        //search right subtree for empty node
    else if(data.region > root->data.region) {
        root->right=insert_by_region_avl(root->right,data);
    }
    else if(data.region == root->data.region) {
        root->equalnext=insert_by_region(root->equalnext,data);
        return root;
    }
    balance_node(root);
    return root;
}