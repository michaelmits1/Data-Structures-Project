#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/datastrproj/Data-Structures-Project2/Data-Structures-Project/input.csv";

    node *root = nullptr;

    //BIRTHS BST
    root = read_csv_regions_avl(root, fname);

    //cout << "Inorder traversal:\n";

    //node* item = search_by_births(root,12);
    //displayMenu(root);
    //print_node(item);
    //print_node_equal_tree(item);
    //node* node = delete_node_avl(root, "West Coast region");

    //REGION BST
    //root=read_csv_regions(root,fname);
    //node* node = delete_node(root, "Tasman region");
    //traverseInOrder(node);
    //displayMenu_region(root);

    //avl
    //traverseInOrder(root);
//    delete_node_avl(root, "Auckland region");
//    delete_node_avl(root, "Bay of Plenty region");
//    delete_node_avl(root, "Tasman region");
//    traverseInOrder(root);

    // Print the AVL tree structure
//    heightcalc(root);
//    printBinaryTree(root,0,10);
//    //cout<<"AFTER DELETION\n";
//    root = delete_node_avl(root,"Nelson region");
//    balance_node(root);
//    //heightcalc(root);
//    traverseInOrder(root);
//    printBinaryTree(root,0,10);
    displayMenu_avl(root);

    return 0;
}
