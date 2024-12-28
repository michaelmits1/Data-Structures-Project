#include "region.h"
using namespace std;

node* read_csv_births(node* root,const string& filename) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return nullptr;
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
            if (r.event==1)root=insert_by_births(root,r);
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

            if (r.event==1)root=insert_by_births(root,r);
        }
       
    }

    file.close();
    return root;
}

node* read_csv_regions(node* root,const string& filename) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return nullptr;
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
            if (r.event==1)root=insert_by_region(root,r);
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

            if (r.event==1)root=insert_by_region(root,r);
        }
       
    }

    file.close();
    return root;
}

void read_csv_regions_htable(vector<node*>& htable,const string& filename) {
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
            if (r.event==1) insert_htable(htable,r);
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

            if (r.event==1)insert_htable(htable,r);
        }
       
    }

    file.close();
    return ;
}