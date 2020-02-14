#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* stri, int start, int end){
    char *p,*q;
    char h;
    p = stri+end;
    q = stri+start;
    while (p>q) {
        h = *p;
        *p-- = *q;
        *q++ = h;
    }
}

void cutandrev(char *l){
    int start = 0;
    for (int i=0;i<strlen(l)-1;i++){
        if (l[i]==' '){
            reverse(l,start,i-1);
            start = i+1;
        }
    }
    reverse(l,start,strlen(l)-1);
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for (int i=1;i<=n;i++){
        char s[100];
        gets(s);
        cutandrev(s);
        printf("%s\n",s);
    }
    return 0;
}
