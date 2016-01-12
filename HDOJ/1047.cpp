/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10837274
*/

#include<iostream>
using namespace std;
int sum[102];
char str[102];
int main()
{
    int i,j,k,lena,n;
    cin>>n;
    for(k=0;k<n;k++)
    {
    memset(sum,0,sizeof(sum));
    memset(str,0,sizeof(str));
    while(cin>>str&&strcmp(str,"0"))    
    {
        lena=strlen(str);
            for(i=0;i<=lena;i++)
            {
                sum[i]+=str[lena-i]-'0';;
                if(sum[i]>9)
                {
                    sum[i+1]++;
                    sum[i]-=10;
                }
            }

    }
    for(j=101;j>0;j--)
        if(sum[j]!=0) break;
    if(j==0) cout<<0;
    else
        for(;j>0;j--)
            cout<<sum[j];
         cout<<endl;
         if(k!=n-1) cout<<endl;
    }

    return 0;
} 