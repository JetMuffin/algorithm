/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856614
*/

#include<iostream>
#include<algorithm>
using namespace std;
int a[101];
int main()
{
    int m,n;
    while(cin>>n>>m)
    {
        if(m==0&&n==0) break;
        for(int i=0;i<n;i++)
            cin>>a[i];
        a[n]=m;
        sort(a,a+n+1);
        for(int j=0;j<=n;j++)
            if(j==0) cout<<a[j];
            else cout<<" "<<a[j];
        cout<<endl;
    }
    return 0;
}