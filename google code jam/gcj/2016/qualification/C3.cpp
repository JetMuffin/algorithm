#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 16
#define LL long long 
LL a[16], mi;
char s[16];
LL inter(int n) {
	LL ans = 0;
	LL base = 1;
	for(int i = 0; i < N; i++) {
		ans += base*(s[i]-'0');
		base *= n;
		cout<<ans<<endl;
	}
	return ans;
}

int main() {
	cin>>s;
	LL x = inter(10);
	cout<<x<<endl;
	cout<<s<<endl;
}