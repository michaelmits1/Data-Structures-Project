#include "region.h"
using namespace std;

node* read_csv_births(node* root, const string& filename){
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
            if(r.event) root = insert_by_births(root, r);
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

            // Convert cnt_str to integer (with error handling)
            try {
                r.cnt = stoi(cnt_str);
            } catch (const std::invalid_argument& e) {
                cerr << "Invalid cnt value: " << cnt_str << endl;
                continue; // Skip this line and continue to the next one
            }

            if(r.event) root= insert_by_births(root, r);
        }

    }

    file.close();
    return root;
}

node* read_csv_regions(node* root,const string& filename){
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
            if(r.event==1) root = insert_by_region(root, r);
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

            // Convert cnt_str to integer (with error handling)
            try {
                r.cnt = stoi(cnt_str);
            } catch (const std::invalid_argument& e) {
                cerr << "Invalid cnt value: " << cnt_str << endl;
                continue; // Skip this line and continue to the next one
            }

            if(r.event==1) root = insert_by_region(root, r);
        }

    }

    file.close();
    return root;
}