/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11871515
*/

#include<iostream>
#include<math.h>
#define N 1231

using namespace std;
int prime[N]; 
int ans[N*N];
void makeprime()
{
    int j,n=29,i=9,sqrtn;
    prime[0]=2;
    prime[1]=3;
    prime[2]=5;
    prime[3]=7;
    prime[4]=11;
    prime[5]=13;
    prime[6]=17;
    prime[7]=19;
    prime[8]=23;
    while (i<N) 
    {
        j=0; 
        sqrtn=(double)sqrt((double)n);
        while (prime[j]<=sqrtn)
        {
            if (n%prime[j]==0)break; 
            j++;
        }
        if (prime[j]>sqrtn)
        {
            prime[i]=n; 
            i++;
        }
        n+=2;
    }
}

int main()
{
    makeprime();
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
        {
            if(prime[i] == prime[j]) continue;
            else
                ans[prime[i]+prime[j]]++;
        }
    int n;
    while(cin>>n)
    {
        if(!n) break;
        cout<<ans[n]<<endl;
    }            
}