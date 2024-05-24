#include "region.h"
using namespace std;

void quicksort(vector<Region>& list, int left, int right){
    int pivot, l, r;    //pivot, left arrow, right arrow
    l = left;           //left arrow = left most element in list
    r = right;
    pivot = list[(left + right) / 2].cnt;

    while(r >= l){
        while(list[r].cnt > pivot) --r; //
        while(list[l].cnt < pivot) ++l;

        if(l <= r){
            swap(list[l], list[r]);
            ++l;
            --r;
        }
    }

    if(left < r) quicksort(list, left, r);
    if(l < right) quicksort(list, l, right);
}

vector<Region> countsort(vector<Region>& inlist){
    int m=0;

    for(const Region& region : inlist){        //max value from input
        m = max(m, region.cnt);
    }

    vector<int> clist(m+1, 0);  //counting list with inputs max val filled with 0

    for(const Region& region: inlist){
        clist[region.cnt]++;
    }
    for(int j=0; j <= m; ++j){
        clist[j] += clist[j-1];
    }

    vector<Region> outlist(inlist.size());

    for(int i = inlist.size() - 1; i >= 0; --i){
        outlist[clist[inlist[i].cnt] - 1] = inlist[i];
        clist[inlist[i].cnt]--;
    }
    return outlist;
}