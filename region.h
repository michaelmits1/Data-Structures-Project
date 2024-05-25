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
};

//File Handling
node* read_csv_births(node* root, const string& filename);
node* read_csv_regions(node* root,const string& filename);

//Display menu
void displayMenu(node* root);

//Binary-tree
node* newNode(Region data);
void traverseInOrder(node *temp);
void print_node_equal_list(node* temp);
void print_node(node *temp);

//BIN_TREE_BIRTHS
node* insert_by_births(node* root,Region data);
node* search_by_births(node* root,int key);
node* find_min(node* root);
node* find_max(node* root);

//BIN_TREE_REGION
node* insert_by_region(node* root, Region data);
node* search_by_region(node* root, string region);
node* delete_node(node* root, const string& key);

#endif
