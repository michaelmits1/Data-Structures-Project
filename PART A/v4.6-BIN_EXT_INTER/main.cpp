#include "region.h"
#include "chrono"
#include "vector"
using namespace std;
using namespace chrono;


int main(){
    string fname = "/home/mmitsainas/CLionProjects/dsproj/input.csv";

    int size = get_arrsize(fname);
    Region regions[size];

    read_csv(regions, fname);

    displayMenu(regions, size);

    return 0;
}

