#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"

personPtr search_node(char* comparingName, personPtr head){
    personPtr temp = head;
    while(temp!=NULL) {
        if(!strcmp(comparingName, temp->name)){
        return temp;
        }
        else temp = temp->next;
    }
    return NULL;
};

void enroll(personPtr* head){
    personPtr insert = malloc(sizeof(person));
    printf("Enter name: ");
    scanf("%s", insert->name);
    printf("Enter phone: ");
    scanf("%s", insert->phone);
    if(search_node(insert->name, *head) != NULL){
        printf("Name already exists! Could not enroll.\n");
    } else {
        insert->next = *head;
        *head = insert;
        printf("Enroll success!\n");
    }
    return;
};

void list(personPtr head){
    person *temp = head;
    printf("\nName \tPhone number:\n");
    while(temp != NULL){
        printf("%s\t %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
    return;
};

void search(personPtr head){
    printf("Enter finding name: ");
    char scanName[20];
    scanf("%s", scanName);
    personPtr temp = search_node(scanName, head);
    if (temp == NULL){
        printf("%s was not found.\n", scanName);
        return;
    }   else printf("NAME FOUND:\n%s\t%s\n",temp->name, temp->phone);
    return;
};

void del(personPtr* head){
    char scanName[20];
    personPtr curr = *head; 
    printf("Enter deleting name: ");
    scanf("%s", scanName);
    curr = search_node(scanName, *head);
    if(curr == NULL) 
        printf("%s was not found, could not delete.\n", scanName);
    else{
        personPtr temp = *head, prev_node;
        if (curr == *head){
            *head = curr->next;
            free(curr);
            printf("%s has been deleted :(\n", scanName);
        } else{
            while(temp != curr){
                prev_node = temp;
                temp = temp->next;
            };
            free(curr);
            prev_node->next = temp->next;
            printf("%s has been deleted :(\n", scanName);
        }

    }
    return;
};

void selection(int option, personPtr* head){
    switch (*option){
        case 1:
            enroll(head);
            break;
        case 2:
            list(*head);
            break;
        case 3:
            search(*head);
            break;
        case 4:
            del(head);
            break;
        case 5:
            break;
        default:
            printf("Please check your input.\n");
            break;
    }
    return;
}
