/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10830036
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    int i,j,count=0,len;
    string str;
    while(cin>>str)
    {
        if(str=="<br>") 
        {
            cout<<endl;
            count=0;
        }
        else if(str=="<hr>")
        {    
            if(count)    
                cout<<endl;
            for(j=0;j<80;j++)
                cout<<"-";
            cout<<endl;
            count=0; 
        }
        else 
        {
            if (str.length() + count + 1 <= 80)
            {
                if (!count)
                    cout<<str;
                else
                    cout<<" "<<str;
                count += str.length() + 1;
            }
            else
            {
                cout<<endl<<str;
                count=str.length();
            }
        }
        
    }
    cout<<endl;        
    return 0;
}