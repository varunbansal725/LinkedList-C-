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

void Insert_in_sortedlist(struct Node *p, int element) {
    struct Node *t, *q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=element;
    t->next=NULL;
    if(element < first->data) {
        t->next=first;
        first=t;
    }
    else {
    while(p && element > p->data) {
        q=p;
        p=p->next;
    }
    t->next=q->next;
    q->next=t;
}
}

void copy(struct Node *p) {
    struct Node *tail, *x, *y;
    x=p;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=first->data;
    head->next=NULL;
    tail=head;
    x=x->next;
    while(x) {
        y=(struct Node *)malloc(sizeof(struct Node));
        y->data=x->data;
        y->next=NULL;
        tail->next=y;
        tail=y;
        x=x->next;
    }
}

int compare(struct Node *p, struct Node *q) {
    int count1=0;
    int count2=0;
    while(p) { count1++; p=p->next; }
    while(q) { count2++; q=q->next; }
    if(count1==count2) {
        while(p && q) {
            if(p->data == q->data) {
                p=p->data;
                q=q->data;
        }
    else
        break;
    }
}
    else
        return -1;
}


void find_position(struct Node *p, int key) {
    int position=0;
    while(p)
    {
        if(p->data == key) {
            printf("%d ", position);
            p=p->next;
            position++;
        }
        else {
            p=p->next;
            position++;
        }
    }
}


void main() {
    int a;
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
    Insert_in_sortedlist(first, 0);
    Display(first
    Delete_list(first);
    Display(first);
    copy(first);
    Display(head);
    find_position(first, 50);
    a=compare(first,head);
    if(a==-1)
        printf("Both lists are not equal");
    else
        printf("Lists are equal");
}
