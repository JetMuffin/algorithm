#include <iostream>
using namespace std;
int vis[10];
void digit(int n) {
	while(n) {
		vis[n%10] = 1;
		n /= 10;
	}
}
bool check() {
	for(int i = 0 ; i < 10; i++) {
		if(!vis[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	// while(cin>>n) {
		for(int n = 0; n <= 1000000; n++) {
		memset(vis, 0, sizeof(vis));
			for(int i = 1; i < 10000; i++) {
				digit(n*i);
				if(check()) {
					if(i > 45){
					cout<<n<<" "<<i<<endl;

					}
					break;
				}
			}			
		}
	// }
}