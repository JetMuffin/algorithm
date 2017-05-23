/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11626650
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <ctime>
using namespace std;

#define LL long long
#define ULL unsigned long long
//#define mod 1000000007
#define eps 1e-8
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define RREP(i,a,b) for(int i = b; i > a ; --i)
#define RE freopen("in.txt","r",stdin)
#define WE freopen("out.txt","w",stdout) 

LL a[101];
set <LL> st;
set <LL>::iterator it;
int main()
{
    int n;
    while(cin>>n)
    {
        st.clear();
        LL sum=0;
        REP(i,0,n) 
            cin>>a[i];
        REP(i,0,n)
            REP(j,0,n)
            {
                if(i!=j)
                    st.insert(a[i]+a[j]);
            }
        for(it=st.begin();it!=st.end();it++)
            sum+=*it;
        cout<<sum<<endl;
    }
    
} 