#ifndef REGION_H
#define REGION_H
#include "string"
#include "vector"
#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"
using namespace std;

struct Region{
    string period;
    bool event;     //1:Birth, 0:Death
    string region;
    int cnt;
};

//File Handling
void read_csv(Region regions[],const string& filename);
void print_array_regions(Region regions[],int size);
int get_arrsize(const string& filename);
int get_arrsize_event(Region* list, int sizelist);

//Sorting
void merge(Region *Arr, int start, int mid, int end);
void mergeSort(Region *Arr, int start, int end);

void quicksort(Region *list, int left, int right);

Region* countsort(Region *inlist, int size);

void heapify(Region* list, int size, int root);
void heapsort(Region* list, int size);

//Searching
Region* interpolation_search(Region *list, int b1, int b2, int size, string regions[], int &res);


#endif //REGION_H
