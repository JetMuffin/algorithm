#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[5050];
char buf[20000];
int main() {
	while(~scanf("%s", s)) {
		memset(buf, 0, sizeof(buf));
		int len = strlen(s);
		for(int i = 0; i < len; i++) {
			buf[i*2] = s[i];
			buf[i*2+1] = '#';
		}
		len = strlen(buf)-1;
		long long ans = 0;
		for(int i = 0; i < len; i++) {
			for(int j=i,k=i; j>=0&&k<len; j--,k++) {
				if(buf[k] == buf[j]) {
					if(buf[k] == '#')
						continue;
					// cout<<buf[j]<<" "<<buf[k]<<" "<<j<<" "<<k<<endl;
					ans++;
				} else {
					break;
				}
			}
		}
		printf("%lld\n", ans);
	}
}