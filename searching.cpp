#include "region.h"
using namespace std;


int interpolation_search(Region* arr,int left,int right,int key){
     if (arr[left].cnt == arr[right].cnt || right<left) {//check so you dont divide by zero
           return right+1;
        }
    
    int medium = left + (((key - arr[left].cnt) * (right - left)) / (arr[right].cnt - arr[left].cnt));

    if (arr[medium].cnt==key) return medium;
    else if (arr[medium].cnt>key) {
       return  interpolation_search(arr,left,medium-1,key);//search left
    }
    else if (arr[medium].cnt<key){
        return  interpolation_search(arr,medium+1,right,key);//search right
    }
}

int bin_search(Region* arr,int left,int right,int key){
    int medium=(left+right)/2;
    if (arr[medium].cnt==key) return medium;
    else if (arr[medium].cnt>key) {
        if (right<=left)return right+1 ;
       return bin_search(arr,left,medium-1,key);//search left
    }
    else if (arr[medium].cnt<key){
        if (right<=left)return right+1 ;
        return bin_search(arr,medium+1,right,key);//search right
    }
}

int bin_inter_search(Region* list, int size , int key){
    if (key > list[size-1].cnt || key < list[0].cnt) return -1;
    int left = 0;
    int right = size-1;
    int len = right - left+1;
    int next = left + ((key - list[left].cnt) * (right - left) / (list[right].cnt - list[left].cnt));
    int step;
    while(key != list[next].cnt ){
        int i=0;
        len = right - left+1;
         step=(int)sqrt(len);
        //apeutheias grammiki anazitisi
        if(len <= 5){
           for (int i = left; i <= right; ++i) if (list[i].cnt >= key) return i;
        }
        if(key >=list[next].cnt){
            while(key > list[next + i*step ].cnt){
                ++i;
                if(next+i*step>size-1) break;
            }
            right=min(size-1,next+i*step);
            left=right-step;
        }
        else if(key < list[next].cnt){
            while(key < list[next - i*step].cnt){
                ++i;
                if(next-i*step<0) break;
            }
            left=max(0,next-i*step);
            right=left+step;
            
        }
         next = left + ((key - list[left].cnt) * (right - left) / (list[right].cnt - list[left].cnt));
    }
    //found
    return next;
}

int bin_inter_extended_search(Region* list, int size , int key){
    if (key > list[size-1].cnt || key < list[0].cnt) return -1;
    int left = 0;
    int right = size - 1;
    int next = left + ((key - list[left].cnt) * (right - left) / (list[right].cnt - list[left].cnt));
    while (left <= right) {
        int len = right - left + 1;

        if (len <= 5) {  // Direct linear search for small ranges
            for (int i = left; i <= right; ++i)  if (list[i].cnt >= key) return i;
        }

        if (list[next].cnt == key) return next;

        int step = (int)sqrt(len);
        int i = 1;

        if (key > list[next].cnt) {  // Search to the right
            while (next + i * step <= right && key > list[next + i * step].cnt) {
                i =i* 2;
            }
            left = next + (i / 2) * step;
            right = min(next + i * step, right);
            while (left+step < right) {
                int mid = left + (right - left) / 2;
                if (list[mid].cnt == key) return mid;
                else if (list[mid].cnt < key) left = mid + 1;
                else right = mid - 1;
            }
        } else { 
            while (next - i * step >= left && key < list[next - i * step].cnt) {
                i =i*2;
            }
            right = next - (i / 2) * step;
            left = max(next - i * step, left);
            while (left+step < right) {
                int mid = left + (right - left) / 2;
                if (list[mid].cnt == key) return mid;
                else if (list[mid].cnt < key) left = mid + 1;
                else right = mid - 1;
            }
        }
        next = left + ((key - list[left].cnt) * (right - left) / (list[right].cnt - list[left].cnt));

    }
    return next;
}


void find_region_bin(Region* arr,int size,int b1,int b2){
    if (b1>b2 ) return;
    int start_index,end_index;
    if (arr[size-1].cnt<=b1) {
        start_index=size-1;
        end_index=size-1;
    }
    start_index=bin_search(arr,0,size-1,b1);
    if (start_index<0) start_index=0;
    if (b2>=arr[size-1].cnt) end_index=size-1;
    else{
        for(int i=start_index;i<size;i++){
            if(arr[i].cnt==b2) {
                end_index=i;
                break;
            }
            else if(arr[i].cnt>b2){
                end_index=i-1;
                break;
            }
        }      
    }
         
    print_part_of_array(arr,start_index,end_index,size);

}

void find_region_inter(Region* arr,int size,int b1,int b2){
  if (b1>b2 ) return;
    int start_index,end_index;
    if (arr[size-1].cnt<=b1) {
        start_index=size-1;
        end_index=size-1;
    }
    start_index=interpolation_search(arr,0,size-1,b1);
    if (start_index<0) start_index=0;
    if (b2>=arr[size-1].cnt) end_index=size-1;
    else{
        for(int i=start_index;i<size;i++){
            if(arr[i].cnt==b2) {
                end_index=i;
                break;
            }
            else if(arr[i].cnt>b2){
                end_index=i-1;
                break;
            }
        }      
    }
         
    print_part_of_array(arr,start_index,end_index,size);
}


void find_region_bin_inter(Region* arr,int size,int b1,int b2){
    if (b1>b2 ) return;
    int start_index,end_index;
    if (arr[size-1].cnt<=b1) {
        start_index=size-1;
        end_index=size-1;
    }
    start_index=bin_inter_search(arr,size,b1);
    if (start_index<0) start_index=0;
 if (b2>=arr[size-1].cnt) end_index=size-1;
    else{
        for(int i=start_index;i<size;i++){
            if(arr[i].cnt==b2) {
                end_index=i;
                break;
            }
            else if(arr[i].cnt>b2){
                end_index=i-1;
                break;
            }
        }      
    }  
    print_part_of_array(arr,start_index,end_index,size);

}

void find_region_bin_inter_extended(Region* arr,int size,int b1,int b2){
    if (b1>b2 ) return;
    int start_index,end_index;
    if (arr[size-1].cnt<=b1) {
        start_index=size-1;
        end_index=size-1;
    }
    start_index=bin_inter_extended_search(arr,size,b1);
    if (start_index<0) start_index=0;
   if (b2>=arr[size-1].cnt) end_index=size-1;
    else{
        for(int i=start_index;i<size;i++){
            if(arr[i].cnt==b2) {
                end_index=i;
                break;
            }
            else if(arr[i].cnt>b2){
                end_index=i-1;
                break;
            }
        }      
    }      
    print_part_of_array(arr,start_index,end_index,size);
}

