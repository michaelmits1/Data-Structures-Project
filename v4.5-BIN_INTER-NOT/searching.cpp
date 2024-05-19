#include "region.h"
using namespace std;

int bin_search(Region* list, int b1, int b2, int key){
    int mid = (b2 + b1) / 2;

    if(list[mid].cnt == key) return mid;

    else if(list[mid].cnt > key){
        if(b2 == b1) return -1 ;
        return bin_search(list, b1, mid - 1, key);  //search left
    }
    else if(list[mid].cnt < key){
        if (b2 == b1) return -1;
        return bin_search(list, mid + 1, b2, key);  //search right
    }
}


int interpolation_search(Region *list, int key, int left, int right) {
//    int left = 0;
//    int right = size-1;

    while(left <= right && key >= list[left].cnt && key <= list[right].cnt){

        int pos = left + (((key - list[left].cnt) * (right - left)) / (list[right].cnt - list[left].cnt));

        //found
        if(list[pos].cnt == key){
           return pos;
        }
        //continue search
        if(list[pos].cnt > key) right = pos - 1;
        else left = pos + 1;
    }
    return -1;
}

int bin_inter_search(Region* list, int size , int key){
    int left = 0;
    int right = size-1;
    int len = right - left;
    int next = left + (len * (key - list[left].cnt) / (list[right].cnt - list[left].cnt));
    int step;

    while(key != list[next].cnt){
        int i;
        len = right - left;

        //apeutheias grammiki anazitisi
        if(len <= 5){
            while(key != list[left].cnt) left++;
            next = left;
        }

        if(key > list[next].cnt){
            i=1;
            step = (int)sqrt(len);
            while(key > list[next + i*step - 1].cnt){
                right = next + (i+1)*step;
                left = next + i*step;
                ++i;
            }
        }
        else if(key < list[next].cnt){
            i=1;
            while(key < list[next - i*step + 1].cnt){
                right = next - (i-1)*step;
                left = next - i*(int) sqrt(len);
                ++i;
            }
        }
        next = left + ((right - left) * (key - list[left].cnt) / (list[right].cnt - list[left].cnt));
    }
    //found
    if(key == list[next].cnt) return next;
    // :(
    else return -1;
}

Region* find_regions_inter(Region *list, int size, Region found[]){
    int count=0;
    int b1, b2;
    cout << "span [b1, b2]: ";
    cin >> b1 >> b2;
    int p1 = b1;
    int p2 = b2;

    int pos1 = interpolation_search(list, p1, 0, size - 1);
    while(pos1 == -1){
        p1++;
        pos1 = interpolation_search(list, p1, 0, size - 1);
    }

    int pos2 = interpolation_search(list, p2, 0, size - 1);
    while(pos2 == -1){
        p2--;
        pos2 = interpolation_search(list, p2, 0, size - 1);
    }

    for(int i=pos1; i<=pos2; ++i){
        found[count++] = list[i];
    }
    while(list[pos2+1].cnt == list[pos2].cnt && stoi(list[pos2+1].period) != stoi(list[pos2-1].period)){
        found[count++] = list[pos2++];
    }


    if (count==0) {
        cout << "No regions found within the specified birth count range.\n";
    } else {
        cout << "Regions within the specified birth count range:\n";
        for (int i = 0; i < count; ++i) {
            cout << i+1 << ". ";
            cout << "Period: " << found[i].period << ", ";
            cout << "Region: " << found[i].region << ", ";
            cout << "Count: " << found[i].cnt << endl;
        }
    }
}

Region* find_regions_bin_inter(Region *list, int size, Region found[]){
    int count=0;
    int b1, b2;
    cout << "span [b1, b2]: ";
    cin >> b1 >> b2;
    int p1 = b1;
    int p2 = b2;

    int pos1 = bin_inter_search(list, size - 1, p1);
    while(pos1 == -1){
        p1++;
        pos1 = bin_inter_search(list, size - 1, p1);
    }

    int pos2 = bin_inter_search(list, size - 1, p2);
    while(pos2 == -1){
        p2--;
        pos2 = bin_inter_search(list, size - 1, p2);
    }

    for(int i=pos1; i<=pos2; ++i){
        found[count++] = list[i];
    }
    while(list[pos2+1].cnt == list[pos2].cnt && stoi(list[pos2+1].period) != stoi(list[pos2-1].period)){
        found[count++] = list[pos2++];
    }

    if (count==0) {
        cout << "No regions found within the specified birth count range.\n";
    } else {
        cout << "Regions within the specified birth count range:\n";
        for (int i = 0; i < count; ++i) {
            cout << i+1 << ". ";
            cout << "Period: " << found[i].period << ", ";
            cout << "Region: " << found[i].region << ", ";
            cout << "Count: " << found[i].cnt << endl;
        }
    }
}
void find_regions_bin(Region* arr,int size,int b1,int b2){
    int start_index=-1;
    int end_index=-1;
    while(b1<b2 && start_index==-1){
        start_index=bin_search(arr,0,size-1,b1);
        b1++;
    }
    while(b1<b2 && end_index==-1){
        end_index=bin_search(arr,0,size-1,b2);
        b2--;
    }
    print_part_of_array(arr,start_index,end_index,size);

}



