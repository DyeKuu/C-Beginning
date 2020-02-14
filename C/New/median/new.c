#include<stdio.h>

int main(int *a,int low,int high){
    int low
    int k=a[low];
    do{
        while(low<high && a[high]>=k) --high;
        if(low<high){
            a[low]=a[high];
            ++low;
        }
        while(low<high && a[low]<=k) ++low;
        if(low<high){
            a[high]=a[low];
            --high;
        }
    }while(low!=high);
    a[low]=k;
    return low;
}
