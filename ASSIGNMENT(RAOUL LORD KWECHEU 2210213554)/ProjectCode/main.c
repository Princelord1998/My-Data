#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Struct to store the students informations
struct data{
    int id;
    char name[30];
    int age;
};

// This struct contains address of struct data
struct node{
    struct data* data;
    struct node* next;
};

// function to create a new node
struct node* createNode(struct data* data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
};

//Function to delete node next to node with given name
struct node* deleteNext(struct node* head, char* name){
    if(head){
        struct node* temp = head;
        while(temp && strcmp(temp->data->name,name)!=0)
            temp = temp->next;
        if(!temp) return head;
        struct node* del = temp->next;
        temp->next = del->next;
        free(del);
        return head;
    }
}

// function to insert a new node on linked list
struct node* insert(struct node* head, struct data* data){
    if(!head) return createNode(data);
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node* t = head;
    while(t->next) t = t->next;
    t->next = temp;
    return head;
};

// Function to display the longest student name and length of name in the linked list
void longNameRecord(struct node* head){
    if(head){
        int longest = strlen(head->data->name);
        char* longestName = head->data->name;
        struct node* temp = head;
        while(temp){
            if(strlen(temp->data->name) > longest){
                longest = strlen(temp->data->name);
                longestName = temp->data->name;
            }
            temp = temp->next;
        }
        printf("Longest data: %s with length: %d\n",longestName, longest);
    }
}

// Function to search a given student information from the linked list
void search(struct node* head, char nam[]){
    if(!head) printf("empty list\n");
    else{
        struct node* temp = head;
        while(temp){
            if(strcmp(temp->data->name, nam)==0) break;
            temp = temp->next;
        }
        if(!temp) printf("record not found\n");
        else{
            printf("searched results: ");
            printf("%d-%s %d\n",temp->data->id,temp->data->name,temp->data->age);
        }
    }
}

// Function to print Students informations
void info(struct node* head){
    while(head){
        printf("%d-%s %d\n",head->data->id,head->data->name,head->data->age);
        head = head->next;
    }
}

void main(){
    struct node* head = NULL;
    struct data* data = NULL;
    int response = 1;

    while(response){
        printf("STUDENT DATA BASE\n\n");
        printf("\t1-Add student info\n");
        printf("\t2-Search by name\n");
        printf("\t3-Display student info\n");
        printf("\t4-delete data next to\n");
        printf("\t5-Longest name\n");
        printf("\t0-Exit\n");
        printf("your choice: ");
        scanf("%d",&response);

        switch(response){
            case 1:
               data = malloc(sizeof(struct data));
               printf("enter student id, name and age: ");
               scanf("%d %s %d",&data->id,data->name,&data->age);
               head = insert(head,data);
            break;
            case 2:
                printf("enter name to search: ");
                char name[30];
                scanf("%s",name);
                search(head,name);
            break;
            case 3:
                printf("\nStudent Info\n");
                info(head);
            break;
            case 4:
                printf("enter name to delete: ");
                char delName[30];
                scanf("%s",delName);
                head = deleteNext(head,delName);
            break;
            case 5:
                longNameRecord(head);
            break;
        }
    }

}
