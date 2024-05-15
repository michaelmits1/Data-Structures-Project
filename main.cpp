
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept> // Include for std::invalid_argument

using namespace std;

struct Region {
    std::string period;
    bool birth;
    std::string region;
    int count;
};

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
               if (stoi(period)>=2005) size++;
            } catch (const std::invalid_argument& e) {
                continue; // Skip this line and continue to the next one
            }
    }
    return size;
}

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
        string period, birth_death, region,region2, count_str;

        // Parse the line
        if (getline(ss, period, ',') && 
            getline(ss, birth_death, ',') && 
            getline(ss, region, ',') && 
            getline(ss, count_str, ',')) {
            // Handle quoted region name (same as before)

            Region r;
            r.period = period;
            r.birth = (birth_death == "Births");
            r.region = region;

            // Convert count_str to integer (with error handling)
            try {
                r.count = stoi(count_str);
            } catch (const std::invalid_argument& e) {
                cerr << "Invalid line " <<  endl;
                continue; // Skip this line and continue to the next one
            }
             regions[i++]=r;
            
        }
        else{
            stringstream sss(linecopy);
            getline(sss, period, ',') ;
            getline(sss, birth_death, ',') ; 
            getline(sss, region, ',');
             Region r;
            r.period = period;
            r.birth = (birth_death == "Births");
            r.region = region;
           
            getline(file, line);
            stringstream s(line);
            getline(s, region2, ','); // Read the region within quotes
            getline(s, count_str, ',');
           r.region.append(" ");
           r.region.append(region2);

            // Convert count_str to integer (with error handling)
            try {
                r.count = stoi(count_str);
            } catch (const std::invalid_argument& e) {
                cerr << "Invalid count value: " << count_str << endl;
                continue; // Skip this line and continue to the next one
            }
             regions[i++]=r;
        }
       
    }

    file.close();
}

void print_array_regions(Region regions[],int size){
    for (int i=0;i<size;i++) {
        cout << i<<"Period: " << regions[i].period << ", ";
        cout << "Event: " << (regions[i].birth ? "Births" : "Deaths") << ", ";
        cout << "Region: " << regions[i].region << ", ";
        cout << "Count: " << regions[i].count << endl;
    }
    
}

void print_part_of_array(Region regions[],int start_index,int end_index,int size){
    cout<<"print_array_regions\n";
    cout<<"start "<<start_index<<" end "<<end_index<<"\n";

    if (end_index!=-1 && start_index!=-1){
        for (int i=start_index;i<=end_index;i++) {
            cout <<i <<"Period: " << regions[i].period << ", ";
            cout << "Event: " << (regions[i].birth ? "Births" : "Deaths") << ", ";
            cout << "Region: " << regions[i].region << ", ";
            cout << "Count: " << regions[i].count << endl;
        }
    }
}





void create_birth_array(Region regions[],Region clone[],int size){
   int j=0;
    for (int i=0;i<size;i++){
       if(regions[i].birth==1) clone[j++]=regions[i];
    }
}

void create_death_array(Region regions[],Region clone[],int size){
   int j=0;
    for (int i=0;i<size;i++){
       if(regions[i].birth==0) clone[j++]=regions[i];
    }
}

int count_births(Region regions[],int size){
    int births=0;
    for (int i=0;i<size;i++) {
       if(regions[i].birth==1)births++;
    }
    return births;
}


void swap(Region *Arr,int r,int b){
    Region c=Arr[r];
    Arr[r]=Arr[b];
    Arr[b]=c;
    return ;
}

void merge(Region *Arr, int start, int mid, int end) {
    // create a temp array
    Region temp[end - start + 1];
    // crawlers for both intervals and for temp
    int i = start, j = mid+1, k = 0;
    // traverse both arrays and in each iteration add smaller of both elements in temp
    while(i<= mid && j <= end) {
        if(Arr[i].count<= Arr[j].count) {
            temp[k] = Arr[i];
            k += 1; i += 1;
        }
        else {
            temp[k] = Arr[j];
            k += 1; j += 1;
        }
    }
// add elements left in the first interval
    while(i <= mid) {
        temp[k] = Arr[i];
        k += 1; i += 1;
    }
    // add elements left in the second interval
    while(j <= end) {
        temp[k] = Arr[j];
        k += 1; j += 1;
    }
    // copy temp to original interval
    for(i = start; i <= end; i += 1) {
        Arr[i] = temp[i - start];
    }
}

