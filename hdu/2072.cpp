/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11624097
*/

#pragma warning(disable:4786)
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    set <string> st;
    char str[1000];

    int i,len;
    while(gets(str))
    {
        if(strcmp(str,"#")==0)
            break;
        else 
        {    
            string s="";

            len=strlen(str);
            str[len]=' ';
            for (i=0;i<=len;i++)
            {
                if (str[i]!=' ')
                    s+=str[i];
                else
                {
                    if (s.length())
                        st.insert(s);
                    s = "";
                }
            }
            cout <<st.size()<< endl;
            memset(str,'\0',sizeof(str));
            st.clear();
        }
    }

    return 0;
}