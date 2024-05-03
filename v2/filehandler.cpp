#include "region.h"
using namespace std;

vector<Region> read_csv(const string& fname){
    vector<Region> regions;
    ifstream file(fname);
    string line;

    if(!file.is_open()) {cerr << "Failed to open file.\n"; return regions;}

    while(getline(file, line)){
        stringstream ss(line);
        string p, e, r, c;

        if(getline(ss, p, ',') && getline(ss, e, ',') && getline(ss, r, ',') && getline(ss, c, ',')){
            Region region;
            if(r.front() == '"' && r.back() == '"') region.region = "UNKNOWN";
            else region.region = r;
            region.period = p;
            region.cnt = stoi(c);
            region.event = (e == "Births");
            regions.push_back(region);
        }
        else{
            string waste;
            Region region;
            if(r.front() == '"'){
                while(getline(file, line, ',')){
                    break;
                }
            }
            region.region = "UNKNOWN";
            region.period = p;
            region.event = (e == "Births");
            getline(file, c);
            region.cnt= stoi(c);

            regions.push_back(region);
        }
    }
    return regions;
}

void print_regions(const vector<Region>& regions) {
    for (const auto& region : regions) {
        cout << "Period: " << region.period << " | Event Type: " << region.event << " | Region: " << region.region << " | Count: " << region.cnt << endl;
    }
}