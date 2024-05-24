#ifndef REGION_H
#define REGION_H

#include "string"
//#include "vector"
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

//Binary-tree
node* newNode(Region data);
node* insert_by_births(node* root, Region data);
node* insert_by_region(node* root, Region data);

node* search(node* root, int key);
node* find_min(node* root);
node* find_max(node* root);
void traverseInOrder( node *temp);
void print_node_equal_list(node* temp);
void print_node(node *temp);

#endif
