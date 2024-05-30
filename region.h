#ifndef REGION_H
#define REGION_H

#include "string"
#include "vector"
#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "iostream"
#include "cstdlib"
using namespace std;

struct Region{
    string period;
    bool event;     //1:Birth, 0:Death
    string region;
    int cnt;
};

struct node {
    Region data;
    struct node *left;
    struct node *right;
    struct node *equalnext;
    int height;
};

//File Handling
node* read_csv_births(node* root, const string& filename);
node* read_csv_regions(node* root,const string& filename);
node* read_csv_regions_avl(node* root,const string& filename);

//Display menu
void displayMenu_births(node* root);
void displayMenu_region(node* root);
void displayMenu_avl(node* root);

//Binary-tree
node* newNode(Region data);
void traverseInOrder(node *temp);
void print_node_equal_tree(node* temp);
void print_node(node *temp);
void printBinaryTree(node* root, int space, int height);

//BIN_TREE_BIRTHS
node* insert_by_births(node* root,Region data);
node* search_by_births(node* root,int key);
node* find_min(node* root);
node* find_max(node* root);

//BIN_TREE_REGION
node* insert_by_region(node* root, Region data);
node* search_by_region(node* root, string region);
void delete_equalnext_bintree(node *temp);
node* delete_node(node* root, const string& key);
node* search_by_region_period(node* root);
void edit_birth(node* root);

//BIN_TREE_PERIOD
node* search_by_period(node* root, const string& period);
node* insert_by_period(node* root, const Region& data);

//AVL TREE
int heightcalc(node* temp);
int b_factor(node *temp);
void rotate_left(node *a);
void rotate_right(node *a);
void balance_node(node* a);
node* insert_by_region_avl(node* root, const Region& data);
int geth(node* node);
node* delete_node_avl(node* root, const string& key);



#endif
