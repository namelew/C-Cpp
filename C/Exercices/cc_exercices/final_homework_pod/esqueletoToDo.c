/*
 Este é um esqueleto que deve ser utilzado como base para implementação da Lista de tarefas;
	- As funções não têm os parâmetros definidos; se necessário, estes devem ser incluídos;
 	- Devem ser respeitados os nomes atribuidos aos métodos e estruturas, porém, novas estruturas e funções podem ser criadas, caso julgue necessário;
	- Faça os includes necessários;
	- A organização das funções fica a critério do programador;
	- Códigos não indentados sofrerão duras penalidades;
	- Não serão toleradas variaveis globais;
	- Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

//Struct que representa a data.
typedef struct{
     int day;
     int month;
}Date;

// Estrutura que contém os campos dos registros das tarefas
struct REC {
     char nome[50];
     int prioridade; // prioridade é minha chave primária na BST
     Date entrega; 
	struct REC *next; // implemente como lista, como árvore BST, AVL...
	struct REC *prev;
};

// Tipo criado para instanciar variaveis do tipo acima
typedef struct REC Task;

typedef struct{
     Task *source;
}Tree;

void init_tree(Tree *tree){ // elimina lixo da memória
     tree->source = NULL;
}

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
     int op;
     printf("1 - Adiciona;\n");
     printf("2 - Deleta;\n");
     printf("3 - Atualiza tarefa;\n");
     printf("4 - Pesquisar tarefa;\n");
     printf("5 - Mostrar todas;\n");
     printf("%d - Finaliza",EXIT);
     printf("\n: ");
     scanf("%d",&op);
     getchar();
     return op;
}

// Permite o cadastro de uma tarefa
Task *insTask(Task *source, Task *new)
{
     if(source == NULL){
          return new;
     }
     if(new->prioridade > source->prioridade){
          source->next = insTask(source->next, new);
     } else {
          source->prev = insTask(source->prev, new);
     }
     return source;
}

Task *new_node(){
     Task *n = malloc(sizeof(Task));
     printf("Nome: ");
     fgets(n->nome, 50, stdin);
     n->nome[strcspn(n->nome, "\n")] = '\0';
     printf("Prioridade: ");
     scanf("%d", &n->prioridade);
     getchar();
     printf("Data de Entrega: ");
     scanf("%d/%d", &n->entrega.day, &n->entrega.month);
     getchar();
     n->prev = NULL;
     n->next = NULL;
     return n;
}

// Permite excluir uma tarefa
void delTask ()
{
    return;
}

// Lista o conteudo da lista de tarefas (todos os campos)
void listTasks (Task *source)
{
    // in order
     if(source == NULL){
          return;
     }
     listTasks(source->prev);
     printf("Nome: %s\n", source->nome);
     printf("Prioridade: %i\n", source->prioridade);
     printf("Data de Entrega: %i/%i\n", source->entrega.day, source->entrega.month);
     listTasks(source->next);
}

// Permite consultar uma tarefa da lista pelo nome
void queryTask ()
{
     return;
}

// Permite a atualização dos dados de uma tarefa
void upTask ()
{
     return;
}

// Programa principal
int main()
{
     int op;
     Tree tree;
     init_tree(&tree);
     Task *new;
     do
     {
          op=menu();
          switch(op)
          {
               case 1:
                    new = new_node();
                    tree.source = insTask(tree.source, new);
                    break;
               case 2: delTask();
               case 3: upTask();
               case 4: queryTask();
               case 5: listTasks(tree.source);
          }
     }while(op!=EXIT);

     return 0;
}
