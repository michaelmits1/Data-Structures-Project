#include "region.h"
using namespace std;

int main() {
    string fname = "/home/mmitsainas/CLionProjects/dsproj/input.csv";

    vector<Region> regions = read_csv(fname);   //vector of structs region
    print_regions(regions);

    return 0;
}