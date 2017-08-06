#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 205;
int col[maxn][maxn];
int row[maxn][maxn];
char d[5];
int n, m;
int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		row[1][1] = 0;

		int l, f, r, t;
		int x = 1, y = 1;
		char cur_d = 'd';
		for(int i = 0; i < 2 * n * m - 1; i++) {
			scanf("%d%d%d", &l, &f, &r);
			scanf("%s", d);
			if(cur_d == 'd') {
				row[x + 1][y] = f;
				col[x][y] = r;
				col[x][y + 1] = l;
			} else if(cur_d == 'u') {
				row[x][y] = f;
				col[x][y] = l;
				col[x][y + 1] = r;
			} else if(cur_d == 'l') {
				col[x][y] = f;
				row[x][y] = r;
				row[x + 1][y] = l;
			} else if(cur_d == 'r') {
				col[x][y + 1] = f;
				row[x][y] = l;
				row[x + 1][y] = r;
			}
			if(d[0] == 'l') y--;
			if(d[0] == 'r') y++;
			if(d[0] == 'u') x--;
			if(d[0] == 'd') x++;
			cur_d = d[0];
		}
		for(int i = 0; i < 2 * n + 1; i++) {
			for(int j = 0; j < 2 * m + 1; j++) {
				if(i % 2 == 0) {
					if(j % 2 == 0) {
						printf("%c", '+');
					} else {
						printf("%c", row[i/2+1][j/2+1] ? '-' : ' ');
					}
				} else {
					if(j % 2 == 0) {
						printf("%c", col[i/2+1][j/2+1] ? '|' : ' ');
					} else {
						printf("%c", ' ');
					}
				}
			}
			printf("\n");
		}
	}
}