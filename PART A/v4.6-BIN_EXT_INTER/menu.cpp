#include "region.h"
using namespace std;


int secondary_menu(const string& s1,const string& s2){
    int option=0;
    cout<<"------------------------\n";
    cout<<"Press 1 for "<<s1<< endl;
    cout<<"Press 2 for "<<s2<< endl;
    cout << "Choose an option: ";
    cin >> option;
    return option;
}

void displayMenu(Region regions[], int size) {
    int size_births = get_arrsize_event(regions, size);

    Region barray[size_births];
    Region darray[size - size_births];

    int b=0,d=0;
    for (int i=0;i<size;i++){
        if(regions[i].event) barray[b++] = regions[i];
        else darray[d++] = regions[i];
    }

    int b1=0,b2=0;
    int choice;
    int sec_choise;
    do {
        cout << "----------Menu----------\n";
        cout << "1. Sort Regions by Birth Counts using Merge Sort or Quick Sort\n";
        cout << "2. Sort Regions by Death Counts using Heap Sort or Counting Sort\n";
        cout << "3. Find Regions Based on Birth Counts within a Given Range [b1, b2] Using Binary Search or Interpolation Search\n";
        cout << "4. Find Regions Based on Birth Counts within a Given Range [b1, b2] Using Binary Interpolation Search or Binary Interpolation Extended Search\n";
        cout << "5. Reset arrays\n";
        cout << "6. Exit program\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            sec_choise = secondary_menu("Merge Sort", "Quick Sort");
            if(sec_choise==1){
                mergeSort(barray,0,size_births-1);
                print_array_regions(barray, size_births);
            }else if(sec_choise==2){
                quicksort(barray,0,size_births-1);
                print_array_regions(barray, size_births);
            }
        }
        else if (choice == 2) {
            sec_choise = secondary_menu("Heap Sort", "Counting Sort");
            if(sec_choise==1){
                heapsort(darray, size - size_births);
                print_array_regions(darray, size - size_births);
            }else if(sec_choise==2){
                countsort(darray, size - size_births);
                print_array_regions(darray, size - size_births);
            }
        }
        else if (choice == 3) {
            sec_choise=secondary_menu("Binary Search","Interpolation Search");
            cout<<"Give a specific range:\n";
            cin>>b1;
            cin>>b2;
            if(sec_choise==1){
                quicksort(barray, 0, size_births-1);
                find_region_bin(barray,size_births,b1,b2);
            }else if(sec_choise==2){
                quicksort(barray,0,size_births-1);
                find_region_inter(barray,size_births, b1, b2);
            }
        }
        else if (choice == 4) {
            sec_choise = secondary_menu("Binary Interpolation Search","Binary Interpolation Extented Search");
            cout<<"Give a specific range:\n";
            cin>>b1;
            cin>>b2;
            if(sec_choise==1){
                mergeSort(barray,0,size_births-1);
                find_region_bin_inter(barray,size_births,b1,b2);
            }else if(sec_choise==2){
                mergeSort(barray,0,size_births-1);
                find_region_bin_inter_extended(barray,size_births,b1,b2);
            }
        }
        else if (choice == 5) {
            int b=0, d=0;
            for (int i=0;i<size;i++){
                if(regions[i].event==1) barray[b++]=regions[i];
                else darray[d++]=regions[i];
            }
        }
    } while (choice != 6);
}

