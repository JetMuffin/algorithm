/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10928453
*/

#include<iostream>
using namespace std;
int a[101],b[101],c[101],d[9004];
int pos(int a,int b)
{
    char s1[5],s2[5];
    int count=0;
    ltoa(a,s1,10);
    ltoa(b,s2,10);
    for(int i=0;i<4;i++)
        if(s1[i]==s2[i])
            count++;
    return count;
}
int num(int a,int b)
{
    int count=0;
    char s1[5],s2[5];
    sprintf(s1,"%d",a);
    sprintf(s2,"%d",b);
    int len=4;
    for(int i=0;i<len;i++)
        for(int j=0;j<4;j++)
            if(s1[i]==s2[j])
            {
                count++;
                s1[i]=' ';
                s2[j]='!';
            }
    return count;
}
int main()
{
//    freopen("data.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int i,j,k,t,n,count;
    while(cin>>n&&n!=0)
    {
        count=0;
        for(i=0;i<n;i++)
            cin>>a[i]>>b[i]>>c[i];
        for(i=0;i<9000;i++)
            d[i]=i+1000;
        for(i=0;i<n;i++)
    //    i=5;
            for(j=0;j<9000;j++)
                {
                    if(d[j]==0) continue;
                    else{
                        if(!(num(d[j],a[i])==b[i]&&pos(d[j],a[i])==c[i]))
                            d[j]=0;    
                    }
    
                }
        for(i=0;i<9000;i++)
        {
            if(d[i]!=0) {count++;k=i;}
        }
        if(count==1) cout<<d[k]<<endl;
        else cout<<"Not sure"<<endl;             
    }
    return 0;
} 