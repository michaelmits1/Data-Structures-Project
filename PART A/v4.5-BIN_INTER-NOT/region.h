#ifndef REGION_H
#define REGION_H
#include "string"
#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "math.h"
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
void print_part_of_array(Region regions[],int start_index,int end_index,int size);

//Sorting
void merge(Region *Arr, int start, int mid, int end);
void mergeSort(Region *Arr, int start, int end);

void quicksort(Region *list, int left, int right);

Region* countsort(Region *inlist, int size);

void heapify(Region* list, int size, int root);
void heapsort(Region* list, int size);

//Searching
int bin_search(Region* list, int b1, int b2, int key);
int interpolation_search(Region *list, int key, int left, int right);
int bin_inter_search(Region* list, int size, int key);

void find_regions_bin(Region* arr,int size,int b1,int b2);
Region* find_regions_inter(Region *list, int size, Region found[]);
Region* find_regions_bin_inter(Region *list, int size, Region found[]);



#endif //REGION_H

