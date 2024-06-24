#include "region.h"
using namespace std;

//  BINARY SEARCH
int bin_search(Region* list, int left, int right, int key){

    if(left >= right - 1) return left;

    int mid = (left + right) / 2;

    if (list[mid].cnt >= key) return bin_search(list, left, mid - 1, key);   //search left

    else return bin_search(list, mid + 1, right, key);                       //search right
}

//  INTERPOLATION SEARCH
int interpolation_search(Region* list, int left, int right, int key){
    if(left > right || list[left].cnt == list[right].cnt) return left;

    int medium = left + (((key - list[left].cnt) * (right - left)) / (list[right].cnt - list[left].cnt));
    medium = max(left, min(medium, right));

    if(list[medium].cnt == key) return medium;

    else if(list[medium].cnt > key) return interpolation_search(list, left, medium - 1, key);  //search left

    else if(list[medium].cnt < key) return interpolation_search(list, medium + 1, right, key);  //search right
}

//  BINARY INTERPOLATION SEARCH
int bin_inter_search(Region* list, int size , int key){
    if (key > list[size-1].cnt || key < list[0].cnt) return -1;

    int left = 0;
    int right = size-1;
    int len = right - left;
    int next = len * ((key - list[left].cnt) / (list[right].cnt - list[left].cnt));
    int step=0;

    while(key != list[next].cnt ){
        int i=0;
        len = right - left+1;
        step=(int)sqrt(len);

        if(len <= 3){
            for(int index=0; index < len; ++index){
                if(key != list[left].cnt) left++;
                else if(key == list[left].cnt) return left;
            }
            if(key != list[left].cnt) return next;
        }

        if(key >= list[next].cnt){
            while(key > list[next + i*step - 1].cnt){
                ++i;
                if(next + i * step-1 > size-1) break;
            }
            right = next + i * step;
            left = right - step;
        }

        else if(key < list[next].cnt){
            while(key < list[next - i*step + 1].cnt){
                ++i;
                if(next-i*step-1<0) break;
            }
            right=next-(i-1)*step;
            left=right-step;
        }

        if(list[left].cnt == list[right].cnt) next = left;
        else next = left- 1 + ((right - left+1) * (key - list[left].cnt) / (list[right].cnt - list[left].cnt));

        next = max(left, min(next, right));
    }
    return next;
}

//  BINARY INTERPOLATION SEARCH EXTENDED
int bin_inter_extended_search(Region* list, int size , int key){

    if (key > list[size-1].cnt || key < list[0].cnt) return -1;
    int left = 0;
    int right = size - 1;
    int next = left + ((key - list[left].cnt) * (right - left) / (list[right].cnt - list[left].cnt));
    if (next < left || next > right) return -1; // Check bounds

    while (left <= right) {
        int len = right - left + 1;

        if (len <= 5) {  // Direct linear search for small ranges
            for (int i = left; i <= right; ++i) {
                if (list[i].cnt == key) return i;
            }
            return -1;
        }

        if (list[next].cnt == key) return next;

        int step = (int)sqrt(len);
        int i = 1;

        if (key > list[next].cnt) {  // Search to the right
            while (next + i * step <= right && key > list[next + i * step].cnt) {
                i =i* 2;
            }
            left = next + (i / 2) * step;
            right = min(next + i * step, right);
            // cout<<"left: "<<left<<"|next: "<<next<<"|right: "<<right<<"\n";
            while (left+step < right) {
                int mid = left + (right - left) / 2;
                if (list[mid].cnt == key) return mid;
                else if (list[mid].cnt < key) left = mid + 1;
                else right = mid - 1;
            }
        } else {
            while (next - i * step >= left && key < list[next - i * step].cnt) {
                i =i*2;
            }
            right = next - (i / 2) * step;
            left = max(next - i * step, left);
            // cout<<"left: "<<left<<"|next: "<<next<<"|right: "<<right<<"\n";
            while (left+step < right) {
                int mid = left + (right - left) / 2;
                if (list[mid].cnt == key) return mid;
                else if (list[mid].cnt < key) left = mid + 1;
                else right = mid - 1;
            }
        }
        next = left + ((key - list[left].cnt) * (right - left) / (list[right].cnt - list[left].cnt));
    }
    return -1;
}

void find_region_bin(Region* arr, int size, int b1, int b2){
    int start_index = -1 ;
    int end_index = -1;

   start_index = bin_search(arr, 0, size-1, b1);
   if(start_index >= size || arr[start_index].cnt < b1){
       cout << "b1 greater than any element\n";
       return;
   }

   end_index = bin_search(arr, start_index, size-1, b2);

   if(end_index < start_index){
       cout << "Invalid range.\n";
       return;
   }

   print_part_of_array(arr, start_index, end_index, size);
}

void find_region_inter(Region* arr,int size,int b1,int b2){
    int start_index = -1 ;
    int end_index = -1;

    start_index = interpolation_search(arr, 0, size-1, b1);

    if(arr[start_index].cnt < b1) start_index++;

    if(start_index >= size || arr[start_index].cnt < b1){
        cout << "b1 greater than any element\n";
        return;
    }

    end_index = interpolation_search(arr, start_index, size-1, b2);

    if(end_index < start_index){
        cout << "Invalid range.\n";
        return;
    }

    print_part_of_array(arr, start_index, end_index, size);
}

void find_region_bin_inter(Region* arr,int size,int b1,int b2){
    int start_index=0;
    int end_index=size;

    start_index = bin_inter_search(arr, size, b1);
    if(arr[start_index].cnt < b1) start_index++;
    if (start_index == -1 || arr[start_index].cnt < b1) {
        cout << "b1 is greater than any elements\n";
        cout << start_index;
        return;
    }

    end_index = bin_inter_search(arr, size, b2);
    if (end_index == -1 || arr[end_index].cnt > b2) {
        end_index--;
    }
/*
    if (end_index < start_index) {
        cout << "Invalid range.\n";
        return;
    }*/

print_part_of_array(arr, start_index, end_index, size);
}

void find_region_bin_inter_extended(Region* arr,int size,int b1,int b2){
    int start_index=-1;
    int end_index=-1;
    if (arr[size-1].cnt<=b2) end_index=size-1;
    if (arr[0].cnt>=b1) start_index=0;
    while(b1<=b2 && start_index==-1){
        start_index=bin_inter_extended_search(arr,size,b1);
        b1++;
    }
    while(b1-1<=b2 && end_index==-1){
        end_index=bin_inter_extended_search(arr,size,b2);
        b2--;
    }
    print_part_of_array(arr,start_index,end_index,size);
}

/*
int linear(Region list[], int size, int start, int key){
    for(int i=start; i<size; ++i){
        if(list[i].cnt == key) return i;
    }
    return -1;
}
*/


