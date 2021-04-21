# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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
void list_tail(Student *tail);
void end(List *list);

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
            list_tail(list.tail);
            break;
        default:
            break;
        }
    }

    return 0;
}

void *insert_student(List *list, char prev_enroll[]){
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
        for(aux = list->head; aux != NULL; aux= aux ->next){
            if(!strcmp(prev_enroll, aux->enrollment)){
                break;
            }
        }
        // se aux->next = NULL, da overflow
        aux->next->prev=pt;
        pt->next = aux->next;
        aux->next = pt;
        pt->prev = aux; 
    }

}

void *remove_student(List *list, char enrollment[]){
    Student *aux;
}

void list_head(Student *head){
    Student *aux;

}

void list_tail(Student *tail){
    Student *aux;
}

void end(List *list){
    Student *aux;
}