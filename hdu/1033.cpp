/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10784649
*/

#include<iostream>
using namespace std;
char str[200];
int main(){
    int x,y;
    int t=1;
    
    while(cin>>str)
    {
        
        x=300;y=420;t=2;
        cout<<"300 420 moveto"<<endl;
        x+=10;
        cout<<x<<" "<<y<<" lineto"<<endl;
        
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='A'){
                t--;
                if(t==0)t=4;
            }
            else if(str[i]=='V')
            {
                t++;
                if(t==5)t=1;
            }
                        if(t==1)    {y-=10; printf("%d %d lineto\n",x,y);}
            if(t==2)    {x+=10; printf("%d %d lineto\n",x,y);}
            if(t==3)    {y+=10; printf("%d %d lineto\n",x,y);}
            if(t==4)    {x-=10; printf("%d %d lineto\n",x,y);}    
        }
        cout<<"stroke"<<endl<<"showpage"<<endl;
        memset(str,0,sizeof(str));
    }
    return 0;
}
 