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
#define RE freopen("in.txt","r",stdin)
#define WE freopen("out.txt","w",stdout) 

string s;
int len;

int input()
{
	s ="";
	string stmp;
	len = 0;
	cin>>stmp;
	for(int i=0;i<stmp.length();i++)
	{
		char c = stmp[i];
		if((c<='Z'&&c>='A')||(c<='z'&&c>='a'))
			{
				s+=c;
				len++;
			}
	}
	return len;
} 

int check1(string s,int len)
{
	for(int lenA = 1;lenA <= (len-2)/3;lenA ++)
	{
		string A = s.substr(0,lenA);
		string Ainv = s.substr(len-lenA,lenA);
//		cout<<"A:"<<lenA<<" "<<A<<" "<<Ainv<<endl;
		if(A == Ainv)
		{
			for(int lenB = 1;lenB <= (len-lenA*2-1)/2;lenB++)
			{
				string B = s.substr(lenA,lenB);
				string Binv = s.substr(len-lenB-lenA,lenB);
//				cout<<"B:"<<B<<" "<<Binv<<endl;
				if(B == Binv) 
				{
					string Asub = s.substr(lenA+lenB,len-lenA*2-lenB*2);
//					cout<<"Asub:"<<Asub<<endl;
					if(Asub == A)
						if(A!=B&&A.length()>0&&B.length()>0) 
						{
//							cout<<"check1"<<endl;
//							cout<<A<<" "<<B<<endl;
							return 1;	
						}
				}
			}
		}
	}
	return 0;
}

int check2(string s,int len)
{
	for(int lenAB = 2;lenAB <= (len-1)/3;lenAB++)
	{
		string AB = s.substr(0,lenAB);
		string ABinv = s.substr(len-lenAB,lenAB);
//		cout<<AB<<" "<<ABinv<<endl;
		if(AB == ABinv)
		{
			for(int lenTmp = 1;lenTmp <= len-lenAB*2-1;lenTmp++)
			{
				string ABTmp = s.substr(lenAB,lenTmp);
//				cout<<ABTmp<<endl;
				if(ABTmp == AB)
				{
					string C = s.substr(lenAB+lenTmp,len-lenAB*3);
//					cout<<C<<endl;
					for(int lenA = 1;lenA <= lenAB-1;lenA++)
					{
						string A = AB.substr(0,lenA);
						string B = AB.substr(lenA,lenAB-lenA);
						if(A!=B&&B!=C&&C!=A&&A.length()>0&&B.length()>0&&C.length()>0) {
//							cout<<"check2"<<endl;
//							cout<<A<<" "<<B<<" "<<C<<endl;
							return 1;	
						}
					}
				}
			}
		}
	}	
	return 0;
}

int main()
{
//	RE;
	int T;
	cin>>T;
	while(T--)
	{
		len = input();
		if(check1(s,len)||check2(s,len)) puts("Yes");
		else puts("No");	
	}
} 