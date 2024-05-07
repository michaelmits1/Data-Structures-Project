#include "region.h"
using namespace std;

/*
- Xristis: dinei euros birth_cnt KAI b1->birth_cnt OUTPUT: births[pos].region (EAN IPARXEI)
- [left, right] -> [b1, b2]
- b1 = arithmos genniseon pou psaxnei o xristis
- list[pos].region -> perioxi me ton arithmo genniseon (b1).
*/
Region* interpolation_search(Region *list, int b1, int b2, int size, string regions[], int &res){
    int count=0;
    int left = 0;
    int right = size-1;
    //if(right > list[size-1].cnt || left > right) return "invalid span input.\n";

    while(left <= right && b1 >= list[left].cnt && b1 <= list[right].cnt){

        int pos = left + ((double)(right - left) / (list[right].cnt - list[left].cnt)) * (b2 - list[left].cnt);

        if(list[pos].cnt < b1) left = pos+1;
        else if(list[pos].cnt > b2) right = pos-1;
        else{
            regions[count++] = list[pos].region;

            int low = pos - 1;
            while(low >= left && list[low].cnt >= b1){
                regions[count++] = list[low--].region;
            }
            int high = pos + 1;
            while(high <= right && list[high].cnt <= b2){
                regions[count++] = list[high++].region;
            }
            break;
        }

    }
    res = count;
}