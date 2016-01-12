/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14708162
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int digit(int a,int b,int k){
    while(k>0){
        if(a%10 != b%10)
            return 0;
        a/= 10;
        b/= 10;
        k --;
    }
    return 1;
}
int main(){
    int a,b,k;
    while(~scanf("%d%d%d",&a,&b,&k)){
        if(a==0&&b==0)
            break;
        if(digit(a,b,k)){
            puts("-1");
        }else{
            cout<<a+b<<endl;
        }
    }
}