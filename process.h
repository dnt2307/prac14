#ifndef PROCESS_FILE
#define PROCESS_FILE

typedef struct node{
    char name[20];
    char phone[15];
    struct node *next;
} person, *personPtr;

extern void selection();

#endif