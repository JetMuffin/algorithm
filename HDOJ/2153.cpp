/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10910776
*/

#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n;
    while(cin>>n&&n!=0)
    {
        if(n==1) {printf("%3d\n",1);;continue;}
        for(i=1;i<=n;i++)
            printf("%3d",i);
        cout<<endl;
        for(i=0;i<n-2;i++)
        {
            printf("%3d",(n-1)*4-i);
            for(j=0;j<n-2;j++)
                printf("%3s"," ");
            printf("%3d",n+i+1);
            cout<<endl;
        }
        for(i=0;i<n;i++)
        {
            printf("%3d",3*n-2-i);
        }
        cout<<endl;
    }
    return 0;
}