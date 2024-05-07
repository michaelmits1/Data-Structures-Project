#include "region.h"
using namespace std;


int interpolation_search(Region *list, int key, int size){
    int left = 0;
    int right = size-1;

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

Region* find_regions(Region *list, int size, string found[]){
    int count=0;
    int b1, b2;
    cout << "span [b1, b2]: ";
    cin >> b1 >> b2;

    for(int i=b1; i<=b2; ++i){
        int pos = interpolation_search(list, i, size);
        if(pos != -1){
            found[count++] = list[pos].region;
        }
    }

    if (count==0) {
        cout << "No regions found within the specified birth count range.\n";
    } else {
        cout << "Regions within the specified birth count range:\n";
        for (int i = 0; i < count; ++i) {
            cout << found[i] << endl;
        }
    }

}
