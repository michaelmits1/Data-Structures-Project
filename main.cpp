#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/datastrproj/Data-Structures-Project2/Data-Structures-Project/input.csv";
    node *root=nullptr;
    root=read_csv(root, fname);
    cout << "Inorder traversal:\n";
    traverseInOrder(root,0);

    return 0;
}
