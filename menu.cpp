#include "region.h"
using namespace std;


void HashingMenu(vector<node*>& htable) {
    int choice;
    node* temp=nullptr;
    string reg;
    string period;
    do {
         cout << "----C Menu----\n";
        cout << "1. Search for the count of births for a specific period and region\n";
        cout << "2. Edit the count of births for a specific period and region\n";
        cout << "3. Delete a record based on the region\n";
        cout << "4. Exit the program\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
             cout<<"Give a region to be searched: ";
              cin.ignore();
            getline(cin,reg);
             cout<<"Give a period to be searched: ";
             getline(cin,period);
            temp=search_htable(htable,reg,period);
            print_node(temp);

        } else if (choice == 2) {
             cout<<"Give a region to be searched: ";
            cin.ignore();
            getline(cin,reg);
             cout<<"Give a period to be searched: ";
              getline(cin,period);
            editnode(htable,reg,period);
            temp=search_htable(htable,reg,period);
            print_node(temp);
        }else if (choice == 3) {
            cout<<"Give a region to be searched: ";
             cin.ignore();
            getline(cin,reg);
             int hvalue= gethash(reg);
             htable[hvalue]=delete_node_region(htable[hvalue],reg);
        }
    } while (choice != 4);
}

void BirthMenu(node* root) {
    int choice;
    node* key;
    do {
         cout << "----B Menu----\n";
        cout << "1. Find Region/Regions with the MINIMUM NUMBER OF BIRTHS\n";
        cout << "2. Find Region/Regions with the MAXIMUM NUMBER OF BIRTHS\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
             key=find_min(root);
            print_node_equal_tree(key);
        } else if (choice == 2) {
            key=find_max(root);
            print_node_equal_tree(key);
        }
    } while (choice != 3);
}


void RegionMenu(node* root) {
    int choice;
    node* temp=nullptr;
    string reg;
    string period;
    int value;
    do {
         cout << "----A Menu----\n";
        cout << "1. Print BST with in-order traversal\n";
        cout << "2. Search for the count of births for a specific period and region\n";
        cout << "3. Edit the count of births for a specific period and region\n";
        cout << "4. Delete a record based on the region\n";
        cout << "5. Exit the program\n";   
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Inorder traversal:\n";
            traverseInOrder(root);
        }else if (choice == 2) {
           cout<<"Give a region to be searched: ";
              cin.ignore();
            getline(cin,reg);
             cout<<"Give a period to be searched: ";
             getline(cin,period);
            temp=search_by_region(root,reg);
            if (temp->data.period!=period) temp=search_by_period(temp->equalnext,period);
            print_node(temp);
        }else if (choice == 3) {
             cout<<"Give a region to be searched: ";
            cin.ignore();
            getline(cin,reg);
             cout<<"Give a period to be searched: ";
              getline(cin,period);
            temp=search_by_region(root,reg);
            if (temp->data.period!=period) temp=search_by_period(temp->equalnext,period);
            print_node(temp);
            if (temp==nullptr) return;
            cout<<"Give a value to be inserted: ";
            cin>> value;
            temp->data.cnt=value;
            print_node(temp);
        }else if (choice == 4) {
            cout<<"Give a region to be searched: ";
             cin.ignore();
            getline(cin,reg);
            root=delete_node_region(root,reg);
        }
    } while (choice != 5);
}