#include "region.h"
using namespace std;

/*
- Xristis: dinei euros birth_cnt KAI key->birth_cnt OUTPUT: births[pos].region (EAN IPARXEI)
- [left, right] -> [b1, b2]
- key = arithmos genniseon pou psaxnei o xristis
- list[pos].region -> perioxi me ton arithmo genniseon (key).
*/
string interpolation_search(Region *list, int left, int right, int key, int b2){
    int i;
    //if(right > list[size-1].cnt || left > right) return "invalid span input.\n";

    while(left <= right && key >= list[left].cnt && key <= list[right].cnt){
        int pos = left + (((key - list[left].cnt) * (right - left)) / (list[right].cnt - list[left].cnt));

        //found
        if(list[pos].cnt == key){
            i = key;
            while(list[i].cnt != b2){
                cout << list[i].region << "\n";
                ++i;
            }
        }

        //continue search
        if(list[pos].cnt > key) right = pos - 1;
        else left = pos + 1;

    }
    return "KEY NOT FOUND\n";

}