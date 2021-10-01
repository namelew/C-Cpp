#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tinfo {
  int age;
};

struct tnode {
  struct tinfo info;
  struct tnode *left, *right;
};

struct ttree {
   struct tnode *root;
};

typedef struct tinfo vinfo;
typedef struct tnode vnode;
typedef struct ttree vtree;

void initTree(vtree *t)
{
	t->root=NULL;
}

vnode *newNode(vinfo i)
{
	vnode *n;
	n=(vnode *)malloc(sizeof(vnode));
	n->info.age=i.age;
	n->left=NULL;
	n->right=NULL;
	return n;
}

// insert a node in the Binary Search Tree (iterative)
void insertNodeI (vtree *t, vnode *n)
{
	vnode  *actn, *prevn;
	int dir;
	if (t->root==NULL) // tree is empty
	{
		t->root=n;
		return;
	}
	// search for the right place to insert n
	actn=t->root; // start from the root
	dir=0;
	while (actn!=NULL)
	{
		prevn=actn;
		if (n->info.age < actn->info.age) // new age is smaller, go to left
		{
		   actn=actn->left;
		   dir=0; // the new node must be inserted as left child
		}
		else
		{
		   actn=actn->right;  // otherwise, go to right
		   dir=1; // the new node must be inserted as right child
		}
     }
     if (dir) // right child
        prevn->right=n;
     else
        prevn->left=n;
     return;
}


void showTreeRIn(vnode *root)
{
	if (root==NULL) 
	{
		printf("\n");
	    return;
	}
	showTreeRIn(root->left);
	printf("%d ",root->info.age);
	showTreeRIn(root->right);
}

void freeTree(vnode *n)
{
	if (n==NULL) return;
	freeTree(n->left);
	freeTree(n->right);
    free(n);
}

int depthSubTree(vnode *root){
	int depthLeft, depthRight;

	if (root == NULL)
		return 0;

	depthLeft  = depthSubTree(root->left);
	depthRight = depthSubTree(root->right);

	return 1 + (depthRight>depthLeft?depthRight: depthLeft); //condição ternaria
	// 135 if is the same.... 
	//if ((depthRight>depthLeft))
	// 	return depthRight;
	// else	
	// 	return depthLeft;
}


vnode* ll(vnode *root){
	vnode *newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	return newRoot;
}

vnode* rr(vnode *root){
	vnode *newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;

	return newRoot;
}

vnode* lr(vnode* root){
	root->left = rr(root->left);
	return ll(root);
}

vnode* rl(vnode* root){
	root->right = ll(root->right);
	return rr(root);
}

// int checkBalance(vnode* root){
// 	return depthSubTree(root->left) - depthSubTree(root->right);
// }
vnode* checkBalance(vnode* root){
	int balanceFactor = depthSubTree(root->left) - depthSubTree(root->right);
	int sonBalance;
	vnode *son;
	
	if (balanceFactor > 1){
		son = root->left;
		sonBalance = depthSubTree(son->left) - depthSubTree(son->right);
		if (sonBalance > 0 ){
			printf("%d unbalance LL!\n", root->info.age);
			root = ll(root);
		}else{
			printf("%d unbalance LR!\n", root->info.age);
			root = lr(root);
		}
		
	}else if (balanceFactor < -1){
		son = root->right;
		sonBalance = depthSubTree(son->left) - depthSubTree(son->right);
		if (sonBalance < 0 ){
			printf("%d unbalance RR!\n", root->info.age);
			root = rr(root);
		}else{
			printf("%d unbalance RL!\n", root->info.age);
			root = rl(root);
		}
	}
	return root;
}




void printTree2D(vnode *root, int level){
	int i;

	if (root == NULL)	return;

	printTree2D(root->right, level+1);
	
	for(i=0;i<level;i++)
		printf("\t");
	printf("%d\n", root->info.age);
	
	printTree2D(root->left, level+1);
	
}

vnode *insertNodeR (vnode *root, vnode *n) //  recursive
{
	if (root==NULL)
	   return n;
	if (n->info.age < root->info.age) // go to left
	   root->left=insertNodeR(root->left,n);
	else
	   root->right=insertNodeR(root->right,n);

	root = checkBalance(root);

	return root;
}


	
int main()
{
	vtree tree;
	vinfo inf;
	initTree(&tree);

	int nVals = 20;
	srand(time(NULL)); //seed

	while(nVals-- > 0){
		inf.age=rand()%200;
		tree.root=insertNodeR(tree.root,newNode(inf));

		printf("\n\n ----- add (%d) \n", inf.age);
		printTree2D(tree.root, 0);

		getchar(); //pause
	}
	
	

	// inf.age=28;
	// tree.root=insertNodeR(tree.root,newNode(inf));
	
	// inf.age=26;
	// tree.root=insertNodeR(tree.root,newNode(inf));
	
	// inf.age=15;
	// insertNodeR(tree.root,newNode(inf));
	
	// // inf.age=43;
	// // insertNodeR(tree.root,newNode(inf));
	
	// inf.age=5;
	// insertNodeR(tree.root,newNode(inf));

	// inf.age=51;
	// insertNodeR(tree.root,newNode(inf));

	// inf.age=52;
	// insertNodeR(tree.root,newNode(inf));
	
	
	freeTree(tree.root);
	return 0;
}