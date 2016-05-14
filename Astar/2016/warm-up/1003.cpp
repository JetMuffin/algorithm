#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <sstream> 
#include <cmath>
#include <set>
using namespace std;
#define LL long long 
struct ip {
	int a,b,c,d;
	void input() {
		scanf("%d.%d.%d.%d", &a, &b, &c, &d);
	}
	void output() {
		printf("%d.%d.%d.%d\n", a, b, c, d);
	}
 	LL toNum(){
    	return (LL)a*(1e9)+(LL)b*(1e6)+(LL)c*(1e3)+(LL)d;
  	}
}a[2000];
map<string, int> mp;
set <LL>s;
ip cal(ip before, ip mask) {
	ip after;
	after.a = before.a & mask.a;
	after.b = before.b & mask.b;
	after.c = before.c & mask.c;
	after.d = before.d & mask.d;
	return after;
}
int main() {
	int t, cas = 0;
	scanf("%d", &t);
	while(t--) {
		cas++;
		printf("Case #%d:\n", cas);
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0 ; i < n ; i++) {
			a[i].input();
		}
		for(int i = 0 ; i < m ; i++) {
			s.clear();
			ip mask;
			mask.input();
			for(int i = 0; i < n; i++) {
				ip net = cal(a[i], mask);
				// net.output();
				// cout<<net.hash()<<endl;
				s.insert(net.toNum());
			}
			printf("%d\n", s.size());
		}
	}
}
