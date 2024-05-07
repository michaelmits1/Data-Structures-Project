#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/CLionProjects/dsproj/input.csv";
    int size = get_arrsize(fname);

    Region regions[size];
    read_csv(regions, fname);

    int size_births = get_arrsize_event(regions, size); //megethos tou pinaka genniseon

    //Orismos births, deaths arrays
    int i=0, j=0;
    Region births[size_births];
    Region deaths[size - size_births];

    for(const auto& region: regions){
        if(region.event){
            births[i++] = region;
        }
        else if(!region.event){
            deaths[j++] = region;
        }
    }

    //mergeSort(births, 0, size/2 -1);
    quicksort(births, 0, size_births);
    //Region* sorted_deaths = countsort(deaths, size/2 -1);
    //heapsort(births, size/2 -1);


    string birth_regions[100];
    find_regions(births, size_births, birth_regions);

    print_array_regions(births, size_births);


    return 0;
}