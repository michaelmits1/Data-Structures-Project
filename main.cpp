#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/datastrproj/Data-Structures-Project2/Data-Structures-Project/input.csv";
    node *root = nullptr;
    //root = read_csv_births(root, fname);
    root = read_csv_regions(root, fname);

    cout << "Inorder traversal:\n";
    traverseInOrder(root);

    return 0;
}
