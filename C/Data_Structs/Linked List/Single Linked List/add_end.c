# include <stdlib.h>
# include <stdio.h>
struct node{
    int data;
    struct node *link;
};

int main(void){
    void add_at_end(struct node *head, int data);
    void print_data(struct node *head);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *current = (struct node *)malloc(sizeof(struct node));

    head ->data = 45;
    head ->link = current;

    current -> data = 98;
    current -> link = NULL;

    current = (struct node *)malloc(sizeof(struct node));
    current -> data = 3;
    current -> link = NULL;
    head -> link -> link = current;

    add_at_end(head, 67);
    print_data(head);

    return 0;
}

void add_at_end(struct node *head, int data){
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));

    temp ->data = data;
    temp -> link = NULL;

    while(ptr -> link != NULL){
        ptr = ptr -> link;
    }

    ptr -> link = temp;

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
