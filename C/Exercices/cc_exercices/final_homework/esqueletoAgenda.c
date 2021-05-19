
/*
 Este é um esqueleto que deve ser utilizado como base para implementação da Agenda:
  - As funções não têm os parâmetros definidos e os parâmetros, caso necessários, devem ser incluídos.
  - Caso seja necessário novas funções podem ser incluídas
  - Devem ser respeitados os nomes dados para o métodos e estruturas, porém novas estruturas e funções podem ser criados, caso julgue necessário
  - Faça os includes necessários
  - A organização das funções fica a critério do programador
  - Códigos não indentados sofrerão duras penalidades
  - Não serão toleradas variáveis globais
  - Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/

#include <stdio.h>
#include <stdlib.h> 


#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

//Struct que representa a data.
typedef struct {
	int day;
	int month;
	int year;
} Date;


// Estrutura que contém os campos dos registros da agenda
struct MREC {
     char name[30];
     Date birth; 
     char email[40];
     char phone[15];
	struct MREC *next;
	struct MREC *prev;
};

// Tipo criado para instanciar variáveis do tipo agenda
typedef struct MREC Contact;

typedef struct{
     Contact *head;
     Contact *tail;
}Notebook;

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
     int op=EXIT+1;
     printf("%d Finaliza",EXIT);
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

     fgets(pt->name, 30, stdin);
     getchar();
     scanf("%d/%d/%d", &pt->birth.day, &pt->birth.month, &pt->birth.year);
     getchar();
     scanf("%s", pt->email);
     getchar();
     fgets(pt->phone, 15, stdin);
     // deu pau
     if(!note->head){
          note->head = pt;
          note->tail = pt;
          printf("Funcionou\n");
          return;
     }
     get_last(note->head);
     note->tail->next = pt;
     pt->prev = note->tail;
     note->tail = pt;

     printf("%s adicionado a agenda!\n", pt->name);
}
// Permite o cadastro de um contato
// deve ser passado pelo menos o email
void insContactAfter(Notebook *note, char *email)
{
     Contact *aux;
     Contact *pt = malloc(sizeof(Contact));
     pt->next = NULL;
     pt->prev = NULL;

     fgets(pt->name, 30, stdin);
     getchar();
     scanf("%d/%d/%d", &pt->birth.day, &pt->birth.month, &pt->birth.year);
     getchar();
     scanf("%s", pt->email);
     getchar();
     scanf("%f", &pt->phone);
     getchar();

     for(aux = note->head; aux!=NULL; aux=aux->next){
          if(!strcmp(email, aux->email)){
               break;
          }
     }

     if(aux == NULL){
          pt->next = note->head;
          note->head->prev = pt;
          note->head = pt;
          printf("Registro nao encontrado! %s adicionado no inicio da lista\n", pt->name);
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
     printf("%s adicionado apos %s\n", pt->name, aux->name);
}
// Permite excluir um contato da agenda baseado no email
void delContact (Notebook *note, char *email)
{
     if(note->head == NULL){
        printf("Agenda Vazia!\n");
        return;
     }
     Contact *aux = note->head;
     while(aux != NULL){
         if(strcmp(email, aux->email) == 0){break;}
         aux = aux->next;
     }
     if(aux == note->head){
         aux->next->prev = NULL;
         note->head = aux->next;
         free(aux);
         return;
     }
     get_last(note->head);
     if(aux == note->tail){
         aux->prev->next = NULL;
         note->tail = aux->prev;
         free(aux);
         return;
     }
     aux->prev->next = aux->next;
     aux->next->prev = aux->prev;
     free(aux);
}

// Lista o conteúdo da agenda (todos os campos)
void listContacts (Contact *head)
{
     if(head == NULL){
        printf("Agenda Vazia!\n");
        return;
     }
     Contact *aux;
     for(aux = head; aux != NULL; aux= aux->next){
         printf("%s, ", aux->name);
         printf("%d/%d/%d, ",aux->birth.day, aux->birth.month, aux->birth.year);
         printf("%s, ", aux->email);
         printf("%s\n", aux->phone);
     }
}

// Permite consultar um contato da agenda por nome
void queryContact (Contact *head, char *name)
{
     if(head == NULL){
        printf("Agenda Vazia!\n");
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
}

// Permite a atualização dos dados de um contato da agenda
void upContact (Notebook *note, char *email)
{
     Contact *aux = note->head;
     char new_email[40], new_name[30], new_phone[15];
     Date new_birth;

     for(aux = note->head; aux != NULL; aux=aux->next){
          if(!strcmp(email, aux->email)){
               break;
          }
     }

     if(!aux){
          printf("Contato nao encontrado!\n");
          return;
     }

     fgets(new_name, 30, stdin);
     getchar();
     scanf("%d/%d/%d", &new_birth.day, &new_birth.month, &new_birth.year);
     fgets(new_email, 40, stdin);
     getchar();
     fgets(new_phone, 15, stdin);
     getchar();

     aux->birth = new_birth;

     strcpy(aux->name, new_name);
     strcpy(aux->email, new_email);
     strcpy(aux->phone, new_phone);

     printf("Registro Atualizado!\n");

     return;
}

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

void get_last(Notebook *note);

// Programa principal
int main()
{
    int op=EXIT+1;
    char email[40], name[30];
    Notebook note;
    Contact MContact;

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
               fgets(email, 40, stdin);
               getchar();
               insContactAfter(&note, email);
          }
          if(op == 3){
               fgets(email, 40, stdin);
               getchar();
               delContact(&note, email);
          }
          if(op == 4){
               fgets(email, 40, stdin);
               upContact(&note, email);
          }
          if(op == 5){
               fgets(name, 30, stdin); 
               queryContact(note.head, name);
          }
          if(op == 6){
               listContacts(note.head);
          }
    }
    printf("Fechando: ");
    freeMem(&note); // liberar toda a memória alocada
    printf("Agenda Fechada!\n");
    return 0;
}


void get_last(Notebook *note){
    Contact *aux = note->head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    note->tail = aux;
}
