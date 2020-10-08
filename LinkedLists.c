#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    }*first=NULL,*head=NULL, *third=NULL, *fourth=NULL, *fifth=NULL, *sixth=NULL;

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

void create1(int arr[], int size) {
    struct Node *t, *tail;
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fourth->data=arr[0];
    fourth->next=NULL;
    tail=fourth;
    for(int i=1; i < size; i++) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        tail->next=t;
        tail=t;
    }
}

void create2(int arr[], int size) {
    struct Node *t, *tail;
    sixth=(struct Node *)malloc(sizeof(struct Node));
    sixth->data=arr[0];
    sixth->next=NULL;
    tail=sixth;
    for(int i=1; i < size; i++) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        tail->next=t;
        tail=t;
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


void duplicate(int size) {
    struct Node *p=first;
    int hash[size],value;
    for(int i=0; i<=size; i++)
        hash[i]=0;
    while(p) {
        if(hash[p->data]==0)
            hash[p->data]=1;
        else
            hash[p->data]++;
        p=p->next;
    }
    for(int i=0; i <= size; i++) {
        if(hash[i] > 1)
            value=i; }
        if(value > 1 && value < size)
            printf("The duplicate value is: %d ", value);
        else
            printf("List contains no duplicates");
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

void concatenate(struct Node *p, struct Node *q) {
    if(p && q) {
    third=p;
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
    }
}

void merge(struct Node *p, struct Node *q) {
    struct Node *last;
    if(p->data < q->data) {
        fifth=last=p;
        p=p->next;
        fifth->next=NULL;
    }
    else {
        fifth=last=q;
        q=q->next;
        fifth->next=NULL;
    }
    while(p && q) {

        if(p->data < q->data) {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
        last->next=p;
    if(q)
        last->next=q;
}

int detect_loop(struct Node *q) {
    struct Node *z, *y;
    z=y=q;
    do {
        y=y->next;
        z=z->next;
        z=z?z->next:z;
    } while(y && z && y!=z);
    if(y==z)
    return 1;
    else
    return 0;
}


int main() {
    int i,size,a;
    struct Node *last, *x;/* initializing struct variables for detecting loop. These will only be used for detecting loop function */
    int A[10]={1,2,3,4,5,7,8,9,10,11};
    int B[10]={10,20,30,40,50,60,70,80,90,100};
    int C[10]={12,16,24,35,59,62,65,72,78,85};
    /*printf("Enter the elements of the array");
    for(i=0; i < 10; i++)
        scanf("%d", &A[i]);  */
    create_linkedlist(A, 10);
    printf("Linked List is: ");
    Display(first);
    printf("\n");
    Insertion(first, 5, 6);
    printf("After insertion at a specific position: ");
    Display(first);
    printf("\n");
    printf("The element is found at: %d", search(first, 8));
    Deletion(first, 5);
    printf("\n");
    Display(first);
    Reverse();
    printf("\nAfter reversing: ");
    Display(first);
    Reverse();
    printf("\n");
    Display(first);
    printf("\n");
    Insert_in_sortedlist(first, 6);
    printf("After sorted insertion: ");
    Display(first);
    printf("\n");
    duplicate(11);
    printf("\n");
    copy(first);
    Display(head);
    printf("\n");
    find_position(first, 11);
    printf("\n");
    /* printf("%d", compare(first, head)); */
    a=compare(first, head);
    if(a == -1)
        printf("Not equal\n");
    else
        printf("Lists are equal\n");
    concatenate(first, head);
    Display(third);
    printf("\n");
    create1(B, 10);
    Display(fourth);
    printf("\n");
    create2(C, 10);
    Display(sixth);
    printf("\n");
    last=sixth;
    while(last->next!=NULL)
        last=last->next;
    x=sixth;
    x=x->next->next->next->next->next;
    printf("%d\n",x->data);
    printf("%d\n",last->data);
    last->next=x;
     printf("%d\n", detect_loop(sixth));
     last->next=NULL;
    merge(fourth, sixth);
    Display(fifth);
    printf("\n");

}
