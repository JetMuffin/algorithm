/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11172171
*/

#include<iostream>
#include<algorithm>
using namespace std;
struct point{
    int E;
    int K;
    double s;
};
struct point p[100001]; 
int cmp(point p1,point p2)
{
    return p1.s<p2.s;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,N;
    int min;
    __int64 sum=0;
    __int64 totE=0;
    cin>>N;
    for(i=1;i<=N;i++)
        cin>>p[i].E;
    for(i=1;i<=N;i++)
        cin>>p[i].K;
    for(i=1;i<=N;i++)
        p[i].s = p[i].E/(double)p[i].K;
    sort(p+1,p+N+1,cmp);
    for(i=1;i<=N;i++)
        {
            totE+=p[i].E;
            sum+= totE*p[i].K;
        }
        

    cout<<sum<<endl;
}