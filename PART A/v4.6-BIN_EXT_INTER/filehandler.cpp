#include "region.h"
using namespace std;

void read_csv(Region regions[],const string& filename) {
    int i=0;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return ;
    }

    // Read each line from the file
    while (getline(file, line)) {
        string linecopy=line;
        stringstream ss(line);
        string period, event_str, region,region2, cnt_str;

        // Parse the line
        if (getline(ss, period, ',') &&
            getline(ss, event_str, ',') &&
            getline(ss, region, ',') &&
            getline(ss, cnt_str, ',')) {
            // Handle quoted region name (same as before)

            Region r;

            if(region.front() == '"' && region.back() == '"') r.region = "Region not stated";
            else r.region = region;
            r.period = period;
            r.event = (event_str == "Births");
            r.region = region;

            // Convert cnt_str to integer (with error handling)
            try {
                r.cnt = stoi(cnt_str);
            } catch (const std::invalid_argument& e) {
                continue; // Skip this line and continue to the next one
            }
            regions[i++]=r;

        }
        else{
            string waste;
            Region r;
            if(region.front() == '"'){
                while(getline(file, line, ',')){
                    break;
                }
            }
            r.region = "Region not stated";
            r.period = period;
            r.event = (event_str == "Births");
            getline(file, cnt_str);
            r.cnt= stoi(cnt_str);

            try {
                r.cnt = stoi(cnt_str);
            } catch (const std::invalid_argument& e) {
                cerr << "Invalid cnt value: " << cnt_str << endl;
                continue; // Skip this line and continue to the next one
            }

            regions[i++] = r;
        }
    }
    file.close();
}

void print_array_regions(Region regions[],int size){
    for (int i=0;i<size;i++) {
        cout << i << ". ";
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

int get_arrsize_event(Region regions[],int size){
    int births=0;
    for (int i=0;i<size;i++) {
        if(regions[i].event==1)births++;
    }
    return births;
}

void print_part_of_array(Region regions[],int start_index,int end_index,int size){
    cout<<"print_array_regions\n";
    cout<<"start "<<start_index<<" end "<<end_index<<"\n";

    if (end_index>size-1 || start_index<0) return;

    if (end_index!=-1){
        for (int i=start_index; i<=end_index;i++) {
            cout << i <<"Period: " << regions[i].period << ", ";
            cout << "Event: " << (regions[i].event ? "Births" : "Deaths") << ", ";
            cout << "Region: " << regions[i].region << ", ";
            cout << " " << regions[i].cnt << endl;
        }
    }
}

double calculateStats(Region *list, int size) {
    // Calculate the mean of the array
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += list[i].cnt;
    }
    double mean = static_cast<double>(sum) / size;
    cout << "mean: " << mean << endl;

    // Calculate the variance
    double variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(list[i].cnt - mean, 2);
    }
    variance = static_cast<double>(variance) / size;
    return sqrt(variance);
}