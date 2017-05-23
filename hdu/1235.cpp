/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14709003
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    map <int,int>m;
    int n;
    while(~scanf("%d",&n)){
        if(n == 0)break;
        m.clear();
        for(int i = 0 ; i < n; i++){
            int x;
            scanf("%d",&x);
            m[x]++;            
        }
        int k;
        scanf("%d",&k);
        printf("%d\n",m[k]);
    }
}