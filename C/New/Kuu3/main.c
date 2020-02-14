#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b
int main(){
    long n;
    scanf("%ld",&n);

    for (int j = 1; j<=n; j++){
        char s1[2000]={0}, s2[2000]={0};
        int n1[2000]={0}, n2[2000]={0},n3[2000]={0};
        scanf("%s",s1);
        scanf("%s",s2);

        //string to int array
        long len1 = strlen(s1);
        long len2 = strlen(s2);
        for (int i = 0; i<= len1 -1 ; ++i) n1[i]=(int)s1[i]-48;
        for (int i = 0; i<= len2 -1 ; ++i) n2[i]=(int)s2[i]-48;
        long len = max(len1,len2);
        long diff = abs(len1 - len2);

        //fill with 0
        if (len1>len2) {
            int i= len1-1;
            for (; i>=diff; --i) n2[i]=n2[i-diff];
            while (i>=0) n2[i--]=0;
        }
        else if (len1<len2) {
            int i= len2-1;
            for (; i>=diff; --i) n1[i]=n1[i-diff];
            while (i>=0) n1[i--]=0;
        }

        /*for (long i=0; i<=len-1; i++){
        printf("%d",*(n1+i));
        }
        printf("\n");
        for (long i=0; i<=len-1; i++){
        printf("%d",*(n2+i));
        }
        printf("\n");*/

        //addition
        int sum = 0;
        int bonus = 0;
        for (long i = len -1; i>=0;i--){
            sum = n1[i]+n2[i]+bonus;
            n3[i] = sum%10;
            bonus = sum/10;
        }

        //print
        if (bonus!=0) printf("%d",bonus);
        for (long i=0; i<=len-1; i++){
        printf("%d",*(n3+i));
        }
        printf("\n");
    }
    printf("END");
    return 0;
}



