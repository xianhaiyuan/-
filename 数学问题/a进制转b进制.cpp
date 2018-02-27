/*
题目描述：
	求任意两个不同进制非负整数的转换（二进制 ~ 十六进制），所给整数在long所能表达的范围之内。不同进制的表示符号为（0,1,...,9,a,b,...,f)或(0,1,...,9,A,...,F)
输入：
	输入只有一行，包含三个整数a,n,b。a表示其后的n是a进制整数，b表示欲将a进制整数n转换成b进制整数。a,b是十进制整数，2 =< a,b <=16。
输出：
	可能有多组测试数据，对于魅族数据，输出包含一行，该行有一个整数位转换后的b进制数。输出时字母符号全部用大写表达，即（0,1,...,9,A,...,F)
样例输入
15 Aab3 7
样例输出：
210306
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main() {
	int a,b;
	char str[40];
	while(scanf("%d%s%d",&a,str,&b)!=EOF) {
		// int tmp=0,lenth=strlen(str),c=1;
		// tmp为我们将要计算的a进制对应的十进制数，lenth为字符串长度方便我们从低高位遍历每个数位上的数，
		// c为各个数位的权重初始化为1，表示最低数位权1，之后每位权重都是前一位权重的a倍
		for(int i=lenth-1; i>=0; i--) {
			// 从低位到高位遍历每个数位上的数字
			int x;
			if(str[i]>'0' && str[i]<'9')  //字符在0到9之间
				x = str[i]-'0';
			else if(str[i]>='a'&&str[i]<='z')  //字符为小写字母时
				x = str[i] - 'a' + 10;
			else x=str[i] - 'A' +10;  //字符为大写字母时
			tmp+=c*x;  //累加该位数字与该数位权重的积
			c*=a;  //计算下一位数位的权重
		}
		char ans[40];  //用ans保存转换到b进制的各个数位数字
		int size=0;
		do {
			int x = tmp%b;  //计算该位数字
			ans[size++]=(x<10)?(x+'0'):(x-10+'A');  //将数字转化为字符
			tmp/=b;
		} while(tmp);
		for(int i=size-1; i>=0; i--)
			printf("%c",ans[i]);
		printf("\n");
	}
	system("pasue");
	return 0;
}