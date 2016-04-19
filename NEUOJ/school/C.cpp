#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define LL long long
char str[20000];
stack<char> op;
stack<LL> num;

bool digit(char  c) {
	return c >= '0' && c<= '9';
}

int main() {
	int t;
	LL a,b,k;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", str);
		int len = strlen(str);
		for(int i = 0; i < len; i++) {
			if(digit(str[i])) {
				k = str[i] - '0';
				i++;
				while(digit(str[i])) {
					k = k*10 + str[i] - '0';
					i++;
				}
				i--;
				num.push(k);
			} else if(str[i] == '+') {
				if(!op.empty()) {
					while(op.top() == '*' || op.top() == '/') {
						char c = op.top();
						op.pop();
						a = num.top();
						num.pop();
						b = num.top();
						num.pop();
						if(c == '*') {
							num.push(a*b);
						} else if(c == '/'){
							num.push(b/a);
						}	
					}
				}
				op.push(str[i]);		
			} else if(str[i] == '-') {
				if(!op.empty()) {
					while(op.top() == '*' || op.top() == '/') {
						char c = op.top();
						op.pop();
						a = num.top();
						num.pop();
						b = num.top();
						num.pop();
						if(c == '*') {
							num.push(a*b);
						} else if(c == '/'){
							num.push(b/a);
						}	
					}										
				}
	
				op.push(str[i]);		
			} else if(str[i] == '*') {
				op.push(str[i]);
			} else if(str[i] == '/') {
				op.push(str[i]);
			}

		}
	}
	while(!op.empty()) {
		char c = op.top();
		op.pop();
		a = num.top();
		num.pop();
		b = num.top();
		num.pop();
		if(c == '+') {
			num.push(a+b);
		} else if(c == '-') {
			num.push(b-a);
		} else if(c == '*') {
			num.push(a*b);
		} else {
			num.push(b/a);			
		}
	}
	printf("%lld\n", num.top());
}
