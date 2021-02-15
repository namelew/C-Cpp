# include <stdio.h>
# include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

int main(void){
    struct node * add_at_end(struct node *ptr, int data);
    struct node *head = (struct node *)malloc(sizeof(struct node));

    head ->data = 45;
    head ->link = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 98);
    ptr = add_at_end(ptr, 3);
    ptr = add_at_end(ptr, 67);

    ptr = head;

    while (ptr != NULL){
        printf("%i ", ptr -> data);
        ptr = ptr -> link;
    }
    

    return 0;
}

struct node* add_at_end(struct node *ptr, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;

    return temp;
}