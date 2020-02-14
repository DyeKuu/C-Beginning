#include <stdio.h>
int main (void)
{
    int n, i;
    char type;
    double ti, tf;

    scanf("%d", &n);
    getchar();

    for (i = 1; i <= n; i++){
        scanf("%c %lf", &type, &ti);
        getchar();
        if (type =='C'){
            tf = ti*1.8+32;
            type = 'F';
        }
        else{
            tf = (ti-32)/1.8;
            type = 'C';
        }
        printf("%.2lf\n", tf);
    }
    return 0;
}
