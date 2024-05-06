#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/CLionProjects/dsproj/input.csv";
    int size = get_arrsize(fname);

    Region regions[size];

    int size_births = get_arrsize_event(regions, size); //megethos tou pinaka genniseon

    Region births[size_births];
    Region deaths[size - size_births];

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
    quicksort(births, 0, size_births);

    //Region* sorted_deaths = countsort(deaths, size/2 -1);
    //heapsort(births, size/2 -1);

    int b1, b2, key;
    cout << "[b1, b2]: ";
    cin >> b1 >> b2;
    cout << "\nkey: ";
    cin >> key;

    string key_region = interpolation_search(births, 0, size_births, b1, b2);
    cout<< "NIGGA " << key_region;

    //print_array_regions(births, size_births);
    return 0;
}