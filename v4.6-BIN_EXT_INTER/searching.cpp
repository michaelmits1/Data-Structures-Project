#include "region.h"
using namespace std;

int bin_search(Region* list, int b1, int b2, int key){
    int mid = (b2 + b1) / 2;

    if(list[mid].cnt == key) return mid;

    else if(list[mid].cnt > key){
        if(b2 == b1) return -1 ;
        return bin_search(list, b1, mid - 1, key);  //search left
    }
    else if(list[mid].cnt < key){
        if (b2 == b1) return -1;
        return bin_search(list, mid + 1, b2, key);  //search right
    }
}
int interpolation_search(Region *list, int key, int left, int right) {
    while(left <= right && key >= list[left].cnt && key <= list[right].cnt){

        int pos = left + (((key - list[left].cnt) * (right - left)) / (list[right].cnt - list[left].cnt));

        //found
        if(list[pos].cnt == key){
           return pos;
        }
        //continue search
        if(list[pos].cnt > key) right = pos - 1;
        else left = pos + 1;
    }
    return -1;
}
int bin_inter_search(Region* list, int size , int key){
    if (key > list[size-1].cnt || key < list[0].cnt) return -1;

    int left = 0;
    int right = size-1;
    int len = right - left;
    int next = len * ((key - list[left].cnt) / (list[right].cnt - list[left].cnt));
    int step;

    while(key != list[next].cnt ){
        int i=0;
        len = right - left+1;
        step=(int)sqrt(len);

        if(len <= 3){
            for(int index=0; index < len; ++index){
                if(key != list[left].cnt) left++;
                else if(key == list[left].cnt) return left;
            }
            if(key != list[left].cnt) return -1;
        }

        if(key >=list[next].cnt){
            while(key > list[next + i*step - 1].cnt){
                ++i;
                if(next+i*step-1>size-1) break;
            }
            right=next+i*step;
            left=right-step;
        }

        else if(key < list[next].cnt){
            while(key < list[next - i*step + 1].cnt){
                ++i;
                if(next-i*step-1<0) break;
            }
            right=next-(i-1)*step;
            left=right-step;
        }
        next = left- 1 + ((right - left+1) * (key - list[left].cnt) / (list[right].cnt - list[left].cnt));
    }


    if(key == list[next].cnt) return next;
    else return -1;
}
int bin_inter_extented_search(Region* list, int size, int key){
    int left=0;
    int right= size - 1;
    int len = right - left + 1;
    int next= (int)(ceil(len * (key - (list[left].cnt)) / (list[right].cnt - list[left].cnt))) + 1;

    while(key != list[next].cnt){

        int i=0;
        size=right-left+1;
        if(list[left].cnt <= key && key <= list[right].cnt)  return bin_search(list, left, right, key);

        else if (key >= list[next].cnt){
            while (key > list[(int)(next + pow(2, i) * sqrt(len) - 1)].cnt) ++i;

            right=(int)(next + pow(2,i) * sqrt(size));
            left=(int)(next + pow(2,i-1) * sqrt(size));

        }
        else if (key < list[next].cnt){
            while (key < list[(int)(next - pow(2, i) * sqrt(len) + 1)].cnt) ++i;

            right=(int)(next - pow(2,i-1) * sqrt(size));
            left=(int)(next + pow(2,i) * sqrt(size));
        }
        next=left + (int)(ceil((right-left+1) * (key - list[left].cnt) / (list[right].cnt - list[left].cnt)) - 1);
    }

    if(key == list[next].cnt){
        return next;}
    else
        return -1;

}
int bin_inter_extented_search_NOT(Region* list, int size , int key){
    if (key > list[size-1].cnt || key < list[0].cnt) return -1;

    int left = 0;
    int right = size - 1;

    // Interpolation step
    int next = left + ((key - list[left].cnt) * (right - left) / (list[right].cnt - list[left].cnt));
    if (next < left || next > right) return -1; // Check bounds

    while (left <= right) {
        int len = right - left + 1;

        if (len <= 5) {  // Direct linear search for small ranges
            for (int i = left; i <= right; ++i) {
                if (list[i].cnt == key) return i;
            }
            return -1;
        }

        if (list[next].cnt == key) return next;

        int step = (int)sqrt(len);
        int i = 1;

        if (key > list[next].cnt) {  // Search to the right
            while (next + i * step <= right && key > list[next + i * step].cnt) {
                i *= 2;
            }
            left = next + (i / 2) * step;
            right = min(next + i * step, right);

            // Binary search in the identified range
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (list[mid].cnt == key) return mid;
                else if (list[mid].cnt < key) left = mid + 1;
                else right = mid - 1;
            }
        } else {  // Search to the left
            while (next - i * step >= left && key < list[next - i * step].cnt) {
                i *= 2;
            }
            right = next - (i / 2) * step;
            left = max(next - i * step, left);

            // Binary search in the identified range
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (list[mid].cnt == key) return mid;
                else if (list[mid].cnt < key) left = mid + 1;
                else right = mid - 1;
            }
        }
    }
    return -1;
}

