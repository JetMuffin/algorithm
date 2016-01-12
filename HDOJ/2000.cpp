/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10803905
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char s[3];
    while(cin>>s)
    {
        sort(s,s+3);
            printf("%c %c %c\n", s[0], s[1], s[2]);
    }    
}