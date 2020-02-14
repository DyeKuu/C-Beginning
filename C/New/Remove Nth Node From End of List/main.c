#include <stdio.h>
#include <stdlib.h>
typedef int element_type;

typedef struct STRUCTNODE* nPtr;
typedef struct STRUCTNODE {
  element_type element;
  struct STRUCTNODE* next;
  struct STRUCTNODE* last;
}node;

struct LINKLIST
{
  nPtr head;
  nPtr tail;
  nPtr fence;
};
typedef struct LINKLIST* List;
void init(List listLink);
void Free(List listLink);
void append(List listLink, element_type item);
void show(List listlink);
void removefromtail(List listlink, long position);

int main()
{
    int n;
    scanf("%d\n",&n);
    List list = (List)malloc(sizeof(struct LINKLIST));
    for (int i = 1;i <= n;i++){
        init(list);
        char c;
        while ((c = getchar())!=' '){
            append(list,(int)c-48);
        }
        long position;
        scanf("%ld",&position);
        if (i!=n) getchar();
        if (position==0) goto wobuwanle;
        removefromtail(list,position);
        wobuwanle:show(list);
        printf("\n");
        //Free(list);
    }
    return 0;
}

void init(List listLink){
    nPtr headnode = (nPtr)malloc(sizeof(node));
    headnode->element = 0;
    headnode->next = NULL;
    headnode->last = NULL;
    listLink->head = headnode;
    listLink->tail = listLink->fence = headnode;
}

void Free(List listLink){
    while (listLink->head != NULL){
        listLink->fence = listLink->head;
        listLink->head = listLink->head->next;
        free(listLink->fence);
        //if (listLink->head!=NULL) listLink->head->last = NULL;
    }
    listLink->tail = listLink->fence = NULL;
}

void append(List listlink, element_type item){
    nPtr newnode = (nPtr)malloc(sizeof(node));
    newnode->element = item;
    newnode->next = NULL;
    newnode->last = listlink->tail;
    listlink->tail->next = newnode;
    listlink->tail=newnode;
}
void removefromtail(List listlink, long position){
    long count = 1;
    nPtr current = listlink->tail;
    while (count!=position){
        current = current->last;
        count++;
    }
    current->last->next = current->next;
    if (current->next!=NULL) current->next->last = current->last;
    free(current);
}

void show(List listlink){
    listlink->fence = listlink->head->next;
    while (listlink->fence!=NULL){
        printf("%d",listlink->fence->element);
        listlink->fence=listlink->fence->next;
    }
}
