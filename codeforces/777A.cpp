#include <iostream>
using namespace std;
int f[3][6] = {1, 1, 2, 3, 3, 2, 2, 3, 3, 2, 1, 1, 3, 2, 1, 1, 2, 3};
int g[3][6] = {1, 2, 3, 3, 2, 1, 2, 1, 1, 2, 3, 3, 3, 3, 2, 1, 1, 2};
int main() {
	int a, b;
	while(cin>>a>>b) {
		if(a & 1)
			cout<<g[b][a%6]-1<<endl;
		else
			cout<<f[b][a%6]-1<<endl;
	}
}