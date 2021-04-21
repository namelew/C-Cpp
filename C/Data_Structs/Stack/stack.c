# include <stdlib.h>
# include <stdio.h>

typedef struct string{
    char caracter;
    struct string *next;
}String;

typedef struct{
    String *top;
    String *base;
}Stack;

void initStack(Stack *stack);
char pop(Stack *stack);
void push(Stack *stack, char word);
int empytStack(Stack *stack);

int main(){
    Stack stack;
    char word[41];
    char caracter;

    initStack(&stack);

    scanf("%s", word);
    for(int i=0; word[i] != '\0'; i++){
        push(&stack, word[i]);
    }

    while(!empytStack(&stack)){
        caracter = pop(&stack);
        printf("%c", caracter);
    }
    printf("\n");

    return 0;
}

void initStack(Stack *stack){
    stack->top=NULL;
    stack->base=NULL;
}

void push(Stack *stack, char word){
    String *pt = malloc(sizeof(String));
    pt->caracter = word;
    pt->next = NULL;
    if(empytStack(stack)){
        stack->top=pt;
        stack->base=pt;
    }else{
        pt->next = stack->top; 
        stack->top = pt;
    }
}

char pop(Stack *stack){
    String *aux = stack->top;
    char caracter;
    if(!empytStack(stack)){
        caracter = aux->caracter;
        stack->top = aux->next;
        free(aux);
        return caracter;
    }
    return '\0';  
}

int empytStack(Stack *stack){
    if(stack->base == NULL){
        return 1;
    }
    return 0;
}