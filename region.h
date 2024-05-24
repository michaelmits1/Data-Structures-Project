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
};

//File Handling
node* read_csv(node* root,const string& filename);
//Display menu

//Binary-tree
node* newNode(Region data);
node* insert(node* root,Region data);
void traverseInOrder( node *temp,int counter);

#endif
