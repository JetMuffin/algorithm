/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10924713
*/

#include<iostream>
using namespace std;
int main()
{
    //freopen("data.txt","r",stdin);
    int y[30][30];
    int i,j,n;
    
    for(i=0;i<30;i++)
    {
        y[i][0]=1;
        y[i][i]=1;
    }    
    for(i=1;i<30;i++)
        for(j=1;j<i;j++)
            y[i][j]=y[i-1][j]+y[i-1][j-1];
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
                if(j==0) cout<<y[i][j];
                else cout<<" "<<y[i][j];
            cout<<endl;
        }
        cout<<endl;
    }        
}