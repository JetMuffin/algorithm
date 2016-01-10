#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char d[105];
char r[105];
bool check(char a, char b){
	if(a == 'A' && b == 'U')
		return true;
	if(a == 'T' && b == 'A')
		return true;
	if(a == 'C' && b == 'G')
		return true;
	if(a == 'G' && b == 'C')
		return true;
	return false;
}
int main(){ 
	// freopen("in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		scanf("%s",d);
		scanf("%s",r);
		bool flag = true;
		for(int i = 0; i < n; i++){
			if(!check(d[i], r[i])){
				flag = false;
				break;
			}
		}
		if(flag){
			puts("YES");
		}else{
			puts("NO");
		}
	}
}