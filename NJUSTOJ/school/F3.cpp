#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define LL long long
using namespace std;
const int maxn = 100010;
int a[maxn];
int main() {
		int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
				for(int i = 0 ; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = 0 ; i < n; i++) {
			for(int j = i+1; j< n; j++) {
				if(a[j] > a[i])
			}
		}
	}
}