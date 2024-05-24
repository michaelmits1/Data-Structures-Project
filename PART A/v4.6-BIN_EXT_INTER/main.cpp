#include "region.h"
#include "chrono"
using namespace std;
using namespace chrono;

int main() {
    string fname = "/home/mmitsainas/CLionProjects/dsproj/input.csv";
    int size = get_arrsize(fname);

    Region regions[size];
    read_csv(regions, fname);

    int size_births = get_arrsize_event(regions, size+1); //megethos tou pinaka genniseon

    //Orismos barray, darray arrays
    int i=0, j=0;
    Region barray[size_births];
    Region darray[size - size_births];

    for(const auto& region: regions){
        if(region.event){
            barray[i++] = region;
        }
        else if(!region.event){
            darray[j++] = region;
        }
    }

    //mergeSort(barray, 0, size/2 -1);
    quicksort(barray, 0, size_births - 1);
    //Region* sorted_deaths = countsort(darray, size/2 -1);
    //heapsort(barray, size/2 -1);
//    for(int p=0; p < size_births; p++){
//        cout << bin_inter_extented_search(barray,size_births,barray[p].cnt) << "\n";
//    }

    //Region birth_regions[100];
    //find_regions_bin_inter(barray, size_births, birth_regions);


    int ans = bin_inter_extented_search(barray, size_births, 303);
    cout << "\n" << ans;

    //cout << access(barray, 777, size_births);

    //print_array_regions(barray, size_births);


    return 0;
}