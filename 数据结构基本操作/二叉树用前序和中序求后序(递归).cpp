/*
题目描述：
	给定一颗二叉树的前序遍历和中序遍历，求其后序遍历
输入：
	两个字符串，长度n均小于等于26。 
	第一行为前序遍历，第二行为中序遍历。二叉树中的结点名称以大写字母表示：A,B,C,...最多26个结点
输出：
	输入样例可能有多组，对于每组测试样例，输出一行，为后序遍历的字符串
样例输入：
	ABC
	BAC
	FDXEAG
	XDEFAG
样例输出：
	BCA
	XEDGAF 
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
}Tree[50];
int loc;
Node *create(){
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}
char str1[30],str2[30];  //保存前序和中序遍历结果字符串

//后序遍历 
void postOrder(Node *T){
	if(T->lchild != NULL) postOrder(T->lchild);
	if(T->rchild != NULL) postOrder(T->rchild);
	printf("%c",T->c);
}

Node *build(int s1,int e1,int s2,int e2){
	//由字符串的前序遍历和中序遍历还原树，并返回其根结点，其中前序遍历结果为由str1[s1]到str2[e1]，中序遍历结果为str2[s2]到str[e2]
	//s1和e1分别表示此树（或这颗子树）前序开始和结束结点的下标，s2和e2分别表示此树（或这颗子树）中序开始和结束结点的下标
	Node *ret = create();
	ret->c = str1[s1];  //前序遍历的第一个字符（每次都找到这颗树或这颗子树的根结点） 
	int rootIdx;  //str[s1]结点在中序遍历中的下标，这就是此树（或这颗子树）在中序遍历下的根结点下标 
	for(int i=s2;i<=e2;i++){
		if(str2[i]==str1[s1]){
			rootIdx = i;
			break;
		}
	}
	if(rootIdx != s2){ 
		//若左子树不空（中序的第一个和前序的第一个相同说明此树无左子树）
		ret->lchild = build(s1+1, s1+(rootIdx-s2), s2, rootIdx-1);
		//s1+1为左子树前序遍历第一个结点，s1+(rootIdx-s2)为左子树前序遍历最后一个结点 ，rootIdx-s2得出左子树个数
		//s2左子树中序遍历第一个结点，不用变，rootIdx-1为左子树中序遍历最后一个结点 
	}
	if(rootIdx != e2){
		//若右子树不空（中序的最后一个和前序的第一个相同说明此树无右子树）
		ret->rchild = build(s1+(rootIdx-s2)+1, e1, rootIdx+1, e2); 
		//用左子树前序最后一个加1得右子树前序第一个，e1为右子树前序最后一个不用变 
		//用中序的根结点加1得右子树中序第一个，e2为右子树中序最后一个不用变 
	}
	return ret; 
}
int main()  
{
	while(scanf("%s",str1)!=EOF){
		scanf("%s",str2);
		int loc=0;
		int e1 = strlen(str1)-1;
		int e2 = strlen(str2)-1;
		Node *T = build(0,e1,0,e2);  //还原整颗树，其根结点指针保存在T中 
		postOrder(T);
		printf("\n"); 
	}
    return 0 ;    
} 