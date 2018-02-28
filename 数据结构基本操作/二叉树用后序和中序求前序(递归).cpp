/*
��Ŀ������
	�ж��������Ƿ�Ϊͬһ�������������� 
���룺
	��ʼһ����n��1<=n<=20����ʾ��n����Ҫ�жϣ�n=0��ʱ���������������ȥһ����һ�����У����г���С��10��������0~9�������֣�û���ظ����֣�
	����������п��Թ����һ�Ŷ�����������
	����ȥ��n����n�����У�ÿ�����и�ʽ����һ������һ�������ж������������Ƿ������ͬһ�Ŷ����� 
�����
	���������ͬ�����YES���������NO 
�������룺
	2
	567432
	543267
	576342
���������
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

char str1[25],str2[25];  //��������������ı����������ÿһ������ǰ������õ����ַ�������������õ����ַ������ӣ��õ���������ַ��� 

int size1,size2;  //�������ַ������еı����õ��ַ����� 
char *str;  //���浱ǰ�ַ��� 
int *size;   //����ĵ�ǰ���ַ����е��ַ�����
 
//������� 
void postOrder(Node *T){
	if(T->lchild != NULL) postOrder(T->lchild);
	if(T->rchild != NULL) postOrder(T->rchild);
	str[(*size)++]=T->c+'0';  //������е��ַ��������ڱ�����ַ����� 
}

//������� 
void inOrder(Node *T){
	if(T->lchild != NULL) inOrder(T->lchild);
	str[(*size)++]=T->c+'0';  //������е��ַ��������ڱ�����ַ����� 
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
			T = insert(T,tmp[i]-'0');  //���ַ������ֲ������������ 
		}
		size1 = 0;  //���ڱ����һ���ַ����е��ַ�����ʼ��Ϊ0 
		str = str1;
		size = &size1;
		//��str��sizeָ��Ͳ��ô����� 
		postOrder(T);
		inOrder(T);
		str1[size1]=0;  //���ַ��������ӿ��ַ��������size1��postOrder��inOrder������ı��ˣ�����size1Ϊ12, 
		
		while(n--!=0){
			scanf("%s",tmp);
			Node *T2 = NULL;
			for(int i=0;tmp[i]!=0;i++){
				T2 = insert(T2,tmp[i]-'0');
			}
		size2 = 0;  //���ڱ���ڶ����ַ����е��ַ�����ʼ��Ϊ0 
		str = str2;
		size = &size2;
		//��str��sizeָ��Ͳ��ô����� 
		postOrder(T2);
		inOrder(T2);
		str2[size2] = 0;  //���ַ��������ӿ��ַ�
		puts(strcmp(str1,str2)==0 ? "YES":"NO");
		}
	}
    return 0 ;    
} 
