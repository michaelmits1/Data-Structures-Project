#include "region.h"
using namespace std;

node* insert_by_region(node* root, Region data){
    //when you find empty child create a new node
    if (root == nullptr) return newNode(data);

    //search left subtree for empty node
    if (root->data.region > data.region) {
        root->left = insert_by_region(root->left, data);
        return root;
    }

    //search right subtree for empty node
    else if(root->data.region < data.region){
        root->right = insert_by_region(root->right, data);
        return root;
    }
    else {
        root->equalnext = insert_by_period(root->equalnext, data);
        return root;
    }
}
node* search_by_region(node* root, string region){
    if(root == nullptr) return nullptr;

    //check if the node contains key
    if(root->data.region == region) return root;

    //search left subtree
    else if(region < root->data.region) return search_by_region(root->left, region);

    //search right subtree
    else return search_by_region(root->right, region);
}


node* delete_node(node* root, const string& key){
    if (root == nullptr) return root;

    if (key < root->data.region) root->left = delete_node(root->left, key);

    else if (key > root->data.region) root->right = delete_node(root->right, key);

    else{

        if (root->equalnext != nullptr){
            delete_equalnext_bintree(root->equalnext);
        }

        if (root->left == nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }

        //node with 2 sub-trees
        node* sparent = root;
        node* s = sparent->right;

        while(s->left != nullptr){
            sparent = s;
            s = s->left;
        }
        //copy ta data tou successor sto target
        root->data = s->data;
        root->equalnext = s->equalnext;

        if(sparent->left == s) sparent->left = s->right;    //an o successor exei node deksia tou tote ginete aristero node tou goniou tou
        else sparent->right = s->right;

        delete s;
        return root;
    }
    return root;
}

node* search_by_region_period(node* root){
    string period, region;
    cout << "Region: ";
    cin.ignore();
    getline(cin, region);

    cout << "Period: ";
    cin >> period;

    node* target = search_by_region(root, region);
    if(target == nullptr) return nullptr;

    if(target->data.period == period) return target;

    else if(target->equalnext != nullptr){
        node* target1 = search_by_period(target->equalnext, period);

        if(target1 == nullptr) return nullptr;
        else if(target1->data.period == period) return target1;
        else return nullptr;
    }
    else return nullptr;
}

void edit_birth(node* root){
    int new_cnt;
    node* node = search_by_region_period(root);
    print_node(node);
    cout << "Current Birth count: " << node->data.cnt << "\nInsert new Birth count: ";
    cin >> new_cnt;

    node->data.cnt = new_cnt;
    print_node(node);
}

void displayMenu_region(node* root){
    int choice;
    do {
        cout << "----Menu----\n";
        cout << "1. Display Binary Search Tree using INORDER Traversal\n";
        cout << "2. Search BIRTH count by REGION and PERIOD\n";
        cout << "3. Edit BIRTH count\n";
        cout << "4. Delete node by REGION\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                traverseInOrder(root);
                break;
            case 2: {
                node* temp = search_by_region_period(root);
                print_node(temp);
                break;
            }
            case 3:
                edit_birth(root);
                break;
            case 4: {
                string period, region;
                cout << "Region: ";
                cin.ignore();
                getline(cin, region);
                delete_node(root, region);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please choose a valid option.\n";
        }
    } while (choice != 5);
}
