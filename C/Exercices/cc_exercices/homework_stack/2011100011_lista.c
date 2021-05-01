# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define LINK_SIZE 60

typedef struct idress{
    char link[LINK_SIZE];
    struct idress *next;
}Idress;

typedef struct{
    Idress *top;
    Idress *base;
}Stack;

void init_stack(Stack *stack);
int empyt_stack(Stack *stack);
void put(Stack *stack, char link[LINK_SIZE]);
void pop(Stack *stack);
void end(Stack *stack);

int main(){
    Stack historic;
    char command[LINK_SIZE];

    init_stack(&historic);

    do{
        scanf("%s", command);

        if(strcmp(command, "B") == 0){
            pop(&historic);
        }
        if(strcmp(command, "B") != 0 && strcmp(command, "E") != 0){
            put(&historic, command);
        }

    }while(strcmp(command, "E") != 0);

    end(&historic);

    return 0;
}

void put(Stack *stack, char link[LINK_SIZE]){
    Idress *pt = malloc(sizeof(Idress));
    strcpy(pt->link, link);
    pt->next = NULL;

    if(stack->top == NULL){
        stack->top = pt;
        stack->base = pt;
    }else{
        pt->next = stack->top;
        stack->top = pt;
    }
}


void pop(Stack *stack){
    if(stack->top == NULL){
        printf("Vazio\n");
        return;
    }

    Idress *aux = stack->top;
    stack->top = stack->top->next;
    printf("%s\n", aux->link);
    free(aux);
}

void init_stack(Stack *stack){
    stack->top = NULL;
    stack->base = NULL;
}

int empyt_stack(Stack *stack){
    if(stack->base == NULL){
        return 0;
    }
    return 1;
}

void end(Stack *stack){
    Idress *aux = stack->top;
    Idress *prev;
    if(stack->top == NULL){
        printf("!\n");
        return;
    }
    while(aux!=NULL){
        prev = aux;
        aux = aux->next;
        free(prev);
        printf("@");
    }
    stack->top = NULL;
    stack->base = NULL;
    printf("\n");
}