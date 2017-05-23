/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10924567
*/

#include<iostream>
using namespace std;
int f[1000001];
int main()
{
    char s[6];
    int m,n,i,j,count;
    for(i=1;i<=1000000;i++)
        {
            sprintf(s,"%d",i);
            for(j=0;j<strlen(s);j++)
                if(s[j]=='4') {f[i]=1;break;}
                else 
                {
                    if(j<strlen(s)-1&&s[j]=='6'&s[j+1]=='2')
                    {
                        f[i]=1;
                        break;
                    }    
                }
        }
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        count=m-n+1;
        for(i=n;i<=m;i++)
            if(f[i]==1) count--;        
        cout<<count<<endl;
    }
    return 0;
} 