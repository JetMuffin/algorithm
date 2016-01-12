/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11105626
*/

/*
**    p[i]=min(p[2*id-i],max-i)
*/ 

#include<iostream>
using namespace std;
int p[220002];
char s[220002],str[220002];
int len;
int pk()
{
    int i,id;
    int mx=0;
    int max = -1;
    for(i=1;i<len-1;i++)
    {
        if(mx>i)
            p[i]=min(p[2*id-i],mx-i);
        else    
            p[i]=1;
        for(;s[i+p[i]]==s[i-p[i]];p[i]++);
        if(p[i]+i>mx)
        {
            mx=p[i]+i;
            id=i;
            
        }
    //    cout<<p[i]<<" ";
        if(max<p[i]) max=p[i];
    }
    //cout<<endl;
    return max;    
}
int min(int a,int b)
{
    if(a>b) return b;
    else return a;
}
int main()
{
    //freopen("data.txt","r",stdin); 
    int T,_=0;
    int i,j;
    while(cin>>str)
    {        
        s[0]='$';s[1]='#';
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            s[2*i+2]=str[i];
            s[2*i+3]='#';
        }
        len=len*2+2;
        
        cout<<pk()-1<<endl;
    }

    return 0;
}