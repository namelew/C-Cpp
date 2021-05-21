#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


#define EXIT 10  // valor fixo para a opção que finaliza a aplicação
#define TAM_N 30 // tamanho das strings que armazenam nomes
#define TAM_E 40 // tamanho das strings que armazenam emails
#define TAM_P 15 // tamanho das stringas que armazenam numeros de telefone/celular

//Struct que representa a data.
typedef struct {
	int day;
	int month;
	int year;
} Date;


// Estrutura que contém os campos dos registros da agenda
struct MREC {
     char name[TAM_N];
     Date birth; 
     char email[TAM_E];
     char phone[TAM_P];
	struct MREC *next;
	struct MREC *prev;
};

// Tipo criado para instanciar variáveis do tipo agenda
typedef struct MREC Contact;

// estrutura que armazena o ultimo e o primeiro valor da lista
typedef struct{
     Contact *head;
     Contact *tail;
}Notebook;

void get_last(Notebook *note);
void init_list(Notebook *note);

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
     int op=EXIT+1;
     printf("1 - Add\n2 - Add_Next\n3 - Del\n4 - Upg\n5 - Query\n6 - List\n");
     printf("%d - Exit",EXIT);
     printf("\n: ");
     scanf("%d",&op);
     return op;
}

// Permite o cadastro de um contato
void insContact(Notebook *note)
{
     Contact *aux;
     Contact *pt = malloc(sizeof(Contact));
     pt->next = NULL;
     pt->prev = NULL;

     printf("name: ");
     fgets(pt->name, TAM_N, stdin);
     pt->name[strcspn(pt->name, "\n")] = '\0';
     printf("birth: ");
     scanf("%d/%d/%d", &pt->birth.day, &pt->birth.month, &pt->birth.year);
     getchar();
     printf("email: ");
     scanf("%s", pt->email);
     getchar();
     printf("phone: ");
     fgets(pt->phone, TAM_P, stdin);
     pt->phone[strcspn(pt->phone, "\n")] = '\0';
     // deu pau
     if(note->head == NULL){
          note->head = pt;
          note->tail = pt;
          printf("%s add in the notebook!\n", pt->name);
          return;
     }
     get_last(note);
     note->tail->next = pt;
     pt->prev = note->tail;
     note->tail = pt;

     printf("%s add in the notebook!\n", pt->name);
}
// Permite o cadastro de um contato
// deve ser passado pelo menos o email
void insContactAfter(Notebook *note, char *email)
{
     Contact *aux;
     Contact *pt = malloc(sizeof(Contact));
     pt->next = NULL;
     pt->prev = NULL;

     printf("name: ");
     fgets(pt->name, TAM_N, stdin);
     pt->name[strcspn(pt->name, "\n")] = '\0';
     printf("birth: ");
     scanf("%d/%d/%d", &pt->birth.day, &pt->birth.month, &pt->birth.year);
     getchar();
     printf("email: ");
     scanf("%s", pt->email);
     getchar();
     printf("phone: ");
     fgets(pt->phone, TAM_P, stdin);
     pt->phone[strcspn(pt->phone, "\n")] = '\0';

     if(!note->head){
          note->head = pt;
          note->tail = pt;
          printf("empyt notebook! %s add in the beggining\n", pt->name);
          return;
     }

     for(aux = note->head; aux!=NULL; aux=aux->next){
          if(!strcmp(email, aux->email)){
               break;
          }
     }

     if(aux == NULL){
          pt->next = note->head;
          note->head->prev = pt;
          note->head = pt;
          printf("record not founded! %s add on beggining of the notebook\n", pt->name);
          return;
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
     printf("%s add next to %s\n", pt->name, aux->name);
}
// Permite excluir um contato da agenda baseado no email
void delContact (Notebook *note, char *email)
{
     if(note->head == NULL){
        printf("empyt notebook!\n");
        return;
     }
     Contact *aux = note->head;
     while(aux != NULL){
         if(strcmp(email, aux->email) == 0){break;}
         aux = aux->next;
     }
     if(!aux){
          printf("contact not founded!\n");
          return;
     }
     printf("deleting %s...\n", aux->name);
     if(aux == note->head){
          if(aux->next == NULL){
               free(aux);
               note->head = NULL;
               note->tail = NULL;
               printf("record removed!\n");
               return;
          }
          aux->next->prev = NULL;
          note->head = aux->next;
          free(aux);
          printf("record removed!\n");
          return;
     }
     get_last(note);
     if(aux == note->tail){
         aux->prev->next = NULL;
         note->tail = aux->prev;
         free(aux);
         printf("record removed!\n");
         return;
     }
     aux->prev->next = aux->next;
     aux->next->prev = aux->prev;
     free(aux);
     printf("record removed!\n");
}

// Lista o conteúdo da agenda (todos os campos)
void listContacts (Contact *head)
{
     if(head == NULL){
        printf("empyt notebook!\n");
        return;
     }
     Contact *aux;
     for(aux = head; aux != NULL; aux= aux->next){
         printf("%s, ", aux->name);
         printf("%d/%d/%d, ", aux->birth.day, aux->birth.month, aux->birth.year);
         printf("%s, ", aux->email);
         printf("%s\n", aux->phone);
     }
}

// Permite consultar um contato da agenda por nome
void queryContact (Contact *head, char *name)
{
     if(head == NULL){
        printf("empyt notebook!\n");
        return;
     }
     Contact *aux;
     for(aux = head; aux != NULL; aux= aux->next){
          if(strcmp(name, aux->name) == 0){
               printf("%s, ", aux->name);
               printf("%d/%d/%d, ",aux->birth.day, aux->birth.month, aux->birth.year);
               printf("%s, ", aux->email);
               printf("%s\n", aux->phone);
               return;
          }
     }
     printf("record not founded!\n");
}

// Permite a atualização dos dados de um contato da agenda
void upContact (Notebook *note, char *email)
{
     Contact *aux = note->head;
     char new_email[TAM_E], new_name[TAM_N], new_phone[TAM_P];
     Date new_birth;

     for(aux = note->head; aux != NULL; aux=aux->next){
          if(!strcmp(email, aux->email)){
               break;
          }
     }

     if(!aux){
          printf("contact not founded!\n");
          return;
     }
     printf("name: ");
     fgets(new_name, TAM_N, stdin);
     new_name[strcspn(new_name, "\n")] = '\0';
     printf("birth: ");
     scanf("%d/%d/%d", &new_birth.day, &new_birth.month, &new_birth.year);
     getchar();
     printf("email: ");
     fgets(new_email, TAM_E, stdin);
     new_email[strcspn(new_email, "\n")] = '\0';
     printf("phone: ");
     fgets(new_phone, TAM_P, stdin);
     new_phone[strcspn(new_phone, "\n")] = '\0';

     aux->birth.day = new_birth.day;
     aux->birth.month = new_birth.month;
     aux->birth.year = new_birth.year;

     strcpy(aux->name, new_name);
     strcpy(aux->email, new_email);
     strcpy(aux->phone, new_phone);

     printf("record upgraded!\n");

     return;
}

// libera toda a memoria alocada para a criação da agenda
void freeMem(Notebook *note){
     Contact *aux, *prev;
     aux = note->head;
     while(aux != NULL){
          prev = aux;
          aux = aux->next;
          free(prev);
          printf("*");
     }
     printf("\n");
     note->head = NULL;
     note->tail = NULL;
}

// Programa principal
int main()
{
    int op=EXIT+1;
    char email[TAM_E], name[TAM_N];
    Notebook note;
    init_list(&note);

    while (op!=EXIT)
    {
          op=menu();
          getchar();
          if(op == 10){
               break;
          }
          if(op == 1){
               insContact(&note);
          }
          if(op == 2){
               printf("Next to(email): ");
               fgets(email, TAM_E, stdin);
               email[strcspn(email, "\n")] = '\0';
               insContactAfter(&note, email);
          }
          if(op == 3){
               printf("record to delete(email): ");
               fgets(email, TAM_E, stdin);
               email[strcspn(email, "\n")] = '\0';
               delContact(&note, email);
          }
          if(op == 4){
               printf("record to upgrade(email): ");
               fgets(email, TAM_E, stdin);
               email[strcspn(email, "\n")] = '\0';
               upContact(&note, email);
          }
          if(op == 5){
               printf("query(name): ");
               fgets(name, TAM_N, stdin);
               name[strcspn(name, "\n")] = '\0';
               queryContact(note.head, name);
          }
          if(op == 6){
               listContacts(note.head);
          }
    }
    printf("closing: ");
    freeMem(&note);
    printf("notebook closed!\n");

    return 0;
}

// acha o ultimo valor da lista(tail)
void get_last(Notebook *note){
    Contact *aux = note->head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    note->tail = aux;
}

// inicia a lista colocando o tail e o head para NULL
void init_list(Notebook *note){
     note->head = NULL;
     note->tail = NULL;
}