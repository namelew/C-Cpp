#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void add_beg(struct node **head, int d){
    // in this case, head is a poiter of a pointer that point to the pointer head in the main funtion
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;

    ptr->link = *head;

    *head = ptr;

}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head ->data = 45;
    head ->link = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr ->data = 98;
    ptr ->link = NULL;

    head -> link = ptr;

    int data = 3;

    add_beg(&head, data);
    ptr = head;

    while(ptr != NULL){
        printf("%i\n", ptr -> data);
        ptr = ptr ->link;
    }

    return 0;
}