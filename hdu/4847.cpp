/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11187067
*/

#include<iostream>
using namespace std;
 char c[10000];
int main()
{
    //freopen("data.txt","r",stdin);
    int count;
    count=0;    
    while(gets(c))
    {
        
        for(int i=3;i<strlen(c);i++)
        {
            if(tolower(c[i-3])=='d'&&tolower(c[i-2])=='o'&&tolower(c[i-1])=='g'&&tolower(c[i])=='e')
            {
            //    cout<<c[i]<<c[i+1]<<c[i+2]<<c[i+3]<<"@"<<endl;
                count++;    
            }
        }
    }
    cout<<count<<endl;
    return 0;
} 