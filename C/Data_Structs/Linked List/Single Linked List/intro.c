# include <stdio.h>
# include <stdlib.h>

// An exemple of a single linked list

struct node{
    int data;
    int *link;
};

int main(void){
    struct node *head = NULL;
    
    head = (struct node *) malloc(sizeof(struct node));

    head -> data = 45;
    head -> link = NULL;

    printf("%i\n", *head);

    return 0;
}