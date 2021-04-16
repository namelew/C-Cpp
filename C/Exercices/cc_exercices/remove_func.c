# include <stdio.h>
# include <stdlib.h>

typedef struct{
    int day, month, year;
}Data;

struct employee{
    int id;
    char name[41];
    double salary;
    Data bith_date;
    struct employee *next;
};
typedef struct employee Employee;

Employee *add_empl(Employee *head);
void show(Employee *head);
Employee *remove_empl(Employee *head, int id);

int main(){
    Employee *head = malloc(sizeof(Employee));
    head ->next = NULL;
    int op, n, i, id;
    printf("Number of Registers: ");
    scanf("%i", &n);
    for(i = 0; i < n; i++){
        if(i == 0){
            printf("Id: ");
            scanf("%d", &head->id);
            printf("Name: ");
            scanf("%s", &head->name);
            printf("Salary: ");
            scanf("%lf", &head->salary);
            printf("Bith Date: ");
            scanf("%d/%d/%d", &head->bith_date.day, &head->bith_date.month, &head->bith_date.year);
        } else {
            head = add_empl(head);
        }
    }
    printf("Wanna remove one register?(1-Yes, 2-No): ");
    scanf("%i", &op);
    if(op == 1){
        printf("Fired Employee Id`s: ");
        scanf("%i", &id);
        head = remove_empl(head, id);
    } else{
        printf("No register removed\n");
    }

    show(head);

    return 0;
}

Employee *add_empl(Employee *head){
    Employee *pt = malloc(sizeof(Employee));
    printf("Id: ");
    scanf("%d", &pt->id);
    printf("Name: ");
    scanf("%s", &pt->name);
    printf("Salary: ");
    scanf("%lf", &pt->salary);
    printf("Bith Date: ");
    scanf("%d/%d/%d", &pt->bith_date.day, &pt->bith_date.month, &pt->bith_date.year);
    pt -> next = head;
    return pt;
}

void show(Employee *head){
    Employee *pt = malloc(sizeof(Employee));
    pt = head;
    while(pt != NULL){
        printf("- - - - - - - - - - - - - \n");
        printf("Id: %d\n", pt->id);
        printf("Name: %s\n", pt->name);
        printf("Salary: R$ %.2lf\n", pt->salary);
        printf("Bith Date: %d/%2d/%d\n", pt->bith_date.day, pt->bith_date.month, pt->bith_date.year);
        printf("- - - - - - - - - - - - - \n");
        pt = pt -> next;
    }
}

Employee *remove_empl(Employee *head, int id){
    Employee *aux = head;
    Employee *prev;

    while(aux != NULL){
        if(aux -> id == id){
            if(aux == head){
                prev = aux;
                aux = aux -> next;
                free(prev);
                return aux;
            }
            prev -> next = aux -> next;
            free(aux);
            return head;
        }
        prev = aux;
        aux = aux -> next;
    }
    return head;
}