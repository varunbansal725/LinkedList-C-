#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first=NULL;

/* This Insert function is to add the element always at the end of the linked list */
void Insert(int x) {
    struct Node *t,*last;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL) {
        first=last=t;
        }
    else {
        while(last->next)
        last=last->next;
        last->next=t;
        last=t;
    }
}

void Reverse() {
    if(first!=NULL) {
    struct Node *prev, *current;
    prev=first;
    current=first->next;
    first=first->next;
    prev->next=NULL;
    while(first!=NULL) {
        first=first->next;
        current->next=prev;
        prev=current;
        current=first;
    }
    first=prev;
    }
}

void Delete_list(struct Node *p) {
    struct Node *last=p;
    struct Node *temp;
    
    while(last!=NULL) {
        temp=last->next;
        free(last);
        last=temp;
    }
    p=NULL;
}

void Display(struct Node *p) {
    while(p) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void main() {
    Insert(5);
    Display(first);
    Insert(10);
    Display(first);
    Insert(60);
    Display(first);
    Insert(50);
    Display(first);
    Insert(100);
    Display(first);
    Reverse(0);
    Display(first);
    Delete_list(first);
    Display(first);
}