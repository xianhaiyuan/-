/*
题目描述：
    给定一个数n，要求判断其是否为素数（0，1，负数都是非素数）
输入：
    测试数据有多组，每组输入一个数n
样例输入：
    13
样例输出：
    yes
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
bool judge(int x){
    if(x<1) return false;
    int bound = (int)sqrt(x)+1;
    for(int i=2;i<bound;i++)  //只需到x开方加一即可 
        if(x%i==0) return false;
    return true;
}
int main(){
    int x;
    while(scanf("%d",&x)!=EOF)
        puts(judge(x)?"yes":"no");
    system("pause");
    return 0;
}