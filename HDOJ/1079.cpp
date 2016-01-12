/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10831390
*/

#include<iostream>
using namespace std;
int main()
{
    int n,year,month,day;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>year>>month>>day;
        if(year>2001||(year==2001&&month==12)||(year==2001&&month==11&&day>4))cout<<"NO"<<endl;
        else if((month+day)%2==0||(month==9||month==11)&&day==30) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}