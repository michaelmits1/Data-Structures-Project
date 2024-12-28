#include "region.h"
using namespace std;

int main() {
    string fname = "C:\\Users\\Kostas\\Desktop\\DATABASES_PART_2\\bd-dec22-births-deaths-by-region.csv";
    node *root=nullptr;
    int d=11;
    int choice;
    cout << "----Menu----\n";
    cout << "1. Open A menu(bst based on regions)\n";
    cout << "2. Open B menu(bst based on birth count)\n";
    cout << "3. Open C menu(hashing table with bst chains)\n";
    cout << "Choose an option: ";
    cin >> choice;
    if (choice == 1) {
      root=read_csv_regions(root,fname);
      RegionMenu(root);
    } else if (choice == 2) {
      root=read_csv_births(root, fname);
      BirthMenu(root);
    }else if (choice == 3) {
       vector<node*> htable(d);
        read_csv_regions_htable(htable,fname);
        HashingMenu(htable);
    }
  
   /* //REGION BST
  root=read_csv_regions(root,fname);
    traverseInOrder(root);
    printBinaryTreeRegion(root,0,10);
   cout<<"AFTER DELETION\n";
   root=delete_node_region(root,"Nelson region");
   traverseInOrder(root);
    printBinaryTreeRegion(root,0,10);
    printBinaryTreePeriod(root->equalnext,0,10);*/

    return 0;
}

