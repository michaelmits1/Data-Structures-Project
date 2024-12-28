#include "region.h"
using namespace std;

node* insert_by_region(node* root, Region data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);

    //search left subtree for empty node
    if (data.region < root->data.region) {
        root->left = insert_by_region(root->left, data);
    }

        //search right subtree for empty node
    else if(data.region > root->data.region) {
        root->right=insert_by_region(root->right,data);
    }
    else {
        root->equalnext=insert_by_period(root->equalnext,data);
        return root;
    }
    lilwayne(root);
    return root;
}//


node* search_by_region(node* root,string region){
    if (root==nullptr) return nullptr ;
    //check if the node contains key
    if(root->data.region==region)return root;
    //search left subtree
    else if(region < root->data.region) return search_by_region(root->left,region);
    //search right subtree
    else return search_by_region(root->right,region);
}

node* delete_node_region(node* temp, string key){
  if (temp==nullptr){
    cout<<"no such key to be deleted\n";
    return temp;
  } 
  if (key < temp->data.region) {
    temp->left = delete_node_region(temp->left, key);
  }
  else if (key > temp->data.region) {
    temp->right = delete_node_region(temp->right, key);
  }
  else{
    if(temp->left==nullptr && temp->right==nullptr) {//if the node is a leaf just delete
        cout<<"leaf\n";
        deletetree(temp->equalnext);  
        delete temp;
        return nullptr;
    }
    else if (temp->right==nullptr){//no right child
        cout<<"no right child\n";
        node* left=temp->left;
        deletetree(temp->equalnext);
        delete temp;
        return left;
    }
    else if (temp->left==nullptr){//no lieft child
        cout<<"no left child\n";
        node* right=temp->right;
        deletetree(temp->equalnext);
        delete temp;
        return right;
    }
    else{// two children ,swap node with the next minimum value 
        cout<<"two children\n";
        node* minvalue=find_min(temp->right);
        deletetree(temp->equalnext);
        //swap node with min value of the right subtree of the temp node
        temp->data=minvalue->data;
        temp->equalnext=minvalue->equalnext;
        temp->right=delete_node_region(temp->right,minvalue->data.region);
    }
  } 
   lilwayne(temp);
    return temp;
}
