/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14750970
*/

#include <iostream>
#include <cstdio>
using namespace std;
bool is_prime(int x)  
{  
    for(int i=2;i*i<=x;i++)  
        if(x%i==0)return false;  
    return x!=1;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        int n;  
        scanf("%d",&n);  
        if(n==4) printf("2\n");  
        else if(is_prime(n)) printf("%d\n",n-1);  
        else printf("0\n");  
    }  
    return 0;  
}  