/*
题目描述：
    假设你已经知道了所有你喜欢看的电视节目的转播时间表，目标是能看尽量多的完整节目
输入：
    输入数据包含多个测试实例，每个测试实例的第一行只有一个整数n（n<=100），表示你喜欢看的节目慕的总数，然后是n行数据，每行包括两个数据Ti_s，Ti_e（1<=i<=n），
    分别表示第i个节目的开始和结束时间，为了简化问题，每个时间都用一个正整数表示。n=0表示输入结束，不做处理。
输出：
    对于每个测试实例，输出能完整看到的电视节目的个数，每个测试实例的输出占一行
样例输入：
    12
    1 3
    3 4
    0 7
    3 8
    15 19
    15 20
    10 15
    8 18
    6 12
    5 10
    4 14
    2 9
    0
样例输出：
    5 
*/ 

#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct program{
    //电视节目结构体 
    int startTime;  //节目开始时间 
    int endTime;  //节目结束时间 
    bool operator < (const program &b) const {
        //重载小于号，按结束时间升序排序 
        return endTime < b.endTime;
    }
}buf[100];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&buf[i].startTime,&buf[i].endTime);
        }   
        sort(buf,buf+n);  //按照结束时间升序排序 
        int currentTime = 0,ans=0;  //记录当前时间变量初始值为0，答案计数初始值为0 
        for(int i=0;i<n;i++)  //按照结束时间升序遍历所有节目 
        {
            if(currentTime <= buf[i].startTime)  //若当前时间小于等于该节目开始时间，那么收看在剩余节目里结束时间最早的节目 
            {
                currentTime = buf[i].endTime;  //当前时间变为该节目的结束时间 
                ans++;  //计数收看了多少个节目 
            }
        }
        printf("%d\n",ans);
    }    
    system("pause");
    return 0;

}