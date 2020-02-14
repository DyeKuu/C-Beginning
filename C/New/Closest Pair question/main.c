#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define min(a,b) (a<b)?a:b
void quicksort(int** s,int start,int end,int indice);
void swap(int* a, int* b);
double calculate(int num,int**b);
double distance(int** a,int start,int end);
double norm(double a,double b);
int** b;

int main()
{
    long n;
    scanf("%ld",&n);
    int** a;
    hajimaruyo:a = (int **)malloc(n*sizeof(int*));
    b = (int **)malloc(n*sizeof(int*));
    for (int i=0; i<n; i++)
    {
        a[i] = (int*)malloc(2*sizeof(int));
        b[i] = (int *)malloc(2*sizeof(int*));
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    quicksort(a,0,n-1,0);


    printf("%.2f\n",distance(a,0,n-1));
    free(a);
    free(b);

    scanf("%d",&n);
    if (n!=0) goto hajimaruyo;
    return 0;
}

void swap(int* a, int* b)
{
    int h;
    h=*a;
    *a=*b;
    *b=h;
}

void quicksort(int** s,int start,int end,int indice)
{
    if (start>=end)
        return;
    int** p=s+start;
    int** q=s+end;
    int midval=*(*(s+(start+end)/2)+indice);
    while(p<q)
    {
        while(*(*p+indice)<midval)
            p++;
        while(*(*q+indice)>midval)
            q--;
        if (p<q)
        {

            swap(*p,*q);
            swap(*p+1,*q+1);
            p++;
        }
    }
    quicksort(s,start,p-s-1,indice);
    quicksort(s,q-s+1,end,indice);
}

double distance(int** a,int start,int end)
{
    if (start>=end) return 100000;
    if (end-start==1)
        return norm(**(a+start)-**(a+end),*(*(a+start)+1)-*(*(a+end)+1));
    if (end-start==2)
    {
        double res;
        double temp1 = sqrt(pow(**(a+start)-**(a+start+1),2)+pow(*(*(a+start)+1)-*(*(a+start+1)+1),2));
        double temp2 = sqrt(pow(**(a+start)-**(a+start+2),2)+pow(*(*(a+start)+1)-*(*(a+start+2)+1),2));
        double temp3 = sqrt(pow(**(a+start+1)-**(a+start+2),2)+pow(*(*(a+start+1)+1)-*(*(a+start+2)+1),2));
        res = min(temp1,temp2);
        res = min(temp3,res);
        return res;
    }
    int mid = (start+end)/2;
    int midx = **(a+mid);
    double temp;
    double d1 = distance(a,start,mid);
    double d2 = distance(a,mid,end);
    double d = min(d1,d2);

    int cnt = 0;
    for(int i = start; i <= end; i++)
    {
        if (-d < (a[i][0]-midx) &&  (a[i][0]-midx) < d)
        {
            b[cnt] = (int*)malloc(2*sizeof(int));
            b[cnt][0] = a[i][0];
            b[cnt++][1] = a[i][1];
        }
    }
    temp = calculate(cnt,b);
    if (temp<d) d=temp;
    return d;

}

double calculate(int num,int**b)
{
    double temp;
    double res = sqrt(pow(b[0][0]-b[1][0],2)+pow(b[0][1]-b[1][1],2));
    if (num >= 7){
        quicksort(b,0,num-1,1);
        for (int i = 0; i < num-5; i++)
        {
            for (int j =1; j<=5; j++)
            {
                temp = sqrt(pow(b[i][0]-b[i+j][0],2)+pow(b[i][1]-b[i+j][1],2));
                if (temp<res)
                    res = temp;
            }
        }
    }
    else {
        for (int i =0;i<num-1;i++){
            for(int j=i+1;j<num;j++){
                temp = sqrt(pow(b[i][0]-b[j][0],2)+pow(b[i][1]-b[j][1],2));
                if (temp<res)
                    res = temp;
            }
        }
    }
    return res;
}

double norm(double a,double b){
    return sqrt(pow(a,2)+pow(b,2));
}
