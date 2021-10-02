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
     int prioridade;
     Date entrega; 
	struct REC *next; // implemente como lista, como árvore BST, AVL...
	struct REC *prev;
};

// Tipo criado para instanciar variaveis do tipo acima
typedef struct REC Task;

typedef struct registro{
     char nome[50];
     int prioridade;
     Date entrega;
}Registro;

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

int Vazio(Task *source){ // checa se a árvore está ou não vazia
     if(source == NULL){
          return 1;
     }
     return 0;
}

int depthSubTree(Task *source){ // vê a profundidade de um nodo da árvore
	int depthLeft, depthRight;

	if (source == NULL)
		return 0;

	depthLeft  = depthSubTree(source->prev);
	depthRight = depthSubTree(source->next);

	return 1 + (depthRight>depthLeft?depthRight: depthLeft);
}

Task* ll(Task *source){ // rotação left simples
	Task *aux = source->prev;
	source->prev = aux->next;
	aux->next = source;

	return aux;
}

Task* rr(Task *source){ // rotação right simples
	Task *aux = source->next;
	source->next = aux->prev;
	aux->prev = source;

	return aux;
}

Task* lr(Task* source){ // rotação composta left right
	source->prev = rr(source->prev);
	return ll(source);
}

Task* rl(Task* source){ // rotação composta right left
	source->next = ll(source->next);
	return rr(source);
}

Task* checkBalance(Task* source){ // função principal da avl tree
	int balanceFactor = depthSubTree(source->prev) - depthSubTree(source->next);
	int sonBalance;
	Task *son;
	
	if (balanceFactor > 1){
		son = source->prev;
		sonBalance = depthSubTree(son->prev) - depthSubTree(son->next);
		if (sonBalance > 0 ){
			source = ll(source);
		}else{
			source = lr(source);
		}
		
	}else if (balanceFactor < -1){
		son = source->next;
		sonBalance = depthSubTree(son->prev) - depthSubTree(son->next);
		if (sonBalance < 0 ){
			source = rr(source);
		}else{
			source = rl(source);
		}
	}
	return source;
}


// encontra o registro dentro da Tree
Task *achaTask(Task *source, char *key){
     if(source == NULL || !strcmp(key, source->nome)){
          return source;
     }
     if(strcmp(key, source->nome) > 0){
          achaTask(source->next, key);
     } else{
          achaTask(source->prev, key);
     }
}

// Permite o cadastro de uma tarefa
Task *insTask(Task *source, Task *new)
{
     if(source == NULL){
          return new;
     }
     if(strcmp(new->nome, source->nome) > 0){
          source->next = insTask(source->next, new);
     } else {
          source->prev = insTask(source->prev, new);
     }

     source = checkBalance(source);
     
     return source;
}

// Cria uma tarefa
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

Task* minValue(Task* node){ // encontra o menor valor da arvore da direita
    Task* current = node;
 
    while (current && current->prev != NULL)
        current = current->prev;
 
    return current;
}

// Permite excluir uma tarefa
Task *delTask (Task *source, char *key)
{
     if (source == NULL)
          return source;
 
     if (strcmp(key, source->nome) < 0)
          source->prev = delTask(source->prev, key);

     else if (strcmp(key, source->nome) > 0)
          source->next = delTask(source->next, key);
 
     else {
          if (source->prev==NULL && source->next==NULL){
               free(source);
               return NULL;
          } // nó sem filhos
          else if (source->prev == NULL) { // nó com apenas o filho da direita
               struct node* temp = source->next;
               free(source);
               return temp;
          }else if (source->next == NULL) { // nó com apenas o filho da esquerda
               struct node* temp = source->prev;
               free(source);
               return temp;
          }
          // nó com dois filhos

          Task* temp = minValue(source->next); // procura o menor valor da árvore da direita

          // copia o valor do nó encontrado no nó que desejamos apagar  
          strcpy(source->nome, temp->nome);
          source->prioridade = temp->prioridade;
          source->entrega.day = temp->entrega.day;
          source->entrega.month = temp->entrega.month;
 
          source->next = delTask(source->next, temp->nome); //e elimina o valor duplicado
    }
    return source;
}

// Lista o conteudo da lista de tarefas (todos os campos)
void listTasks (Task *source)
{
     if(source == NULL){
          return;
     }
     listTasks(source->prev);
     printf("----------------------------------\n");
     printf("Nome: %s\n", source->nome);
     printf("Prioridade: %i\n", source->prioridade);
     printf("Data de Entrega: %d/%d\n", source->entrega.day, source->entrega.month);
     listTasks(source->next);
}

int sizeTree (Task *source){ // retorna o tamanho da arvore
     if(source == NULL){
          return 0;
     }
     int left = sizeTree(source->prev);
     int right = sizeTree(source->next);

     int total = left + right + 1;

     return total;
}

