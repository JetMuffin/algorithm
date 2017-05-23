/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856624
*/

#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int a[101];
int cmp(int a,int b)
{
    return(abs(a)>abs(b));
}
int main()
{
    int m,n;
    while(cin>>n&&n!=0)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,cmp);
        for(int j=0;j<n;j++)
            if(j==0) cout<<a[j];
            else cout<<" "<<a[j];
        cout<<endl;
    }
    return 0;
}