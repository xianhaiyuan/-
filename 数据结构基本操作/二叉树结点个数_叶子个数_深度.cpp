#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

struct Node{
	int data;
	Node *lchild;
	Node *rchild;
};

int loc;

Node *create(){
	Node *t = (Node *)malloc(sizeof(Node));
	t->lchild = t->rchild = NULL;
	return t;
}
Node *insert(Node *t,int x){
	if(t==NULL){
		t = create();
		t->data = x;
	}
	else if(x < t->data){
		t->lchild = insert(t->lchild, x); 
	}
	else if(x > t->data){
		t->rchild = insert(t->rchild, x);
	}
	return t;
}

//结点个数 
int num_of_nodes(Node *t){
	if(t == NULL) return 0;
	return 1+num_of_nodes(t->lchild)+num_of_nodes(t->rchild);
}
//叶子个数 
int num_of_leaf(Node *t){
	if(t==NULL) return 0;
	if(t->lchild == NULL && t->rchild == NULL) return 1;
	return num_of_leaf(t->lchild) + num_of_leaf(t->rchild);
}

int depth(Node *t){
	if(t == NULL)
		return 0;
	int dl = depth(t->lchild);
	int dr = depth(t->rchild);
	return (dl > dr ? dl : dr) + 1;
}
void preOrder(Node *t){
	printf("%d ",t->data);
	if(t->lchild != NULL) preOrder(t->lchild);
	if(t->rchild != NULL) preOrder(t->rchild);
}
void inOrder(Node *t){
	if(t->lchild != NULL) inOrder(t->lchild);
	printf("%d ",t->data);
	if(t->rchild != NULL) inOrder(t->rchild);
}
void postOrder(Node *t){
	if(t->lchild != NULL) postOrder(t->lchild);
	if(t->rchild != NULL) postOrder(t->rchild);
	printf("%d ",t->data);
}

int main(void)  
{  
  	int n;
	while(scanf("%d",&n)!=EOF) {
		int a[n];
		Node *t = NULL;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			t = insert(t,a[i]);
		}
		printf("inOrder: ")
		inOrder(t);
		printf("\n");
		printf("depth: %d \n",depth(t));
		printf("num of nodes: %d \n",num_of_nodes(t));
		printf("num of leaf: %d \n",num_of_leaf(t));
	}
    return 0 ;    
} 
