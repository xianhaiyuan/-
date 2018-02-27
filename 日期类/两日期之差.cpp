/*
题目描述：
    有两个日期，求两个日期之前的天数，如果两个日期是连续的我们规定他们之间的天数为两天
输入：
    有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
输出：
    每组数据输出一行，即日期差值
样例输入：
    20110412
    20110422
样例输出：
11
*/ 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define ISYEAP(x) x%100!=0 && x%4==0 || x%400 == 0 ? 1:0

int dayOfMonth[13][2] = {
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    30,30
};
//注意二月配合宏定义作特殊处理，闰年用第二排
struct Date{
    int Day;
    int Month;
    int Year;
    void nextDay()
    {
        Day++;
        if(Day>dayOfMonth[Month][ISYEAP(Year)])  //计算下一天的日期
        {
            Day=1;
            Month++;
            if(Month > 12)
            {
                Month = 1;
                Year++;
            } 
         }
    }
};
int buf[5001][13][32];  //保存预处理的天数
//求绝对值
int Abs(int x){
    return x<0?-x:x;
}
int main(){
    Date tmp;
    int cnt=0;  //天数计数器
    tmp.Day=1;
    tmp.Month=1;
    tmp.Year=0;
    //初始化日期类对象为0年1月1日
    while(tmp.Year!=5001)  //日期不超过5000年
    {
        buf[tmp.Year][tmp.Month][tmp.Day]=cnt;
        //将该日与0年1月1日之前相差的天数保存起来
        tmp.nextDay();
        //计数器累加，每经过一天计数器即+1，代表与原点日期的间隔又增加一天
        cnt++;
    }
    int d1,m1,y1;
    int d2,m2,y2;
    while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
    {
        scanf("%4d%2d%2d",&y2,&m2,&d2);
        //读入要计算的两个日期
        printf("%d\n",Abs(buf[y2][m2][d2]-buf[y1][m1][d1])+1);
    }
    system("pause");
    return 0;
}