Region* find_regions_inter(Region *list, int size, Region found[]){
    int count=0;
    int b1, b2;
    cout << "span [b1, b2]: ";
    cin >> b1 >> b2;
    int p1 = b1;
    int p2 = b2;

    int pos1 = interpolation_search(list, p1, 0, size - 1);
    while(pos1 == -1){
        p1++;
        pos1 = interpolation_search(list, p1, 0, size - 1);
    }

    int pos2 = interpolation_search(list, p2, 0, size - 1);
    while(pos2 == -1){
        p2--;
        pos2 = interpolation_search(list, p2, 0, size - 1);
    }

    for(int i=pos1; i<=pos2; ++i){
        found[count++] = list[i];
    }
    while(list[pos2+1].cnt == list[pos2].cnt && stoi(list[pos2+1].period) != stoi(list[pos2-1].period)){
        found[count++] = list[pos2++];
    }


    if (count==0) {
        cout << "No regions found within the specified birth count range.\n";
    } else {
        cout << "Regions within the specified birth count range:\n";
        for (int i = 0; i < count; ++i) {
            cout << i+1 << ". ";
            cout << "Period: " << found[i].period << ", ";
            cout << "Region: " << found[i].region << ", ";
            cout << "Count: " << found[i].cnt << endl;
        }
    }
}
Region* find_regions_bin_inter(Region *list, int size, Region found[]){
    int count=0;
    int b1, b2;
    cout << "span [b1, b2]: ";
    cin >> b1 >> b2;
    int p1 = b1;
    int p2 = b2;

    int pos1 = bin_inter_search(list, size, p1);
    while(pos1 == -1){
        p1++;
        pos1 = bin_inter_search(list, size, p1);
    }

    int pos2 = bin_inter_search(list, size, p2);
    while(pos2 == -1){
        p2--;
        pos2 = bin_inter_search(list, size, p2);
    }

    for(int i=pos1; i<=pos2; ++i){
        found[count++] = list[i];
    }
    while(list[pos2+1].cnt == list[pos2].cnt && stoi(list[pos2+1].period) != stoi(list[pos2-1].period)){
        found[count++] = list[pos2++];
    }

    if (count==0) {
        cout << "No regions found within the specified birth count range.\n";
    } else {
        cout << "Regions within the specified birth count range:\n";
        for (int i = 0; i < count; ++i) {
            cout << i+1 << ". ";
            cout << "Period: " << found[i].period << ", ";
            cout << "Region: " << found[i].region << ", ";
            cout << "Count: " << found[i].cnt << endl;
        }
    }
}
void find_regions_bin(Region* arr,int size,int b1,int b2){
    int start_index=-1;
    int end_index=-1;
    while(b1<b2 && start_index==-1){
        start_index=bin_search(arr,0,size-1,b1);
        b1++;
    }
    while(b1<b2 && end_index==-1){
        end_index=bin_search(arr,0,size-1,b2);
        b2--;
    }
    print_part_of_array(arr,start_index,end_index,size);

}



