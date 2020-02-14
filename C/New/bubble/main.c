#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubble(int* s,int n);
int main()
{
    long n;
    int s[100000]={0};
    scanf("%ld",&n);
    srand((unsigned)time(NULL));
    for (int i=0; i<n; i++) s[i]=rand()%100;
    for (int i=0; i<n; i++) printf("%d ",s[i]);
    //swap(&s[1],&s[0]);
    printf("\n");
    //bubble(s,10);
    //printf("%d\n",s);
    //printf("%d\n",s+9);
    quicksort(s,0,n-1);
    for (int i=0; i<n; i++) printf("%d ",s[i]);
    return 0;
}

void swap(int* a, int* b){
    int h;
    h=*a;
    *a=*b;
    *b=h;
}

void bubble(int* s, int n){
    for (int i=n-1;i>=0;i--){
        for (int j=0;j<=i-1;j++){
            if (s[j]>s[j+1]) {
                    swap(&s[j],&s[j+1]);
            }
        }
    }
}

void selsort(int* s,int n){
    int minindex;
    for (int i=0;i<n-1;i++){
        minindex = i;
        for (int j=i;j<n;j++)
            if (s[j]<s[minindex]) minindex = j;
        if (i!=minindex) swap(&s[i],&s[minindex]);
        }
    }

void quicksort(int* s,int start,int end){
    if (start>=end) return;
    int *p=s+start;
    int *q=s+end;
    int midval=*(s+(start+end)/2);
    printf("midval : %d\n",midval);

    while(p<q){  //不能加等号，不然等着死循环吧，因为最后p，q不相等了
        while((*p<midval)) p++; //这里不能加等号，不然会凉凉，p会越过mid这个值 导致这一波之后，mid左右不是整体小于大于的关系
        //printf("%d ",*p);
        while((*q>midval)) q--;
        //printf("%d\n",*q);
        if (p<q) {  //这里也不行，死循环是大敌
            swap(p,q);
            if (*q==midval) p++;
            if (*p==midval) q--;   //这里要加两个++，--，不加的话，出现相同数据的话，会陷入死循环，不断地交换但是q，p的值不会更新，跳不出循环。
                           //但是正常情况不能加 否则会越过当前值，比如选中的值正好是最小值，它左边正好是第二小的值，1100这个反例
        }

        for (int i=0; i<10; i++) printf("%d ",s[i]);
        printf("\n");
    }

    printf("p:%d q:%d\n",*p,*q);
    for (int i=0; i<10; i++) printf("%d ",s[i]);
    printf("\n");
    printf("p:%d q:%d\n",p,q); //到这里应该p q相等
    //if (p-s> start)
    quicksort(s,start,p-s-1);
    //if (q-s< end)
    quicksort(s,q-s+1,end);

}
