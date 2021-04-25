# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Falta testar nos casos de teste padrões
typedef struct{
    int day, month, year;
}Date;

typedef struct student{
    char enrollment[11];
    char name[41];
    Date birth_day;
    float gpa;
    struct student *next;
    struct student *prev;
}Student;

typedef struct{
    Student *head;
    Student *tail;
}List;

void *insert_student(List *list, char prev_enroll[]);
void *remove_student(List *list, char enrollment[]);
void list_head(Student *head);
void list_tail(List *list);
void end(List *list);
void get_last(List *list);

int main(){
    List list;
    list.head = NULL;
    list.tail = NULL;
    int op = 1;
    char enrollment[11];

    while(op){
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            end(&list);
            break;
        case 1:
            scanf("%s", enrollment);
            insert_student(&list, enrollment);
            break;
        case 2:
            scanf("%s", enrollment);
            remove_student(&list, enrollment);
            break;
        case 3:
            list_head(list.head);
            break;
        case 4:
            list_tail(&list);
            break;
        default:
            break;
        }
    }

    return 0;
}

void *insert_student(List *list, char prev_enroll[]){
    // Ta tranquilo
    Student *aux;
    Student *pt = malloc(sizeof(Student));
    pt->next = NULL;
    pt->prev = NULL;

    scanf("%s", pt->enrollment);
    scanf("%s", pt->name);
    scanf("%i/%i/%i", &pt->birth_day.day, &pt->birth_day.month, &pt->birth_day.year);
    scanf("%f", &pt->gpa);

    if(list->head == NULL){
        list->head = pt;
        list->tail = pt;
    }else{
        for(aux = list->head; aux!=NULL; aux=aux->next){
            if(!strcmp(prev_enroll, aux->enrollment)){
                break;
            }
        }
        if(aux == NULL){
            pt->next = list->head;
            list->head->prev = pt;
            list->head = pt;
        }else{
            if(aux->next == NULL && aux != NULL){
                pt->next = aux->next;
                aux->next = pt;
                pt->prev = aux;
            }else{
                aux->next->prev=pt;
                pt->next = aux->next;
                aux->next = pt;
                pt->prev = aux;
            }
        }
    }
}

void *remove_student(List *list, char enrollment[]){
    // Ta tranquilo
    Student *aux = list->head;
    while(aux != NULL){
        if(strcmp(enrollment, aux->enrollment) == 0){break;}
        aux = aux->next;
    }
    if(aux == list->head){
        aux->next->prev = NULL;
        list->head = aux->next;
        free(aux);
        return;
    }
    get_last(list);
    if(aux == list->tail){
        aux->prev->next = NULL;
        list->tail = aux->prev;
        free(aux);
        return;
    }
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;
    free(aux);
}

void list_head(Student *head){
    // Ta tranquilo
    Student *aux;
    for(aux = head; aux != NULL; aux= aux->next){
        printf("%s, ", aux->enrollment);
        printf("%s, ", aux->name);
        printf("%d/%d/%d, ",aux->birth_day.day, aux->birth_day.month, aux->birth_day.year);
        printf("%.2f\n", aux->gpa);
    }
}

void list_tail(List *list){
    // Ta tranquilo
    get_last(list);
    Student *aux;
    for(aux = list->tail; aux != NULL; aux= aux->prev){
        printf("%s, ", aux->enrollment);
        printf("%s, ", aux->name);
        printf("%d/%d/%d, ",aux->birth_day.day, aux->birth_day.month, aux->birth_day.year);
        printf("%.2f\n", aux->gpa);
    }
}

void end(List *list){
    // Ta tranquilo
    Student *aux, *prev;
    aux = list->head;
    while(aux != NULL){
        prev = aux;
        aux = aux->next;
        free(prev);
        printf("*");
    }
    printf("\n");
    list->head = NULL;
    list->tail = NULL;
}

void get_last(List *list){
    // A principio funciona
    Student *aux = list->head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    list->tail = aux;
}