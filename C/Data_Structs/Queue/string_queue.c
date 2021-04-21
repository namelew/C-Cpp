# include <stdio.h>
# include <stdlib.h>

typedef struct string{
    char caracter;
    struct string *next;
}String;

typedef struct{
    String *first;
    String *tail;
}Queue;

void initQueue(Queue *queue);
char getQueue(Queue *queue);
void putQueue(Queue *queue, char word);
int empytQueue(Queue *queue);

int main(){
    Queue queue;
    char word[100];
    char string;

    initQueue(&queue);
    scanf("%s", word);

    for(int i=0; word[i] != '\0'; i++){
        putQueue(&queue, word[i]);
    }
    while(!empytQueue(&queue)){
        string = getQueue(&queue);
        printf("%c",string);
    }
    printf("\n");

    return 0;
}

void initQueue(Queue *queue){
    queue->first = NULL;
    queue->tail = NULL;
}

char getQueue(Queue *queue){
    char caracter;
    Queue *aux;
    if(!empytQueue(queue)){
        caracter = queue->first->caracter;
        aux = queue->first;
        queue->first= queue->first->next;
        free(aux);
        return caracter;
    }else{
        queue->first = NULL;
        queue->tail = NULL;
    }
}

void putQueue(Queue *queue, char word){
    Queue *aux = queue;
    String *pt = malloc(sizeof(String));
    pt->caracter = word;
    pt->next = NULL;

    if(aux->first == NULL){
        aux->first = pt;
        aux->tail = pt;
    }else{
        aux->tail->next = pt;
        aux->tail = pt;
    }
}

int empytQueue(Queue *queue){
    if(queue -> first == NULL){
        return 1;
    }
    return 0;
}