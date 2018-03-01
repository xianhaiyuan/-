/*
题目描述：
	求正整数N（N>1）的质因数的个数，相同的质因数需要重复计算。如120=2*2*2*3*5，共有5个质因数。 （注意：1不是N的质因数；若N为质数，N是N的质因数） 
输入：
	可能有多组测试数据，每组测试数据的输入时一个正整数N（1<N<10^9）。 
输出：
	对于每组数据，输出N的质因数的个数 
样例输入：
	120
样例输出：
	5
*/
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

bool mark[100001];
int prime[100001];
int primeSize;
//用素数筛选法选出2到100000内的所有素数 
void init(){
	primeSize = 0;
	for(int i=2;i<=100000;i++){
		if(mark[i]==true) continue;
		prime[primeSize++] = i;
		if(i>=1000) continue;  //i大于1000就超过范围了 
		for(int j=i*i;j<=100000;j+=i){
			mark[j] = true;
		}
	}
}
int main()  
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF){
		int ansPrime[30];  //按顺序保存分解出的素数 
		int ansSize = 0;  //分解出素因数的个数 
		int ansE[30];  //保存分解出的素因数对应的幂指数 
		for(int i=0;i<primeSize;i++){
			//依次从小到大测试每一个素数 
			if(n%prime[i]==0){
				//若该素数能整除被分解数 
				ansPrime[ansSize] = prime[i];  //该素数就为其质因数 
				ansE[ansSize] = 0;  //初始化幂指数为0 
				while(n%prime[i]==0){
					//从被测试数中将该素数分解出来，并统计其幂指数 
					ansE[ansSize]++;
					n/=prime[i];
				}
				ansSize++;  	//素因数个数增加 
				if(n==1) break;  //若已被分解成1，则分解提前终止 
			}
		}
		if(n!=1){
			//若测试完2到100000内所有素因数，n仍未被分解至1，则剩余的因数一定是n，一个大于100000的素因数 
			ansPrime[ansSize] = n;  //记录该大素因数 
			ansE[ansSize++] = 1;  //其幂指数只能为1 
		}
		int ans = 0;
		for(int i=0;i<ansSize;i++){
			ans+=ansE[i];  //统计各个素因数的幂指数 
		}
		printf("%d\n",ans);
	}
    return 0 ;    
} 