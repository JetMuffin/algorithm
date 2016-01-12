/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10831783
*/

#include<iostream>
#include<cstdio>
using namespace std;
const int lmax=40007;
int c1[lmax],c2[lmax];
//G(x)=(1+x+x^2+x^3+...+x^num_1)*(1+x^2+x^4+...+x^(2*num_2))*(1+x^5+x^10+...+x^(5*num_3))
int main()
{
    int num_1,num_2,num_3,t;
    while(cin>>num_1>>num_2>>num_3&&(num_1!=0||num_2!=0||num_3!=0))
    {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<=num_1;i++)
        {
            c1[i]=1;
            c2[i]=0;
        }
        for(int j=0;j<=num_1;j++)
        {
            for(int k=0;k<=num_2*2;k+=2)
                {
                    c2[k+j]+=c1[j];
                }
         }
         for(int j=0;j<=num_1+num_2*2;j++)
         {
               c1[j]=c2[j];
               c2[j]=0;
         }
         for(int j=0;j<=num_1+num_2*2;j++)
        {
            for(int k=0;k<=num_3*5;k+=5)
                {
                    c2[k+j]+=c1[j];
                }
         }
         for(t=0;t<=num_1+num_2*2+num_3*5;t++)
         {
              if(c2[t]==0)    {cout<<t<<endl;break;}
         }
         if(t==(num_1+num_2*2+num_3*5+1)) cout<<t<<endl;
    }
    return 0;
}