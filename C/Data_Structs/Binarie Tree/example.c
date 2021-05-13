# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int value;
    struct node *right;
    struct node *left;
}Node;

typedef struct{
    Node *source;
}Tree;

Node *add_node(Node *source, Node *new);
Node *new_node(int key);
void free_tree(Node *source);
void show_tree(Node *source);
void init_tree(Tree *tree);

int main(){
    Tree tree;
    int key = 1, op = -1;
    init_tree(&tree);

    while(op){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &key);
            tree.source = add_node(tree.source, new_node(key));
        }
        if(op == 2){
            show_tree(tree.source);
            printf("\n");
        }
        if(op == 3){
            scanf("%d", &key);
            search_node(tree.source, key);
            printf("\n");
        }
        if(!op){
            free_tree(tree.source);
            printf("\n");
        }

    }

    return 0;
}

void init_tree(Tree *tree){
    tree->source = NULL;
}

Node *add_node(Node *source, Node *new){
    if(source == NULL){
        return new;
    }
    if(new->value > source->value){
        source->right = add_node(source->right, new);
    } else {
        source->left = add_node(source->left, new);
    }
    return source;
}

Node *new_node(int key){
    Node *n = malloc(sizeof(Node));
    n->value = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void free_tree(Node *source){
    if(source == NULL){return;}
    free_tree(source->left);
    free_tree(source->right);
    printf("*");
    free(source);
}

void show_tree(Node *source){
    if(source == NULL){
        return;
    }
    show_tree(source->left);
    printf("%d ", source->value);
    show_tree(source->right);
}

void search_node(Node *source,int key){
    if(source == NULL){
        printf("%d", key);
        return;
    }
    if(key > source->value){
        search_node(source->right, key);
    } else{
        search_node(source->left, key);
    }
}