#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/datastrproj/Data-Structures-Project2/Data-Structures-Project/input.csv";

    node *root = nullptr;

    //BIRTHS BST
    root = read_csv_regions(root, fname);

    //cout << "Inorder traversal:\n";

    //node* item = search_by_births(root,12);
    //displayMenu(root);
    //print_node(item);
    //print_node_equal_list(item);

    //REGION BST
    //root=read_csv_regions(root,fname);
    //delete_node(root, "Athens");
    traverseInOrder(root);

    return 0;
}
