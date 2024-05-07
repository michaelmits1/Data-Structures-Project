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

    int b1, b2;
    cout << "[b1, b2]: ";
    cin >> b1 >> b2;

    const int maxRegions = 100;
    string birth_regions[maxRegions];
    int res_size = 0;   //actual number of regions found

    interpolation_search(births, b1, b2, size_births, birth_regions, res_size);

    print_array_regions(births, size_births);
    if (res_size==0) {
        cout << "No regions found within the specified birth count range.\n";
    } else {
        cout << "Regions within the specified birth count range:\n";
        for (int i = 0; i < res_size; ++i) {
            cout << birth_regions[i] << endl;
        }
    }
    return 0;
}