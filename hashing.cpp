#include "region.h"
using namespace std;

int gethash(string region){
    int sum=0;
    int D=11;
    for (int i=0; i<region.length(); i++) sum=sum+ region[i];
    return (sum%D);
}

void insert_htable(vector<node*>& htable,Region data){
    int hvalue= gethash(data.region);
    htable[hvalue]=insert_by_region(htable[hvalue],data);
}

node* search_htable(vector<node*>& htable,string region,string period){
     int hvalue= gethash(region);
     node* temp=search_by_region(htable[hvalue],region);
     if(temp==nullptr) return temp;
     if (temp->data.period==period) return temp;
     temp=search_by_period(temp->equalnext,period);
     return temp;
}

void print_htable(vector<node*>& htable){
    for (int i=0;i<11;i++) {
        cout<<i<<"-Htable Bucket\n";
        traverseInOrder(htable[i]);
    }   
}

void editnode(vector<node*>& htable,string reg,string period){
    int value;
     node* temp=search_htable(htable,reg,period);
    print_node(temp);
     if (temp==nullptr) return;
     cout<<"Give a value to be inserted: ";
    cin>> value;
    temp->data.cnt=value;
}