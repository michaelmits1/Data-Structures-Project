#include "region.h"
using namespace std;

// Mergesort
void merge(Region *Arr, int start, int mid, int end) {
    // create a temp array
    Region temp[end - start + 1];
    // crawlers for both intervals and for temp
    int i = start, j = mid+1, k = 0;
    // traverse both arrays and in each iteration add smaller of both elements in temp
    while(i<= mid && j <= end) {
        if(Arr[i].cnt<= Arr[j].cnt) {
            temp[k] = Arr[i];
            k += 1; i += 1;
        }
        else {
            temp[k] = Arr[j];
            k += 1; j += 1;
        }
    }
// add elements left in the first interval
    while(i <= mid) {
        temp[k] = Arr[i];
        k += 1; i += 1;
    }
    // add elements left in the second interval
    while(j <= end) {
        temp[k] = Arr[j];
        k += 1; j += 1;
    }
    // copy temp to original interval
    for(i = start; i <= end; i += 1) {
        Arr[i] = temp[i - start];
    }
}

void mergeSort(Region *Arr, int start, int end) {
    if(start < end) {
        int mid=(start + end) / 2;
        mergeSort(Arr, start, mid);
        mergeSort(Arr, mid+1, end);
        merge(Arr, start, mid, end);
    }
}

//Quicksort
void quicksort(Region *list, int left, int right){
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

//Countsort
Region* countsort(Region *inlist, int size){
    int m=0;

    for (int i = 0; i < size; ++i) {
        m = max(m, inlist[i].cnt);
    }

    int clist[m+1];      //counting list with inputs max val filled with 0
    for(int i=0; i<=m; ++i){
        clist[i]=0;
    }

    for(int i=0; i<size; ++i){
        clist[inlist[i].cnt]++;
    }
    for(int j=0; j <= m; ++j){
        clist[j] += clist[j-1];
    }

    //Region* outlist[size];
    Region* outlist = new Region[size];

    for(int i = size - 1; i >= 0; --i){
        outlist[clist[inlist[i].cnt] - 1] = inlist[i];
        clist[inlist[i].cnt]--;
    }
    return outlist;
}

//Heapsort (MaxHeap)
void heapify(Region* list, int size, int root){
    int largest = root;
    int l = 2*root + 1;     //left child
    int r = 2*root + 2;     //right child

    //left child > root
    if(l < size && list[l].cnt > list[largest].cnt) largest = l;

    //right child > largest(root)
    if(r < size && list[r].cnt > list[largest].cnt) largest = r;

    if(largest != root){
        swap(list[root], list[largest]);
        heapify(list, size, largest);
    }
}

void heapsort(Region* list, int size){
    for(int i=size/2 -1; i>=0; --i){
        heapify(list, size, i);
    }

    for(int i = size-1; i>0; --i){
        swap(list[0], list[i]);
        heapify(list, i, 0);
    }
}


