#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    }*first=NULL;

void create_linkedlist(int arr[], int size) {
    struct Node *t,*last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(i=1; i < size; i++) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p) {
    while(p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
}

void Insertion(struct Node *p, int position, int element) {
    struct Node *t;
    int i;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=element;
    if(position==0) {
        t->next=first;
        first=t;
    }
    else {
        for(i=0; i<position-1; i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
    }


int search(struct Node *p, int element) {
    int count=0;
    while(p!=NULL) {
        if(p->data==element) {
            return count; }
        else {
            p=p->next;
            count++;
        }
}
}

void Deletion(struct Node *temp, int position) {
    struct Node *q, *p;
    int count=0;
    q=temp;
        if(position==0) {
            temp=temp->next;
            free(q);
        }
        else {
            while(p!=NULL && count<position) {
                count++;
                p=q;
                q=q->next; }
            p->next=q->next;
            free(q);
        }
}


int main() {
    int i,size;
    int A[10]={1,2,3,4,5,7,8,9,10,11};
    /*printf("Enter the elements of the array");
    for(i=0; i < 10; i++)
        scanf("%d", &A[i]);  */
    create_linkedlist(A, 10);
    Display(first);
    printf("\n");
    Insertion(first, 5, 6);
    Display(first);
    printf("\n");
    printf("%d", search(first, 8));
    Deletion(first, 5);
    printf("\n");
    Display(first);
}
