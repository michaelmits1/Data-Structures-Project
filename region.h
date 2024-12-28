#ifndef REGION_H
#define REGION_H
#include "string"
#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "iostream"
#include "cstdlib"
#include "vector"
#include "bits/stdc++.h"
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
void read_csv_regions_htable(vector<node*>& htable,const string& filename);
//Binary-tree
node* newNode(Region data);
void traverseInOrder( node *temp); 
void print_node_equal_tree(node* temp);
void print_node(node *temp);
void deletetree(node *temp);
void printBinaryTreePeriod(node* root, int space, int height) ;
void printBinaryTreeRegion(node* root, int space, int height) ;
//BIN_TREE_BIRTHS
node* insert_by_births(node* root,Region data);
node* search_by_births(node* root,int key);
node* find_min(node* root);
node* find_max(node* root);
//BIN_TREE_REGION
node* insert_by_region(node* root, Region data);
node* search_by_region(node* root,string region);
node* delete_node_region(node* temp, string key);
//BIN_TREE_PERIOD
node* insert_by_period(node* root,Region data);
node* search_by_period(node* root,string period);
//AVL
int heightcalc(node* temp);
int b_factor(node *temp);
void lilwayne(node* a);
void rotate_right(node *a);
void rotate_left(node *a);
//hashing
int gethash(string Region);
void insert_htable(vector<node*>& htable,Region data);
node* search_htable(vector<node*>& htable,string region,string period);
void print_htable(vector<node*>& htable);
void editnode(vector<node*>& htable,string reg,string period);
//MENU
void BirthMenu(node* root);
void HashingMenu(vector<node*>& htable);
void RegionMenu(node* root);
#endif //REGION_H