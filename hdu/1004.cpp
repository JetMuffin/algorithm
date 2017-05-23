/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10829201
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> ans;
int main()
{
    int N,max;
    string str,max_string;
    while(cin>>N&&N!=0)
    {
        for(int i=0;i<N;i++)
        {
            cin>>str;
            ans[str]++;    
        }
        max=0;
        for(map<string,int>::iterator it = ans.begin();it!=ans.end();it++)
        {
            if(it->second>max)
            {
                max=it->second;
                max_string=it->first;
            }
        }
        ans.clear();
        cout<<max_string<<endl;
    }
    return 0;
}