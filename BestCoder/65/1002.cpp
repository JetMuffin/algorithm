#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n&1){
			puts("1");
		}else{
			puts("0");
		}
	}
}