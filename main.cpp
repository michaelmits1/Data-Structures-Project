#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/datastrproj/Data-Structures-Project2/Data-Structures-Project/input.csv";
    node *root = nullptr;

    //BIRTHS BST
    root = read_csv_regions_avl(root, fname);
    ultimate_extra_cool_hard_menu(root, fname);

    return 0;
}
