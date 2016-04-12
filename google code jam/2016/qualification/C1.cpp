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
	for(int i = N-1; i >= 0; i--) {
		ans += base*(s[i]-'0');
		base *= n;
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	for(int i = 0 ; i < n; i++) {
		cin>>s;
		for(int j = 2; j <= 10; j++) {
			cin>>a[j];
		}
		for(int j = 2; j <= 10; j++) {
			LL x = inter(j);
			// cout<<x<<" "<<a[j]<<" "<<x%a[j]<<endl;
			if(x%a[j] != 0) {
				cout<<x<<" "<<a[j]<<endl;
			}
		}
	}
}