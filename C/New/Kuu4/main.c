#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    long int n = 0;
    scanf("%i",&n);

    for (int j = 1; j <= n; ++j){
        char num[255] = {0}; char rev[255] = {0}; char fin[255] = {0};
        long long s = 0;
        long int len, hook = 0;
        int sign = 1;

        scanf("%s",num);
        len = strlen(num);
        if ((len == 1 && num[0] == '0')||(len == 2 && num[0] == '-' && num[1] == '0')) {
            printf("0\n");
            continue;
        }
        if((int)(num[0]) >= 48 && (int)(num[0]) <= 57) sign = 0;

        //reverse
        for (int i = 0; i <=len - sign -1; ++i) rev[i] = num[len - i - 1];
        //without zero
        while (rev[hook] == '0') ++hook;
        for (int i = hook; i <= strlen(rev) - 1; ++i) fin[i - hook] = rev[i];

        len = strlen(fin) - 1;
        for (int i = 0; i <= len; ++i) s += (long long) ((long long)fin[i] - 48) * round(pow(10,len - i));
        if (s - 2147483647 > sign)
                printf("0\n");
        else{
                if (sign == 1) printf("%c",num[0]);
                printf("%s\n",fin);
        }
    }
    return 0;
}
