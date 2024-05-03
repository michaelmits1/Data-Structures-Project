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

vector<Region> read_csv(const string& fname);
void print_regions(const vector<Region>& regions);

void quicksort(vector<Region>& list, int left, int right);
vector<Region> countsort(vector<Region>& inlist);


#endif //REGION_H

