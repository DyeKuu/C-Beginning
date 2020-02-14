#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
struct number {
    short num;
    struct number* next;
    };
typedef struct number * nPtr;

void output(nPtr head);
void input(nPtr* head);
void Free(nPtr* head);
nPtr newinput(nPtr* head);
nPtr multiply(short mul, nPtr head, long diff);
nPtr addition(nPtr head1,nPtr head2);
nPtr reverse(nPtr* head1);

int main()
{
    long n;
    scanf("%ld\n",&n);
    for (long i = 0;i < n; i++){
        nPtr head1 = NULL, head2 = NULL;
        nPtr res = NULL;

        head1 = newinput(&head1);
        head2 = newinput(&head2);
        //head1 = reverse(&head1); head2 = reverse(&head2);
        //output(head1);printf("\n");output(head2);printf("\n");
        long diff = 0;
        while (head2!=NULL){
            nPtr temp;
            temp = multiply(head2->num,head1,diff++);
            res = (diff==1)? temp : addition(res,temp);
            if (diff > 1) Free(&temp);
            head2 = head2->next;
        }

        res = reverse(&res);

        if (res->num == 0) printf("0");
            else output(res);
        printf("\n");
        Free(&head1);
        Free(&head2);
        Free(&res);
    }
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
        current->num = (short)c-48;
        current->next = NULL;
        prev = current;
    }
}

nPtr newinput(nPtr* head){
    char c;
    nPtr prev, current;
    while ((c=getchar())!='\n'){
        current = (nPtr) malloc(sizeof(struct number));
        if(*head == NULL){
            *head = current;
            current->next = NULL;
        }
        else
            current->next = prev;
        current->num = (short)c-48;
        prev = current;
    }
    return current;
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
    nPtr h;
    nPtr current = *head;
    while (current != NULL){
        h = current;
        current = current->next;
        free(h);
    }
}

nPtr multiply(short mul, nPtr head,long diff){
    nPtr newhead = NULL;
    nPtr current = head;
    nPtr newcurrent,prev;
    short bonus = 0;
    for (long i=0;i<diff;i++){
        newcurrent = (nPtr) malloc(sizeof(struct number));
        if (newhead == NULL)
            newhead = newcurrent;
        else
            prev->next = newcurrent;
        newcurrent->num = 0;
        newcurrent->next = NULL;
        prev = newcurrent;
    }
    while (current!=NULL){
        newcurrent = (nPtr) malloc(sizeof(struct number));
        if (newhead == NULL)
            newhead = newcurrent;
        else
            prev->next = newcurrent;
        newcurrent->num = (mul*current->num+bonus)%10;
        bonus = round((mul*current->num+bonus)/10);
        newcurrent->next = NULL;
        prev = newcurrent;
        current = current->next;
    }
    if (bonus!=0) {
        newcurrent = (nPtr) malloc(sizeof(struct number));
        prev->next = newcurrent;
        newcurrent->num = bonus;
        newcurrent->next = NULL;
        prev = newcurrent;
    }
    return newhead;
}

nPtr addition(nPtr head1,nPtr head2){
    nPtr newhead = NULL;
    nPtr current1 = head1, current2 = head2;
    nPtr newcurrent, prev;
    short bonus = 0;
    while ((current1!=NULL)&&(current2!=NULL)){
        newcurrent = (nPtr) malloc(sizeof(struct number));
        if (newhead == NULL)
            newhead = newcurrent;
        else
            prev->next = newcurrent;
        newcurrent->num = (current1->num+current2->num+bonus)%10;
        bonus = round((current1->num+current2->num+bonus)/10);
        newcurrent->next = NULL;
        prev = newcurrent;
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1==NULL) current1 = current2;
    while (current1!=NULL){
        newcurrent = (nPtr) malloc(sizeof(struct number));
        prev->next = newcurrent;

        newcurrent->num = (current1->num+bonus)%10;
        bonus = (current1->num+bonus)/10;

        newcurrent->next = NULL;
        prev = newcurrent;
        current1 = current1->next;
    }
    if (bonus!=0) {
        newcurrent = (nPtr) malloc(sizeof(struct number));
        prev->next = newcurrent;
        newcurrent->num = bonus;
        newcurrent->next = NULL;
        prev = newcurrent;
    }
    return newhead;
}

nPtr reverse(nPtr* head1){
    nPtr next;
    nPtr head=*head1;
    nPtr prev = NULL;
    while (head!=NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

