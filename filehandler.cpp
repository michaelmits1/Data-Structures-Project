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
            stringstream sss(linecopy);
            getline(sss, period, ',') ;
            getline(sss, event_str, ',') ; 
            getline(sss, region, ',');
             Region r;
            r.period = period;
            r.event = (event_str == "Births");
            r.region = region;
           
            getline(file, line);
            stringstream s(line);
            getline(s, region2, ','); // Read the region within quotes
            getline(s, cnt_str, ',');
           r.region.append(" ");
           r.region.append(region2);

            // Convert cnt_str to integer (with error handling)
            try {
                r.cnt = stoi(cnt_str);
            } catch (const std::invalid_argument& e) {
                cerr << "Invalid cnt value: " << cnt_str << endl;
                continue; // Skip this line and continue to the next one
            }
             regions[i++]=r;
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
        cout << "cnt: " << regions[i].cnt << endl;
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
        for (int i=start_index;i<=end_index;i++) {
            cout <<i <<"Period: " << regions[i].period << ", ";
            cout << "Event: " << (regions[i].event ? "Births" : "Deaths") << ", ";
            cout << "Region: " << regions[i].region << ", ";
            cout << "Count: " << regions[i].cnt << endl;
        }
    }
}