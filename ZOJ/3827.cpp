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

#define Exp 2.718281828459
int main()
{
	//RE;
	int T;
	cin>>T;
	while(T--)
	{
		string op;
		double b;
		double sum=0;
		int n;
		cin>>n;
		cin>>op;
		if(op == "bit")
			b = 2;
		if(op == "dit")
			b = 10;
		if(op == "nat")
			b = Exp;
		for(int i=0;i<n;i++)
		{
			int t;	
			cin>>t;
			if(t==0)
				sum+=0;
			else{
				double p = t/100.0;
				sum += p* (log(p) / log(b));				
			}

		} 
		sum = -sum;
		printf("%.12f\n",sum);
	}
} 