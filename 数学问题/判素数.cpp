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