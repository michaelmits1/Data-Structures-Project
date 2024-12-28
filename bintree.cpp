#include "region.h"
using namespace std;

// New node creation
 node* newNode(Region key) {
    node* node =  new struct node; 
    if (node == nullptr) {
        cerr << "Memory allocation failed\n";
        exit(1);
    }
    node->data=key;
    node->left = nullptr;
    node->right = nullptr;
    node->equalnext=nullptr;
    node->height=-1;
  return node;
}

// Traverse Inorder
void traverseInOrder( node *temp) {
  if (temp != nullptr) {
    traverseInOrder(temp->left);
    print_node_equal_tree(temp);
    traverseInOrder(temp->right);
  }
}

void print_node_equal_tree(node* temp){
    print_node(temp);
      temp=temp->equalnext;
     
      traverseInOrder(temp);
}

void print_node(node *temp){
    if (temp==nullptr){
        cout<<"Key not found\n";
        return;
    }
    cout << "Period: " << temp->data.period << ", ";
    cout << "Event: " << (temp->data.event ? "Births" : "Deaths") << ", ";
    cout << "Region: " << temp->data.region << ", ";
    cout << "Count: " << temp->data.cnt <<",";
    cout<<endl;
}

void deletetree(node *temp){
  if (temp!=nullptr){
    deletetree(temp->left);
    deletetree(temp->equalnext);//delete secondary tree
    deletetree(temp->right);    
    delete temp;  
  }
}


/*void printBinaryTreeRegion(node* root, int space = 0, int height = 10) {
    if (root == nullptr) return;
    space += height;
    printBinaryTreeRegion(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << " ";
    cout << root->data.region << "\n";
    printBinaryTreeRegion(root->left, space);
}
void printBinaryTreePeriod(node* root, int space = 0, int height = 10) {
    if (root == nullptr) return;
    space += height;
    printBinaryTreePeriod(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << " ";
    cout << root->data.period << "\n";
    printBinaryTreePeriod(root->left, space);
}*/