/* 
题目描述： 
	查找和排序

题目：
	输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列，相同成绩都按先录入排列在前的规则处理。

例示：
   jack      70
   peter     96
   Tom       70
   smith     67

从高到低  成绩            
   peter     96    
   jack      70    
   Tom       70    
   smith     67    

从低到高 
   smith     67  
   Tom       70    
   jack      70    
   peter     96      

输入描述:
	输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开

输出描述:
	按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<algorithm>
using namespace std;
struct t{
	char name[100];
	int g;
}student[500];
bool cmp(struct t t1,struct t t2){
	return t1.g<t2.g;
}
bool cmp1(struct t t1,struct t t2){
	return t1.g>t2.g;
}
int main(){
	int n,type;
	while(scanf("%d %d",&n,&type)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%s %d",student[i].name,&student[i].g);
		if(type == 1) stable_sort(student,student+n,cmp);  //使用stable_sort稳定排序，相同的值先输入的在前 
		else stable_sort(student,student+n,cmp1);
		for(int i=0;i<n;i++)
		{
			printf("%s %d\n",student[i].name,student[i].g);
		}
	}
	return 0;	
}

//测试地址：https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=40&tqId=21333&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking 