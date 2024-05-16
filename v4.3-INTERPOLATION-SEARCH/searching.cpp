#include "region.h"
using namespace std;


int interpolation_search(Region *list, int key, int size, int left, int right){
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

Region* find_regions(Region *list, int size, Region found[]){
    int count=0;
    int b1, b2;
    cout << "span [b1, b2]: ";
    cin >> b1 >> b2;
    int p1 = b1;
    int p2 = b2;

    int pos1 = interpolation_search(list, b1, size, 0, size-1);
    while(pos1 == -1){
        pos1 = interpolation_search(list, p1, size, 0, size-1);
        p1++;
    }

    int pos2 = interpolation_search(list, p2, size, 0, size-1);
    while(pos2 == -1) {
        pos2 = interpolation_search(list, p2, size, 0, size-1);
        p2--;
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

//void find_regions(Region* list, int size){
//    int start_index = -1;
//    int end_index = -1;
//
//    int b1, b2;
//    cout << "span [b1, b2]: ";
//    cin >> b1 >> b2;
//
//    while(b1<b2 && start_index == -1){
//        start_index = interpolation_search(list, )
//    }
//
//}

bool access(Region* list, int key, int size){
    int left = 1;
    int right = size;
    int len = right - left + 1;
    int next = len * ((key - list[left].cnt)/(list[right].cnt - list[left].cnt)) + 1;

    while(key != list[next].cnt){
        int i=0;
        len = right - left + 1;

        //apeutheias grammiki anazitisi
        if(len <= 5){
            for(int j=0; j < len; ++j){
                if(list[j].cnt == key) return true; //found
            }
        }

        if(key > list[next].cnt){
            while(key > list[next + i*(int)sqrt(len) - 1].cnt) ++i;

            right = next + i*(int) sqrt(len);
            left = next + (i-1)*(int) sqrt(len);
        }
        else if(key < list[next].cnt){
            while(key < list[next - i*(int)sqrt(len) + 1].cnt) ++i;

            right = next - (i-1)*(int) sqrt(len);
            left = next - i*(int) sqrt(len);
        }

        next = left + len*((key - list[left].cnt)/(list[right].cnt - list[left].cnt)) - 1;
    }

    //found
    if(key == list[next].cnt) return true;
    else return false;
}

