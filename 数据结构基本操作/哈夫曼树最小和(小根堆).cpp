/*
题目描述：
    哈夫曼树，第一行输入一个数n，表示叶结点个数。需要用这些叶结点生成哈夫曼树，根据哈夫曼树的概念，这些结点有权值，即weight，题目需要输出所有结点的值
    与权值的乘积之和
输入：
    输入有多组数据，每组第一行输入一个数n，接着输入n个叶结点（叶结点权值不超过100,2<=n<=1000）
输出：
    输出权值
样例输入：
    5
    1 2 2 5 9
样例输出：
    37 
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > Q;  //建立一个小顶堆 
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(Q.empty()==false) Q.pop();  //清空堆中的元素 
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            Q.push(x);
        }
        int ans = 0;  //保存答案 
        while(Q.size()>1)  //当堆中的元素大于1个 
        {
            int a = Q.top();
            Q.pop();
            int b=Q.top();
            Q.pop();
            ans+=a+b;
            //取出堆中两个最小元素，它们为同一个结点的左右儿子，且双亲结点的权值为它们的和 
            Q.push(a+b);  //将该双亲结点的权值放回堆中 
        }
        printf("%d\n",ans);
    }
   system("pause");
   return 0;
}