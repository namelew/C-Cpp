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

Employee *add_func(Employee *head);
void show(Employee *head);

int main(){
    Employee *head = malloc(sizeof(Employee));
    head ->next = NULL;
    int op;
    printf("Id: ");
    scanf("%d", &head->id);
    printf("Name: ");
    scanf("%s", &head->name);
    printf("Salary: ");
    scanf("%lf", &head->salary);
    printf("Bith Date: ");
    scanf("%d/%d/%d", &head->bith_date.day, &head->bith_date.month, &head->bith_date.year);
    printf("Wanna add one more employee?(1-Yes, 2-No) ");
    scanf("%i", &op);
    while(op != 2){
        head = add_func(head);
        printf("Wanna add one more employee?(1-Yes, 2-No) ");
        scanf("%i", &op);
    }
    show(head);

    return 0;
}

Employee *add_func(Employee *head){
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