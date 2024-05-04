#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/CLionProjects/dsproj/input.csv";
    int size = get_arrsize(fname);

    Region regions[size];
    Region births[size/2];
    Region deaths[size/2];

    read_csv(regions, fname);
    int i=0, j=0;
    for(const auto& region: regions){
        if(region.event){
            births[i++] = region;
        }
        else if(!region.event){
            deaths[j++] = region;
        }
    }
    //mergeSort(births, 0, size/2 -1);
    //quicksort(births, 0, size/2 -1);

    //Region* sorted_deaths = countsort(deaths, size/2 -1);

    heapsort(births, size/2 -1);

    print_array_regions(sorted_deaths, size/2 -1);
    return 0;
}
