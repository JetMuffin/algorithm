#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200010;
int acnt[2 * maxn + 10];
int bcnt[2 * maxn + 10];
struct point {
	int index;
	int atag;
	int btag;
	point(int i, int a, int b):index(i), atag(a), btag(b) {}
	bool operator<(const point& right) const {
		return index < right.index; 
	}
};
int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	vector<point> line;

	for(int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		line.push_back(point(x, 1, 0));
		line.push_back(point(y, -1, 0));
	}

	for(int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		line.push_back(point(x, 0, 1));
		line.push_back(point(y, 0, -1));			
	}

	sort(line.begin(), line.end());
	int a = 0, b = 0;
	for(int i = 0; i < line.size(); i++) {
		a += line[i].atag;
		acnt[i] = a;
		b += line[i].btag;
		bcnt[i] = b;
	}

	int ans = 0;
	for(int i = 0; i < line.size() - 1; i++) {
		if(acnt[i] > 0 && bcnt[i] == 0) {
			ans += line[i+1].index - line[i].index;
		}
	}

	printf("%d\n", ans);
	
}