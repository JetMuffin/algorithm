/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856534
*/

#include<iostream>
#include<string>
using namespace std;
char str[1000];
int main()
{
    int n,count;
    cin>>n;
    while(n--)
    {
        count=0;
        cin>>str;
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]>='0'&&str[i]<='9')
            count++;
        }
        cout<<count<<endl;
    }
}