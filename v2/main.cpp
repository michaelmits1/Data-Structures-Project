#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/CLionProjects/dsproj/input.csv";
    vector<Region> regions = read_csv(fname);   //vector of structs region

    vector<Region> births;
    vector<Region> deaths;

    for(const auto& region: regions){
        if(region.event){
            births.push_back(region);
        }
        else if(!region.event){
            deaths.push_back(region);
        }
    }

    quicksort(births, 0, births.size()-1);      //QUICKSORT
    vector<Region> deaths_sorted = countsort(deaths);    //COUNTING SORT RETURNS NEW SORTED VECTOR

    cout << "BIRTHS_SORTED (QUICKSORT)" << endl;
    print_regions(births);

    cout << "\n" << "DEATHS_SORTED (COUNTING SORT)" << endl;
    print_regions(deaths_sorted);
    return 0;
}