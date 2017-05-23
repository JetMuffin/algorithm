/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11932516
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
set <int> s;
map <int,bool> m;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n) break;
        int tmp;
        scanf("%d",&tmp);
        int Xor = tmp;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d",&tmp);
            Xor ^= tmp;        
        }
        printf("%d\n",Xor);
    }
}