#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NA_TAM 40

typedef struct{
    int day;
    int month;
    int year;
}Data;

struct student{
    char enrollment[11];
    char name[NA_TAM+1];
    Data birth_date;
    float gpa;
    struct student *next;
};
typedef struct student Student;

Student *remove_student(Student *head, char enrollment[NA_TAM+1]);
Student *insert_student(Student *head);
void show(Student *head, int reverse);
void tam(Student *head);
void end(Student *head);

int main(){
    Student *head = NULL;
    char enrollment[11];
    int op=1;

    while(op != 0){
        scanf("%d", &op);
        if(op == 0){
            //complete
            end(head);
        }
        if(op == 1){
            //complete
            head = insert_student(head);
        }
        if(op == 2){
            fgets(enrollment, sizeof(enrollment), stdin);
            head = remove_student(head, enrollment);
        }
        if(op == 3){
            //complete
            show(head, 0);
        }
        if(op == 4){
            show(head, 1);
        }
        if(op == 5){
            //complete
            tam(head);
        }
    }
    return 0;
}

Student *remove_student(Student *head, char enrollment[NA_TAM+1]){
    Student *aux, *prev;
    prev = NULL;
    aux = head;
    while(aux != NULL){
        // errado, nao eh desse jeito 
        if(aux->enrollment == enrollment){
            if(aux==head){
                head = aux -> next;
                free(aux);
                return head;
            }
            prev->next = aux->next;
            free(aux);
            return head;
        }
        prev = aux;
        aux = aux -> next;
    }
}

Student *insert_student(Student *head){
    Student *aux;
    Student *pt = malloc(sizeof(Student));
    pt->next = NULL;
    scanf("%s", pt->enrollment);
    scanf("%s", pt->name);
    scanf("%d/%d/%d", &pt->birth_date.day, &pt->birth_date.month, &pt->birth_date.year);
    scanf("%f", &pt->gpa);

    if(head == NULL){
        head = pt;
        head->next = NULL;
        return head;
    }
    if(head -> next == NULL){
        head->next = pt;
    }else{
        aux = head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux -> next = pt;
    }
    return head;
}

void show(Student *head, int reverse){
    Student *aux = head;
    if(!reverse){
        printf("%s, %s, %2d/%2d/%d, %.2f\n", aux->enrollment, aux->name, aux->birth_date.day, aux->birth_date.month, aux->birth_date.year, aux->gpa);
        if(head->next== NULL){
            return;
        }
        show(head->next, 0);
    }else{
        printf("Unavalible!\n");
    }
}

void tam(Student *head){
    Student *aux = head;
    int i=0;
    while(aux != NULL){
        i++;
        aux = aux -> next;
    }
    printf("%i\n", i);
}

void end(Student *head){
    Student *aux=head;
    Student *prev;
    while(aux != NULL){
        prev = aux;
        aux = aux -> next;
        free(prev);
        printf("-");
    }
    printf("\n");
}