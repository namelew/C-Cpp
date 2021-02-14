# include <stdlib.h>
# include <stdio.h>

struct node{
    int data;
    struct node *link;
};

int main(void){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *current = (struct node *)malloc(sizeof(struct node));
    void count_of_nodes(struct node *head);

    head ->data = 45;
    head -> link = NULL;

    current -> data = 98;
    current -> link = NULL;
    head -> link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current -> data = 3;
    current -> link = NULL;
    head -> link -> link = current;

    count_of_nodes(head);
    
    return 0;
}

void count_of_nodes(struct node *head){
    int count = 0;
    if (head -> link == NULL){
        printf("Linked List is empty\n");
    } else {
        struct node *ptr = head;
        while(ptr != NULL){
            ++count;
            ptr = ptr -> link;
        }
        printf("%i\n", count);
    }


}