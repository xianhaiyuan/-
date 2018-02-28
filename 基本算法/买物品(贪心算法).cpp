/*
题目描述： 
    FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
    The warehouse has N rooms. The i-th room contains J[i] pounds of javaBeans and requires F[i] pounds of cat food. FatMouse does not have to trade for
    all the JavaBeans in the room, instead, he may get J[i]*a% pounds of JavaBeans if he pays F[i]*a% pounds of cat food. Here a is a real number. Now he
    is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
输入：
    The input consists of multiple test cases. Each test case begins with aline containing two non-negative integers M and N. Then N lines follow, each
    contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.
输出：
    For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.
样例输入：
    5 3
    7 2
    4 3
    5 2
    20 3
    25 18
    24 15
    15 10
    -1 -1
样例输出：
    13.333
    31.500
    
题目大意：有m元钱，n种物品：每种物品有j磅，总价值f元，可以使用0到f的任意价格购买相应磅的物品，例如使用0.3f元，可以购买0.3j磅物品。
要求输出用m元钱最多能买到多少磅物品。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct goods{
    //表示每个物品的结构体 
    double weight;  //该物品总重 
    double yuan;  //该物品总价值 
    double s;  //该物品性价比 
    bool operator < (const goods &b) const{
        //重载小于运算符，按照性价比降序排序 
         return s > b.s;
    }
}buf[1000];
int main(){
    double m;
    int n;
    while(scanf("%lf%d",&m,&n)!=EOF)
    {
        if(m==-1&&n==-1) break;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&buf[i].weight,&buf[i].yuan);
            buf[i].s = buf[i].weight/buf[i].yuan;  //计算性价比 
        }
        sort(buf,buf+n);  //按照物品性价比降序排序 
        int idx=0;  //当前物品下标 
        double ans=0;  //累加所能得到的总重量 
        while(m>0&&idx<n)  //循环条件为，既有物品剩余（idx<n），还有钱剩余（m>0）时继续循环 
        {
            if(m>buf[idx].yuan)  //若能买下全部该物品 
            {
                ans += buf[idx].weight;
                m = m - buf[idx].yuan;
            }
            else
            {
                ans += m * buf[idx].weight / buf[idx].yuan;  //只能买下部分该物品 
                m=0;
            }
            idx++;
        }

        printf("%.3lf\n",ans); 
    } 

    system("pause");
    return 0;
} 