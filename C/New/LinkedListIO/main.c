#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct number {
    int num;
    struct number* next;
    };
typedef struct number * nPtr;

void output(nPtr head);
void input(nPtr* head);
void Free(nPtr* head);

int main()
{
    nPtr head = NULL;
    input(&head);
    output(head);
    Free(&head);
    return 0;
}

void input(nPtr* head){
    char c;
    nPtr prev, current;
    while ((c=getchar())!='\n'){
        current = (nPtr) malloc(sizeof(struct number));
        if(*head == NULL)
            *head = current;
        else
            prev->next = current;
        current->num = (int)c-48;
        current->next = NULL;
        prev = current;
    }
}

void output(nPtr head){
    nPtr current;
    current = head;
    while (current != NULL){
        printf("%d",current->num);
        current = current->next;
    }
}

void Free(nPtr* head){
    nPtr now;
    nPtr current = *head;
    while (current != NULL){
        now = current;
        current = current->next;
        free(now);
    }
}

