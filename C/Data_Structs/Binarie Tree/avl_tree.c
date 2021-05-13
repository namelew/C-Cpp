# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}Node;

typedef struct tree{
    Node *source;
}Tree;

Node *add_node(Node *source, Node *new);
Node *new_node(int key);
void init_tree(Tree *tree);
void show_tree(Node *source);

int main(){
    Tree tree;
    int key=1;
    init_tree(&tree);

    while(key){
        scanf("%d", &key);
        if(!key){
            break;
        }
        tree.source = add_node(tree.source, new_node(key));
    }

    show_tree(tree.source);

    return 0;
}

void init_tree(Tree *tree){
    tree->source = NULL;
}

Node *new_node(int key){
    Node *n = malloc(sizeof(Node));
    n->value = key;
    n->right = NULL;
    n->left = NULL;
    return n;
}

Node *add_node(Node *source, Node *new){
    if(source == NULL){
        return new;
    }
    if(new->value > source->value){
        source->right = add_node(source->right, new);
    }else{
        source->left = add_node(source->left, new);
    }
    return source;
}

// the print is in-onder mode
void show_tree(Node *source){
    // always 1-left, 2-right
    if(source == NULL){
        return;
    }
    show_tree(source->left);
    printf("%d ", source->value);
    show_tree(source->right);
}