#ifndef REGION_H
#define REGION_H
#include "string"
#include "vector"
#include "iostream"
#include "fstream"
#include "sstream"
using namespace std;

struct Region{
    string period;
    bool event;     //1:Birth, 0:Death
    string region;
    int cnt;
};

vector<Region> read_csv(const string& fname);
void print_regions(const vector<Region>& regions);


#endif //REGION_H
