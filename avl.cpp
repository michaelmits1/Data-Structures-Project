#include "region.h"
using namespace std;

int heightcalc(node* temp){
    if (temp==nullptr) return -1;//when you find empty node return -1
    temp->height=max(heightcalc(temp->left),heightcalc(temp->right))+1;
    return temp->height;
}

int b_factor(node *temp) {
    int left_height=-1;
    int right_height=-1;
    if(temp->left!=nullptr){
        left_height=temp->left->height;
         
        if(left_height==-1){
            left_height=heightcalc(temp->left);
        }
    } 
    if(temp->right!=nullptr) {
        right_height=temp->right->height;
        
        if(right_height==-1){
            right_height=heightcalc(temp->right);
        }   
    }
        temp->height=max(left_height,right_height)+1;
        return left_height-right_height;//left.height-right.height
}


// B FACTOR : -1,0,1 


void rotate_left(node *a){
    node *b=a->right;
    node* c=b->left;
    node* d=a->left;
    //make a copy of data of a
    Region data=a->data;
    node* equalnext=a->equalnext;
    //assign p as the parent of b
   a->data=b->data;
    a->right=b->right;
    a->left=b;
    a->equalnext=b->equalnext;
    //assign b as the parent of a 
    b->right=c;//assign a as the parent of c 
    b->left=d;
    b->data=data;  
    b->equalnext=equalnext;
}

void rotate_right(node *a){
     node *b=a->left;
    node* c=b->right;
    node* d=a->right;
    //make a copy of data of a
    Region data=a->data;
    node* equalnext=a->equalnext;
    //assign p as the parent of b
    a->data=b->data;
    a->right=b;
    a->left=b->left;
    a->equalnext=b->equalnext;
    //assign b as the parent of a 
    b->right=d;
    b->left=c;
    b->data=data;  
    b->equalnext=equalnext;
}


void lilwayne(node* a){
     int balancefactor=b_factor(a);
    if (balancefactor>1){
        if(b_factor(a->left)>=0){
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
    else if(balancefactor<-1){
        if(b_factor(a->right)<=0) {
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