// Permite consultar uma tarefa da lista pelo nome
void queryTask (Task *source, char *key)
{
     Task *result = achaTask(source, key);
     if(!result){
          printf("Not founded!\n");
          return;
     }
     printf("----------------------------------\n");
     printf("Nome: %s\n", source->nome);
     printf("Prioridade: %i\n", source->prioridade);
     printf("Data de Entrega: %d/%d\n", source->entrega.day, source->entrega.month);
}

// Permite a atualização dos dados de uma tarefa
void upTask (Task *source, char *key)
{
     Task *aux = achaTask(source, key);
     printf("Nova prioridade: ");
     scanf("%d", &aux->prioridade);
     printf("Nova data de entrega: ");
     scanf("%d/%d", &aux->entrega.day, &aux->entrega.month);

     printf("Dados alterados\n");
}

int makeBackup(Task *source, Registro *backup, int tam){ // retira os dados da arvore e os coloca no vetor
     if(source == NULL){return tam;}

     strcpy(backup[tam].nome, source->nome);
     backup[tam].prioridade = source->prioridade;
     backup[tam].entrega.day = source->entrega.day;
     backup[tam].entrega.month = source->entrega.month;

     tam++;

     if(source->prev != NULL){
          tam = makeBackup(source->prev, backup, tam);
     }
     if(source->next != NULL){
          tam = makeBackup(source->next, backup, tam);
     }

     return tam;
}

void Update(Task *source){ // escreve os dados no arquivo
     int *lixo = malloc(sizeof(int));
     int *tam = malloc(sizeof(int));

     *tam = sizeTree(source);
     Registro backup[*tam];

     *lixo = makeBackup(source, backup, 0);

     FILE *arq = fopen("database.txt", "wb");
     FILE *tamanho = fopen("tamanho.txt", "wb");

     if(fwrite(backup, sizeof(Registro), *tam, arq) != *tam){
          printf("Erro na gravação\n");
     }

     if(fwrite(tam, sizeof(int), 1, tamanho) != 1){
          printf("Erro na gravação\n");
     }

     free(tam);
     free(lixo);
     fclose(arq);
     fclose(tamanho);
}

Task *Download(FILE *arq, Task *source){ // transfere do arquivo para a memória principal
     if(arq == NULL){
          return NULL;
     }
     FILE *tamanho = fopen("tamanho.txt", "rb");
     int *tam = malloc(sizeof(int));

     fread(tam, sizeof(int), 1, tamanho);

     Registro download[*tam];

     fread(download, sizeof(Registro), *tam, arq);

     for(int i = 0; i < *tam; i++){
          Task *new = malloc(sizeof(Task));
          strcpy(new->nome, download[i].nome);
          new->prioridade = download[i].prioridade;
          new->entrega.day = download[i].entrega.day;
          new->entrega.month = download[i].entrega.month;
          new->next = NULL;
          new->prev = NULL;
          source = insTask(source, new);
     }

     free(tam);
     fclose(tamanho);
     return source;
}

void free_tree(Task *source){
     if(source == NULL){
          return;
     }
     free_tree(source->next);
     free_tree(source->prev);
     free(source);
}

// Programa principal
int main()
{
     int op;
     Tree MP;
     init_tree(&MP);
     Task *new;
     char nome[50];

     FILE *arq = fopen("database.txt", "rb");
     MP.source = Download(arq, MP.source);
     fclose(arq);
     do
     {
          op=menu();
          switch(op)
          {
               case 1:
                    new = new_node();
                    MP.source = insTask(MP.source, new);
                    printf("----------------------------------\n");
                    break;
               case 2:
                    printf("Nome: ");
                    fgets(nome, 50, stdin);
                    nome[strcspn(nome, "\n")] = '\0';
                    if(!Vazio(MP.source)){
                         MP.source = delTask(MP.source, nome);
                    } else{
                         printf("Registro vazio\n");
                    }
                    printf("----------------------------------\n");
                    break;
               case 3:
                    printf("Nome: ");
                    fgets(nome, 50, stdin);
                    nome[strcspn(nome, "\n")] = '\0';
                    if(!Vazio(MP.source)){
                         upTask(MP.source, nome);
                    } else{
                         printf("Registro vazio\n");
                    }
                    printf("----------------------------------\n");
                    break;
               case 4:
                    printf("Nome: ");
                    fgets(nome, 50, stdin);
                    nome[strcspn(nome, "\n")] = '\0';
                    if(!Vazio(MP.source)){
                         queryTask(MP.source, nome);
                    } else{
                         printf("Registro vazio\n");
                    }
                    printf("----------------------------------\n");
                    break;
               case 5: 
                    if(!Vazio(MP.source)){
                         listTasks(MP.source);
                    } else{
                         printf("Registro vazio\n");
                    }
                    printf("----------------------------------\n");
          }
     }while(op!=EXIT);

     Update(MP.source);
     free_tree(MP.source);
     return 0;
}
