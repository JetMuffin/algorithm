/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10831297
*/

#include<iostream>
#include <algorithm>
using namespace std;
__int64 a[1001];
int main()
{
    int n,i,T;
    cin>>T;
    for(int j=0;j<T;j++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        for(i=0;i<n;i++)
            if(i!=n-1)
                cout<<a[i]<<" ";
            else cout<<a[i]<<endl;    
    }

    return 0;
} 