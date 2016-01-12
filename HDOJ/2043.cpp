/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10917799
*/

#include<iostream>
using namespace std;
char s[51];
int main()
{
    int a,b,c,d,t;
//freopen("data.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>s;
        a=b=c=d=0;    
        if(strlen(s)<8||strlen(s)>16)
            {cout<<"NO"<<endl;}
        else
        {
            for(int i=0;i<=strlen(s);i++)
            {
                char x=s[i];
                if(x>='0'&&x<='9')
                    c=1;
                else if(x>='A'&&x<='Z')
                    a=1;
                else if(x>='a'&&x<='z')
                    b=1;
                else if(x=='~'||x=='!'||x=='@'||x=='#'||x=='$'||x=='%'||x=='^')
                    d=1;
            }
            if(a+b+c+d>=3)
                cout<<"YES"<<endl;    
            else 
                cout<<"NO"<<endl;    
        }
    }    
}