#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
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

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		int a=0,b=0,s;
		for(int i=0;i<n-1;i++)
		{
			cin>>s;
			a+=s;
		}
		for(int i=0;i<m;i++)
		{
			cin>>s;
			b+=s;
		}
		double t1=(a*n)/(double)(n-1)-a;
		double t2=b*(m+1)/(double)m-b;	
		if((t2-floor(t2))<eps)
			cout<<t2+1;
		else cout<<ceil(t2);
		cout<<" ";
		if((t1-floor(t1))<eps)
			cout<<t1-1;
		else cout<<floor(t1);
		cout<<endl;
	}
} 