void mergeSort(Region *Arr, int start, int end) {
    if(start < end) {
        int mid=(start + end) / 2;
        mergeSort(Arr, start, mid);
        mergeSort(Arr, mid+1, end);
        merge(Arr, start, mid, end);
    }
}


void heapify_down(Region *Arr,int r,int end){
    int lchild=2*r+1;
    int rchild=2*r+2;
    if(lchild<end && rchild<end){
        int largest;
        largest=lchild;
        if (Arr[lchild].count<Arr[rchild].count)largest=rchild;
        if (Arr[r].count<Arr[largest].count) {
            swap(Arr,r,largest);
            r=largest;
            heapify_down(Arr,r,end);
        }
    }
    else if(lchild<end && rchild>=end){
        if (Arr[r].count<Arr[lchild].count) {
            swap(Arr,r,lchild);
            r=lchild;
            heapify_down(Arr,r,end);
        }
    }
    else if(lchild>=end && rchild<end){
        if (Arr[r].count<Arr[rchild].count) {
            swap(Arr,r,rchild);
            r=rchild;
            heapify_down(Arr,r,end);
        }
    }
    
    
    return;
}


void buildheap(Region* regions,int size){
    for (int i=0;i<size;i++){
        heapify_down(regions,size-1-i,size);
    }
}


void heapsort(Region *regions,int size ){
   buildheap(regions,size);
   for (int i=0;i<size;i++){
        swap(regions,0,size-1-i);
        heapify_down(regions,0,size-1-i);
   }
}


int bin_search(Region* arr,int b1,int b2,int key){
    int medium=(b2+b1)/2;
    if (arr[medium].count==key) return medium;
    else if (arr[medium].count>key) {
        if (b2==b1)return -1 ;
       return bin_search(arr,b1,medium-1,key);//search left
    }
    else if (arr[medium].count<key){
         if (b2==b1)return -1;
        return bin_search(arr,medium+1,b2,key);//search right
    }
}

void region_bin_search(Region* arr,int size,int b1,int b2){
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




void qsort(Region* arr,int start,int end){
    int pivot=(start+end)/2;
    int left=start-1;
    int right=end+1;
    if(start>=end)return;
    while(left<=right){
        right--;
        if (arr[right].count<=arr[pivot].count){
            do{
                left++;
            }while(arr[left].count<arr[pivot].count && left<right);
           
            if (left!=right)swap(arr,right,left);
            if (right==pivot) pivot=left;
            if (left==pivot) pivot=right;
        }
    }
    qsort(arr,start,pivot-1);
    qsort(arr,pivot+1,end);

    }
    // 0 1 2 3  4 5 6 7 8 9 10
   //   
/*
pivot=8
left=-1
right=11
l,r
-1,10
-1,9 0,9 swap(0,9)
0,8
0,7 1,7 2,7 3,7 swap(3,7)
3,6 4,6 5,6 swap(5,6)
5,5
               7  8   9  10         
4 3 2 2 5 0 8 11 9 14 20
qsort(0,4) -1,4 -1,3 0,3 swap(0,3) 0,2 1,2 swap(1,2) //2 2 3 4 5 //qsort(0,0)//qsort(2,4) 1,4 1,3 2,3 3,3//qsort(2,2)//qsort(4,4)
qsort(7,10) pivot=9 6,10 6,9 6,8 7,8 swap(7,8) pivot=7 qsort(7,6) //qsort(8,10)
*/

int main() {
    string filename = "bd-dec22-births-deaths-by-region.csv";
    int size=get_arrsize(filename);
    Region regions[size];
    read_csv(regions,filename);    

    int births=count_births(regions,size);
    int deaths=size-births;
    Region barray[births];
    Region darray[deaths];
    create_birth_array(regions,barray,size);
    create_death_array(regions,darray,size);

    //MERGESORT
   mergeSort(barray,0,births-1);
        
    cout<<"BIRTH SORTED ARRAY\n";
    print_array_regions(barray,births);
      //HEAPSORT 
    /*heapsort(darray,deaths);  
     cout<<"DEATH SORTED ARRAY\n";
     print_array_regions(darray,deaths);  */
   //BINARY SEARCH
   int b1=12;
    int b2=2400;
   region_bin_search(barray,births,b1,b2);
    /*
  qsort(barray,0,births-1);
 cout<<"BIRTH SORTED ARRAY\n";
    print_array_regions(barray,births);*/

    return 0;
}





