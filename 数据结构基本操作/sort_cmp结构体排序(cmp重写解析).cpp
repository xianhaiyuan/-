#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std; 
struct E{
    char name[101];
    int age;
    int score;
}buf[1000];
bool cmp(E a,E b){
//  按成绩排 ，升序 
    if(a.score!=b.score) return a.score<b.score;
//  成绩相同，按名字字母序排，升序，a<b,tmp<0,return true,即字母徐a<b则返回true
    int tmp = strcmp(a.name,b.name);
    if(tmp!=0) return tmp<0;
//  字相同，按年龄排，升序 
    else return a.age<b.age;
}

/*
bool cmp(int a,int b){
    return a>b;
}
等价于,降序 
bool cmp(int a,int b){
    if(a>b) return true;
    else return false;
}

a[5]={2,1,3,5,4}
排后4,5,3,1,2 
bool cmp(int a,int b){
    return true;
}

排后2,1,3,5,4
bool cmp(int a,int b){
    return false;
}

*/

int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s%d%d",buf[i].name,&buf[i].age,&buf[i].score);
        }                                                                                                                   
        sort(buf,buf+n,cmp);
        for(int i=0;i<n;i++)
        {
            printf("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);
        }
    }
    system("pause");
    return 0;
} 