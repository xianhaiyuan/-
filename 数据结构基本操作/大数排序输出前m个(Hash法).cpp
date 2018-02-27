/*
题目描述：
	给你n个整数，请按从大到小的顺序输出其中前m大的数
输入：
	每组测试数据有两行，第一行有两个数n，m（ 0<n,m<1000000 ），第二行包含n个各部相同，且都处于区间[-500000,500000]的整数
输出：
	对每组测试数据按从大到小顺序输出前m大的数
样例输入：
	5 3
	3 -35 92 213 -644
样例输出
	213 92 3 
*/
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define OFFSET 500000  //偏移量，用于补偿实际数字与数组下标之间的偏移
int Hash[1000001]; 
 
int main(void)  
{  
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=-500000;i<=500000;i++)
			Hash[i+OFFSET]=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			Hash[x+OFFSET]=1;  //凡是出现过的数字，该数组元素均被设置成1 
		}
		for(int i=500000;i>=-500000;i--){  //输出前m个数 
			if(Hash[i+OFFSET]==1){  //若该数字在输入中出现 
				printf("%d",i);  //输出该数字 
				m--;  //输出一个数字后，m-1，直到m变成0
				if(m!=0) printf(" ");  //最后一个数后没空格 
				else{
					printf("\n");
					break;  //若m个数字输出完毕，跳出循环 
				}
				 
			}
		}
	}
    return 0 ;    
} 