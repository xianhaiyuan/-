/*
题目描述：
    We now use the Gregorian style of dating in Russia. The leap years are years with number divisible by 4 but not divisible by 100, or divisible by 400.
    For example, years 2004, 2180 and 2400 are leap. Years 2004, 2181 and 2300 are not leap.
    Your task is to write a program which will compute the day of week corresponding to a given date in the nearest past or in the future using today's agreement
    about dating.
输入：
    There is one single line contains the day number d,month name M and year number y(1000<= y <=3000). The month name is the corresponding English name starting
    from the capital letter.
输出：
    Output a single line with the English name of the day of week corresponding to the date, starting from the capital letter. All other letters must be in lower
    case.
样例输入：
    9 October 2001
    14 October 2001
样例输出：
    Tuesday
    Sunday
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
    31,31, 
    30,30,
    31,31,
    30,30,
    31,31
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
int Abs(int x){
    return x<0?-x:x;
}
char monthName[13][20]={
    "",
    "January",
    "February",
    "March",
    "Apile",
    "May",
    "June",
    "july",
    "August",
    "September",
    "October",
    "November",
    "December"
};
char weekName[7][20] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
}; 
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
    int d,m,y;
    char s[20];
    while(scanf("%d%s%d",&d,s,&y)!=EOF)
    {
        for(m=1;m<=12;m++)
        {
            if(strcmp(s,monthName[m])==0) break;
            //将输入字符串与月名比较得出月数 
        }
        int days = buf[y][m][d]-buf[2018][1][1];
        //计算给定日期与今日日期的天数间隔（注意可能为负） 
        days+=1;
        //（2018.1.1）为星期一，对应数组weekName下标为1，则计算1经过days天后的下标 
        puts(weekName[( ( days %7 )+7 )%7]);
        //加7为了防止负数，若是正数加7后又会多了，再取模一次 
    }
    system("pause");
    return 0;
}