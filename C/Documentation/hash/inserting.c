# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define SLOTS 20
# define OVERFLOW 5

typedef struct{
    int id;
    char name[41];
    double salary;
    int ages;
}Employee;

int hash(int age);
void init_hash(Employee *list);
void add_employee(Employee *list);
void show_hash(Employee *list);
void search_age(int age, Employee *list);

int main(){
    Employee employees[SLOTS+OVERFLOW];
    int op = 1, ages;

    init_hash(employees);

    while(op){
        printf("0-Quit\n1-Add\n2-Search\n3-Show Hash Table\n");
        scanf("%d", &op);
        if(op == 1){
            add_employee(employees);
        }
        if(op == 2){
            scanf("%d", &ages);
            search_age(ages, employees);
        }
        if(op == 3){
            show_hash(employees);
        }
    }
    return 0;
}

int hash(int age){ // calculo do hash
    return age%SLOTS;
}

void init_hash(Employee *list){
    // iniciando o array de hash
    for(int i=0; i<SLOTS+OVERFLOW; i++){
        list[i].id = -1;
        list[i].ages = -1;
        strcpy(list[i].name, " "); // faz o print do hash table ficar bonito
        list[i].salary = 0.0;
    }
    
}

void add_employee(Employee *list){
    // adicionando um valor na hash table
    Employee aux;
    int slot, i;

    scanf("%i", &aux.id);
    scanf("%s", &aux.name);
    scanf("%lf", &aux.salary);
    scanf("%i", &aux.ages);

    slot = hash(aux.ages);
    if(list[slot].ages == -1){
        list[slot] = aux;
    }else{
        for(i = SLOTS; i < SLOTS+OVERFLOW; i++){
            if(list[i].ages == -1){
                list[i] = aux;
                printf("Crash! Register moved for the overflow area\n");
                break;
            }
        }
        if(i == SLOTS+OVERFLOW){
            printf("Overflow area is full\n");
        }
    }
}

void show_hash(Employee *list){
    // monstrando a hash table
    int i;
    printf("Database\n");
    for(i = 0; i < SLOTS; i++){
        printf("|%i|%s|%.2lf|%i|\n", list[i].id, list[i].name,list[i].salary, list[i].ages);
    }
    printf("Overflow Area\n");
    for(i = SLOTS; i < SLOTS+OVERFLOW; i++){
        printf("|%i|%s|%.2lf|%i|\n", list[i].id, list[i].name,list[i].salary, list[i].ages);
    }
}

void search_age(int age, Employee *list){
    // procurando um valor na hash table
    int key = hash(age);
    if(list[key].ages == age){
        printf("|%i|%s|%.2lf|%i|\n", list[key].id, list[key].name,list[key].salary, list[key].ages);
    } else{
        printf("Employee not founded\n");
    }
}
