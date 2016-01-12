/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10815388
*/

#include<iostream>
using namespace std;
int main()
{
 int n,a,sum=0;
 while(cin>>n)
{
 for(int i=0;i<n;i++)
{ cin>>a;
sum+=a;

}
cout<<sum<<endl;
sum=0;
}
return 0;
}