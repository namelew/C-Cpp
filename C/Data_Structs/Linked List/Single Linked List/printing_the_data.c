# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(void){
    void print_data(struct node *head);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *current = (struct node *)malloc(sizeof(struct node));

    head ->data = 45;
    head -> link = current;

    current -> data = 98;
    current -> link = NULL;

    current = (struct node *)malloc(sizeof(struct node));
    current -> data = 3;
    current -> link = NULL;
    head -> link -> link = current;

    print_data(head);

    return 0;
}

void print_data(struct node *head){
    if(head == NULL){
        printf("The Linked List is empty\n");
    }
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%i ", ptr -> data);
        ptr = ptr -> link;
    }

}