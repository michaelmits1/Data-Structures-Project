#include "region.h"
using namespace std;

void read_csv(Region regions[],const string& filename) {
    int i=0;
    int size=0;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {cerr << "Failed to open file: " << filename << endl; return; }
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
            regions[i++] = region;
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

            regions[i++] = region;
        }
    }
    file.close();
}

void print_array_regions(Region regions[],int size){
    for (int i=0;i<size;i++) {
        cout << i+1 << ". ";
        cout << "Period: " << regions[i].period << ", ";
        cout << "Event: " << (regions[i].event ? "Births" : "Deaths") << ", ";
        cout << "Region: " << regions[i].region << ", ";
        cout << "Count: " << regions[i].cnt << endl;
    }
}

int get_arrsize(const string& filename){
    int size=0;

    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return 0;
    }

    while (getline(file, line)) {
        string linecopy=line;
        stringstream ss(line);
        string period;
        getline(ss, period, ',');
        try {
            if (stoi(period)>2004) size++;
        } catch (const std::invalid_argument& e) {
            continue; // Skip this line and continue to the next one
        }
    }
    return size;
}

int get_arrsize_event(Region* list, int sizelist){
    int size=0;
    for(int i=0; i<=sizelist; ++i)
        if(list[i].event) size++;
    return size;
}