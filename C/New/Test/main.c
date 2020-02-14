#include <stdio.h>
#include <stdlib.h>
typedef int element_type;

typedef struct STRUCTNODE* nPtr;
typedef struct STRUCTNODE {
    element_type element;
    struct STRUCTNODE* next;
    struct STRUCTNODE* last;
}node;

struct LINKLIST{
    nPtr head;
    nPtr tail;
    nPtr fence;
};

typedef struct LINKLIST* List;

int main(){
    int n;
    scanf("%d\n",&n);
    List list = (List)malloc(sizeof(struct LINKLIST));
    for (int i = 1;i<=n;i++){
        init(list);
        char c;
        while (c = getchar()!=' '){
            append(list,(int)c-48);
        }
        long position;
        scanf("%ld",&position);
        if (i!=n) getchar();
    }
}

void init(List listLink){
    nPtr headnode = (nPtr)malloc(sizeof(node));
    headnode->element = 0;
    headnode->last = NULL;
    headnode->next = NULL;
    listLink->head = headnode;
    listLink->tail=listLink->fence = headnode;
}

void append(List listlink, element_type item){
    nPtr newnode = (nPtr)malloc(sizeof(node));
    newnode -> element = item;
    newnode -> next = NULL;
    newnode -> last = listlink->tail;
    listlink->tail->next = newnode;
    listlink->tail=newnode;
}

void removefromtail(List listlink, long position){
    long count = 1;
    nPtr current = listlink->tail;
    while (count != position){
        current = current->last;
        count++;
    }
    current->last->next = current->next;
    if (current->next != NULL) current->next->last = current ->last;




}
