/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11118133
*/

#include<iostream>
using namespace std;
int main()
{
    int a,b,p,i,j,m;
    char s[32]={0};
    while(cin>>a>>b)
    {
    i=0;
    j=0;
    if(a<0)
    {
        s[j++]='-';
        a = -a;
    }
    for(p=1;p<=a;p*=b) i++;
    i--;
    p=1;
    for(int k=0;k<i;k++)
        p*=b;
    for(int k=0;k<=i;k++)
    {
        m=a/p;
        if(m>9) s[j++]='A'+m-10;
        else s[j++]='0'+m;
        a=a%p;
        p/=b;
    }    
    for(int k=0;k<j;k++)
        cout<<s[k];    
    cout<<endl;        
    }

}