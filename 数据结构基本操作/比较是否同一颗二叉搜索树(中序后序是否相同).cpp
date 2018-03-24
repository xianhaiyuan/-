/*
题目描述：
	判断两序列是否为同一二叉搜索树序列 
输入：
	开始一个数n（1<=n<=20）表示有n个需要判断，n=0的时候输入结束。接下去一行是一个序列，序列长度小于10，包含（0~9）的数字，没有重复数字，
	根据这个序列可以构造出一颗二叉搜索树。
	接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断这两个序列是否能组成同一颗二叉树 
输出：
	如果序列相同则输出YES，否则输出NO 
样例输入：
	2
	567432
	543267
	576342
样例输出：
	YES
	NO
*/
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

struct Node{
	Node *lchild;
	Node *rchild;
	char c;
}Tree[110];
int loc;
Node *create(){
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

Node *insert(Node *T,int x){
	if(T==NULL){
		T = create();
		T->c = x; 
	}
	else if(x<T->c)
		T->lchild = insert(T->lchild,x);
	else if(x>T->c)
		T->rchild = insert(T->rchild,x);
	return T;
}

char str1[25],str2[25];  //保存二叉排序树的遍历结果，将每一颗树的前序遍历得到的字符串与中序遍历得到的字符串连接，得到遍历结果字符串 

int size1,size2;  //保存在字符数组中的遍历得到字符个数 
char *str;  //保存当前字符串 
int *size;   //保存的当前的字符串中的字符个数
 
//后序遍历 
void postOrder(Node *T){
	if(T->lchild != NULL) postOrder(T->lchild);
	if(T->rchild != NULL) postOrder(T->rchild);
	str[(*size)++]=T->c+'0';  //将结点中的字符放入正在保存的字符串中 
}

//中序遍历 
void inOrder(Node *T){
	if(T->lchild != NULL) inOrder(T->lchild);
	str[(*size)++]=T->c+'0';  //将结点中的字符放入正在保存的字符串中 
	if(T->rchild != NULL) inOrder(T->rchild);
}

int main()  
{
	int n;
	char tmp[12];
	while(scanf("%d",&n)!=EOF && n!=0){
		loc = 0;
		Node *T = NULL;
		scanf("%s",tmp);
		for(int i=0;tmp[i]!=0;i++){
			T = insert(T,tmp[i]-'0');  //将字符串数字插入二叉排序树 
		}
		size1 = 0;  //用于保存第一个字符串中的字符，初始化为0 
		str = str1;
		size = &size1;
		//用str，size指针就不用传参了 
		postOrder(T);
		inOrder(T);
		str1[size1]=0;  //在字符串最后添加空字符，这里的size1在postOrder和inOrder函数里改变了，这里size1为12, 
		
		while(n--!=0){
			scanf("%s",tmp);
			Node *T2 = NULL;
			for(int i=0;tmp[i]!=0;i++){
				T2 = insert(T2,tmp[i]-'0');
			}
		size2 = 0;  //用于保存第二个字符串中的字符，初始化为0 
		str = str2;
		size = &size2;
		//用str，size指针就不用传参了 
		postOrder(T2);
		inOrder(T2);
		str2[size2] = 0;  //在字符串最后添加空字符
		puts(strcmp(str1,str2)==0 ? "YES":"NO");
		}
	}
    return 0 ;    
} 