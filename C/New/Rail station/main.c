#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    int* a;
    kaishile:a = (int*)malloc(n*sizeof(int));

    woyoulaile:for (int i = 0 ; i < n ; i++) {
            scanf("%d",&a[i]);
            if (a[i] == 0) goto zhendezoule;
    }

    int p = 0, hook = 0;
    for ( ; p < n-1 ; p++){
        if (a[p]>a[p+1]) continue;
        if (a[p+1]>a[hook]) hook = p+1;
            else {
                printf("No\n");
                goto zoule;
            }

    }

    printf("Yes\n");

    zoule:goto woyoulaile;

    zhendezoule: printf("---\n");
    scanf("%d",&n);

    if (n != 0) {
            free(a);
            goto kaishile;
    }

    return 0;
}
