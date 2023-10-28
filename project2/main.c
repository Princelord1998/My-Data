// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

// create new node
struct node* createNode(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// insert nodes in descending order of data values
struct node* insert(struct node* head, int data){
    if(!head) return createNode(data);
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    struct node* t = head;
    while(t->next && t->next->data > data) t = t->next;
    if(!t->next){
        t->next = temp;
        temp->next = NULL;
    }else{
       temp->next = t->next;
       t->next = temp;
    }
    return head;
}

// Prints datas on the screen
void info(struct node* head){
    struct node* t = head->next;
    while(t){
        printf("%d->",t->data);
        t = t->next;
    }
}

int main() {
    struct node* head = NULL;
    srand(time(NULL));
    int i = 0;
    while(i<100){
        head = insert(head, rand()%100);
        i++;
    }
    info(head);
    return 0;
}
