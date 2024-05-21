#include "region.h"
using namespace std;


int interpolation_search(Region* arr,int left,int right,int key){
    
    int medium = left + (((key - arr[left].cnt) * (right - left)) / (arr[right].cnt - arr[left].cnt));
    if (arr[medium].cnt==key) return medium;
    else if (arr[medium].cnt>key) {
        if (right<=left)return -1 ;
       return  interpolation_search(arr,left,medium-1,key);//search left
    }
    else if (arr[medium].cnt<key){
         if (right<=left)return -1;
        return  interpolation_search(arr,medium+1,right,key);//search right
    }
}

int bin_search(Region* arr,int left,int right,int key){
    int medium=(left+right)/2;
    if (arr[medium].cnt==key) return medium;
    else if (arr[medium].cnt>key) {
        if (right<=left)return -1 ;
       return bin_search(arr,left,medium-1,key);//search left
    }
    else if (arr[medium].cnt<key){
         if (left==right)return -1;
        return bin_search(arr,medium+1,right,key);//search right
    }
}

void find_region_bin(Region* arr,int size,int b1,int b2){
    int start_index=-1;
    int end_index=-1;
    if (arr[size-1].cnt<=b2) end_index=size-1;
     if (arr[0].cnt>=b1) start_index=0;
    while(b1<=b2 && start_index==-1){
        start_index=bin_search(arr,0,size-1,b1);
        b1++;
    }
    while(b1-1<=b2 && end_index==-1){
        end_index=bin_search(arr,0,size-1,b2);
        b2--;
    }
    print_part_of_array(arr,start_index,end_index,size);

}

void find_region_inter(Region* arr,int size,int b1,int b2){
    int start_index=-1;
    int end_index=-1;
     if (arr[size-1].cnt<=b2) end_index=size-1;
     if (arr[0].cnt>=b1) start_index=0;
    while(b1<=b2 && start_index==-1){
        start_index=interpolation_search(arr,0,size-1,b1);
        b1++;
    }
    while(b1-1<=b2 && end_index==-1){
        end_index=interpolation_search(arr,0,size-1,b2);
        b2--;
    }
    print_part_of_array(arr,start_index,end_index,size);

}


void find_region_bin_inter(Region* arr,int size,int b1,int b2){
    int start_index=-1;
    int end_index=-1;
    if (arr[size-1].cnt<=b2) end_index=size-1;
     if (arr[0].cnt>=b1) start_index=0;
    while(b1<=b2 && start_index==-1){
        start_index=bin_inter_search(arr,size,b1);
        b1++;
    }
    while(b1-1<=b2 && end_index==-1){
        end_index=bin_inter_search(arr,size,b2);
        b2--;
    }
    print_part_of_array(arr,start_index,end_index,size);

}


int bin_inter_search(Region* list, int size , int key){
    if (key>list[size-1].cnt) return -1;
    int left = 0;
    int right = size-1;
    int len = right - left+1;
    int next = 1+ ceil(len * (key - list[left].cnt) / (list[right].cnt - list[left].cnt));
    int step;
    while(key != list[next].cnt ){
        int i=0;
        len = right - left+1;
         step=(int)sqrt(len);
        //apeutheias grammiki anazitisi
        if(len <= 5){
           return bin_search(list,left,right,key);
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
                if(next-i*step+1<0) break;
            }
            right=next-(i-1)*step;
            left=right-step;
        }
        next = left- 1 + ((right - left+1) * (key - list[left].cnt) / (list[right].cnt - list[left].cnt));
    }
    //found
    if(key == list[next].cnt) return next;
    // :(
    else return -1;
}

int bin_inter_extented_search(Region* list, int size , int key){
    if (key>list[size-1].cnt) return -1;
    //if (key==list[size-1].cnt) return  size-1;
    int left = 0;
    int right = size-1;
    int len = right - left+1;
    int next = 1+ ceil(len * (key - list[left].cnt) / (list[right].cnt - list[left].cnt));
    int step;
    while(key != list[next].cnt ){
        int i=1;
        len = right - left+1;
         step=(int)sqrt(len);
        //apeutheias grammiki anazitisi
        if(len <=10){
           return bin_search(list,left,right,key);
        }
        //right subarray
        if(key >=list[next].cnt){
            while(key > list[next + i*step-1].cnt){
                i=2*i;
                if(next+i*step-1>size-1) {
                    right=size-1;
                    left=right-(i/2)*step;
                    break;
                }
            }
            if(next+i*step-1<=size-1){
                 right=next+i*step;
                left=next+(i/2)*step;
            }
            //bin-search
            while(step<right-left){
                int medium=(left+right)/2;
                if (medium>size-1 || medium <0) break;
                if (list[medium].cnt==key) return medium;
                else if(list[medium].cnt<key){
                    left=medium;
                }
                else if(list[medium].cnt>key){
                    right=medium;
                }
               // if(left+step=r)
            }

        }

        //left subarray
        else if(key < list[next].cnt){
            while(key < list[next - i*step+1].cnt){
                i=2*i;
                if(next+i*step+1>size-1) {
                    right=left+(i/2)*step;
                    left=0;
                    break;
                }
            }
             if(next+i*step+1<=size-1){
                right=next-(i/2)*step;
                left=next-i*step;   
             }
            
         while(step<right-left){
                int medium=(left+right)/2;
                if (medium>size-1 || medium <0) break;
                if (list[medium].cnt==key) return medium;
                else if(list[medium].cnt<key){
                    if(step!=right-left)left=medium;
                }
                else if(list[medium].cnt>key){
                    right=medium;
                }
               // if(left+step=r)
            }
        }
        next = left- 1 + ((right - left+1) * (key - list[left].cnt) / (list[right].cnt - list[left].cnt));
       
    }
    //found
    if(key == list[next].cnt) return next;
    // :(
    else return -1;
}
