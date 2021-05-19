#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// falta so testar nos casos de testes

typedef struct BinTreeNode {
    char key;
    struct BinTreeNode *left;
    struct BinTreeNode *right;
} BinTreeNode;

BinTreeNode *BinTreeRebuild(char preordemEst[], int rootIndex, int *qtdNos) {
    BinTreeNode *root;
    int qtdNosSubarv;

    // Consideramos o seguinte caso base nesta funcao recursiva:
    //   A arvore binaria contem apenas um no.
    // Este caso ocorre quando abaixo preordemEst[rootIndex + 1] == '0' e
    // preordemEst[rootIndex + 2] == '0'.

    // Para que a funcao tambem possa ser chamada inicialmente para uma arvore
    // binaria vazia, tratamos o caso em que o indice da raiz no percurso em
    // pre-ordem estendido eh negativo
    if (rootIndex < 0) {
        return NULL;
    }

    root = malloc(sizeof(BinTreeNode));
    root->key = preordemEst[rootIndex];
    root->left = NULL;
    root->right = NULL;

    *qtdNos = 1;

    if (preordemEst[rootIndex + 1] != '0') {
        root->left = BinTreeRebuild(preordemEst, rootIndex + 3, &qtdNosSubarv);
        *qtdNos += qtdNosSubarv;
    }

    if (preordemEst[rootIndex + 2] != '0') {
        root->right = BinTreeRebuild(preordemEst, rootIndex + (*qtdNos * 3), &qtdNosSubarv);
        *qtdNos += qtdNosSubarv;
    }

    return root;
}

void free_tree(BinTreeNode *root);
void in_order(BinTreeNode *root);
void pos_order(BinTreeNode *root);

int main() {
    int qtdNos;
    int tamPreordemEst;
    char *preordemEst = NULL;
    BinTreeNode *root;

    // Le a quantidade de nos da arvore binaria
    scanf("%d", &qtdNos);

    tamPreordemEst = qtdNos * 3;
    preordemEst = malloc((tamPreordemEst + 1) * sizeof(char));

    // Le o percurso em pre-ordem estendido da arvore binaria
    scanf("\n");
    fgets(preordemEst, tamPreordemEst + 1, stdin);
    preordemEst[strcspn(preordemEst, "\n")] = '\0';

    // Reconstroi a arvore binaria a partir do seu percurso em pre-ordem
    // estendido
    if (qtdNos > 0) {
        // Nota: Durante a reconstrucao da arvore binaria, a sua quantidade de
        // nos eh calculada e armazenada na variavel qtdNos. Com isso, esta
        // variavel eh sobrescrita com o mesmo valor que tinha inicialmente
        root = BinTreeRebuild(preordemEst, 0, &qtdNos);
    }
    else {
        root = NULL;
    }
    //Faça a magia acontecer
    in_order(root);
    printf("\n");
    pos_order(root);
    printf("\n");
    free_tree(root);
    printf("\n");

    return 0;
}

void in_order(BinTreeNode *root){
    // pronto
    if(root == NULL){
        return;
    }
    in_order(root->left);
    printf("%c", root->key);
    in_order(root->right);
}

void pos_order(BinTreeNode *root){
    // errado problema no output 3 ??
    if(root == NULL){
        return;
    }
    pos_order(root->left);
    pos_order(root->right);
    printf("%c", root->key);
}

void free_tree(BinTreeNode *root){
    if(root == NULL){
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    printf("0");
    free(root);
}
