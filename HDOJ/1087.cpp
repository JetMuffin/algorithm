/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10838098
*/

#include<iostream>
using namespace std;
int value[1000],dp[1000];
int main()
{
    int n,i,j,k,val,max;
    while(cin>>n&&n!=0)
    {
        memset(dp,0,sizeof(dp));
        
        for(i=0;i<n;i++)
            cin>>value[i];
        dp[0]=value[0];
        max=dp[0];
        for(i=0;i<n;i++)    
        {    
            dp[i]=value[i];
            for(j=0;j<i;j++){  
                if(value[i]>value[j]){  
                    if(dp[i]<dp[j]+value[i])  
                        dp[i]=dp[j]+value[i];  
                }  
            } 
             if(dp[i]>max)  
                max=dp[i]; 
        }
        cout<<max<<endl;
    }
} 