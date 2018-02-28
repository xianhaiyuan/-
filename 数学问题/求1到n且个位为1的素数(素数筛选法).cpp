/*
题目描述：
    输入一个整数n（2<=n<=10000)，要求输出所有从1到这个整数之前（不包括1和这个整数）个位为1的素数，如果没有则输出-1。 
输入：
    输入有多组数据。每组一行，输入n。
输出：
    输出所有从1到这个整数之间（不包括1和这个整数）个位为1的素数（素数之间用空格隔开，最后一个素数后面没有空格），如果没有则输出-1。 
*/ 

#include<stdio.h>
#include<stdlib.h>
using namespace std;
int prime[10000];  //保存筛得的素数 
bool mark[10001];  //若mark[x]为true，则表示该数x已被标记成非素数 
int primeSize;  //保存素数的个数 
void init(){
    for(int i=1;i<=10000;i++)
        mark[i] = false;
    primeSize = 0;  //得到素数的个数为0 
    for(int i=2;i<=10000;i++)  //从2开始到10000进行筛选 
    {
        if(mark[i]==true) continue;
        prime[primeSize++] = i;
        for(int j=i*i;j<=10000;j+=i)  //将i的所有倍数均标记为非素数 
            mark[j] = true;
        //这里没有从2*i开始，而是从i*i开始，避免重复，如从3*2开始，6是2的倍数，其实在i等于2的时候，6已经被标记过了 
    }
}
int main(){
    init();  //在程序一开始首先取得2到10000中所有素数 
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        bool isOutput = false;  //标记是否没有找到素数 
        for(int i=0;i<primeSize;i++)
        {
            if(prime[i]<n&&prime[i]%10==1)  //找1到n且个位为1的素数 
            {
                if(isOutput == false)
                    {
                        isOutput = true;
                        printf("%d",prime[i]);
                    }
                else printf(" %d",prime[i]);
            }
        }
        if(isOutput == false) printf("-1\n");
        else printf("\n");
    }
    system("pause");
    return 0; 
} 