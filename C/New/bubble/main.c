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

    while(p<q){  //���ܼӵȺţ���Ȼ������ѭ���ɣ���Ϊ���p��q�������
        while((*p<midval)) p++; //���ﲻ�ܼӵȺţ���Ȼ��������p��Խ��mid���ֵ ������һ��֮��mid���Ҳ�������С�ڴ��ڵĹ�ϵ
        //printf("%d ",*p);
        while((*q>midval)) q--;
        //printf("%d\n",*q);
        if (p<q) {  //����Ҳ���У���ѭ���Ǵ��
            swap(p,q);
            if (*q==midval) p++;
            if (*p==midval) q--;   //����Ҫ������++��--�����ӵĻ���������ͬ���ݵĻ�����������ѭ�������ϵؽ�������q��p��ֵ������£�������ѭ����
                           //��������������ܼ� �����Խ����ǰֵ������ѡ�е�ֵ��������Сֵ������������ǵڶ�С��ֵ��1100�������
        }

        for (int i=0; i<10; i++) printf("%d ",s[i]);
        printf("\n");
    }

    printf("p:%d q:%d\n",*p,*q);
    for (int i=0; i<10; i++) printf("%d ",s[i]);
    printf("\n");
    printf("p:%d q:%d\n",p,q); //������Ӧ��p q���
    //if (p-s> start)
    quicksort(s,start,p-s-1);
    //if (q-s< end)
    quicksort(s,q-s+1,end);

}
