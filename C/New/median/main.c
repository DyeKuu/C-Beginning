#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n,a,b;
    scanf("%ld\n",&n);

    for (long i = 1; i <= n; i++){
        long s[100000]={0};
        long w[1000]={0};
        long conut = 0;
        double val;
        scanf("%ld %ld\n",&a,&b);
        long p = 0, q = a;
        long num = a + b;
        long mid = num / 2;

        for (long j = 0; j <= num - 1; j++) scanf("%ld", &s[j]);

        while (conut <= mid){
            if((p < a)&&(q < num)) w[conut++] = s[(*((s[p] <= s[q])? &p : &q))++];
            else if (p < a) w[conut++] = s[p++];
                else if (q < num) w[conut++] = s[q++];
        }


        val = (num%2==0)? (w[mid]+w[mid-1])/2.0 : w[mid];
        printf("%.1f\n",val);
    }

    return 0;
}
