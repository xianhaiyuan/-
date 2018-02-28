/*
题目描述：
	输入两个正整数，求其最大公约数 
输入：
	测试数据有多组，每组输入两个正整数 
输出：
	对于每组输入，请输出其最大公约数 
样例输入：
	49 14
样例输出：
	7
*/
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

int gcd(int a,int b){
	if(b==0) return a;  //若b为零则最大公约数为a 
	else return gcd(b,a%b);
}
/*
非递归
int gcd(int a,int b){
	while(b!=0){
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}
*/
int main()  
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		printf("%d\n",gcd(a,b));
	}
    return 0 ;    
} 