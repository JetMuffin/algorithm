#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[5050],b[5050],c[5050],d[5050];
int dp[5050][5050];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(dp, 0, sizeof(dp));
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		scanf("%s", a);
		scanf("%s", b);
		int lena = strlen(a);
		int lenb = strlen(b);
		for(int i = 0 ; i < lena; i++) {
			c[i+1] = a[i];
		}
		for(int i = 0 ; i < lenb; i++) {
			d[i+1] = b[i];
		}		
		for(int i = 1; i <= lena; i++) {
			for(int j = 1; j <= lenb; j++) {
				dp[i][j] = dp[i-1][j];
				if(dp[i][j-1] > dp[i][j]) dp[i][j] = dp[i][j-1];
				if(c[i] == d[j] && dp[i-1][j-1]+1 > dp[i][j])
					dp[i][j] = dp[i-1][j-1] + 1; 
			}

		}

		printf("%d\n", dp[lena][lenb]);
	}
}