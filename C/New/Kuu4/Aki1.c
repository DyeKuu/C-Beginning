#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int Aki1()
{
    int n,i=0;
    char inu;
    scanf("%d",&n);
    scanf("%c",&inu);

    while(i<n){
     long long int res = 0;
     long long int temp = 0;
     int c = 0;
     char ch;
     long long int sign = 1;
     int lim = 1;
     scanf("%c",&ch);
     if(ch == '-'){
         sign = -1;
         scanf("%c",&ch);
         }
     while((ch !='\n'))
     {

         if(lim == 1)
         {
             temp = ch - '0';
              for(int k = 0; k<c;k++)
              {
                temp *= 10;
              }
             res += temp;
         }
         if((sign*res>=INT_MAX)||((sign*res<INT_MIN)))
         {
             lim = 0;
             res = 0;
         }
         c++;
         scanf("%c",&ch);
     }
    int res_f = (int)(sign*res);
    printf("%d\n",res_f);
    i++;
    }
    return 0;
}
