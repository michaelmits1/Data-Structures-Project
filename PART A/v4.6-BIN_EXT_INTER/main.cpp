#include "region.h"
#include "chrono"
#include "vector"
using namespace std;
using namespace chrono;
/*

template<typename Func>
double measuretime(Func sort, Region* list, int left, int right){
    auto start = chrono::high_resolution_clock::now();
    sort(list, left, right);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}
template<typename Func_search>
double measuretime_search(Func_search search, Region* list, int left, int right, int key){
    auto start = chrono::high_resolution_clock::now();
    search(list, left, right, key);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}
template<typename Func_search2>
double measuretime_search2(Func_search2 search, Region* list, int size , int key){
    auto start = chrono::high_resolution_clock::now();
    search(list, size, key);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

double calcmean(const vector<double>& values){
    if(values.empty()){
        cerr << "Error: No times saved" << endl;
        return 0.0;
    }
    double sum = accumulate(values.begin(), values.end(), 0.0);
    double mean = sum / static_cast<int>(values.size());
    return mean;
}
*/

int main(){
    string fname = "/home/mmitsainas/CLionProjects/dsproj/input.csv";
    int size = get_arrsize(fname);

    Region regions[size];
    read_csv(regions, fname);

    displayMenu(regions, size);


/*
    double standard_deviation = calculateStats(barray, size_births);
    cout << "SD = " << standard_deviation << endl;
    quicksort(barray, 0, size_births-1);    //sorting barray to search

    //BINARY SEARCH TIME CALCULATION:
    for(int j=0; j<10; ++j){
        for(int i=0; i<size_births; i++){
            double time = measuretime_search(bin_inter_extended_search, barray, size_births-1, barray[i].cnt);
            times.push_back(time);
        }
    }

    double mean_times = calcmean(times);
    cout << "algorithm mean time: " << mean_times << endl;

    double time1 = measuretime_search(bin_inter_search, barray, size_births, 777);
    double time2 = measuretime_search(bin_inter_extended_search, barray, size_births, 777);

    cout << "bin inter:  " << time1 << endl;
    cout << "bin exten:  " << time2 << endl;
*/

    return 0;
}

