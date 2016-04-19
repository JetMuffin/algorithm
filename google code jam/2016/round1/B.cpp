#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int N = 55;
const int MAXN = 2*N;
const int MAXNUM = 5050;
int n;
int a[MAXN][MAXN];
int exp[MAXN][MAXN];
int color[MAXNUM];
int tot[5050];
vector<int> ans;
vector<int>x,y;
bool check() {
	int len = x.size();
	for(int i = 0; i < len-1; i++) {
		for(int j = i+1; j < len; j++) {
			if(!exp[x[i]][x[j]] || !exp[x[j]][x[i]]) {
				return false;
			}
		}
	}
	len = y.size();
	for(int i = 0; i < len-1; i++) {
		for(int j = i+1; j < len; j++) {
			if(!exp[y[i]][y[j]] || !exp[y[j]][y[i]]) {
				return false;
			}
		}
	}	
	return true;
}
bool cmp(int i, int j) {
	return a[i][0] > a[j][0];
}
void test (){
		for(int i = 0 ; i < 10; i++) {
		cout<<tot[i]<<" ";
	}
	cout<<endl;
}
bool output() {
	int xlen = x.size();
	int ylen = y.size();
	memset(tot,0,sizeof(tot));
	if (xlen > ylen) {
		for(int i = 0; i < xlen; i++) {
			for(int j = 0; j<n; j++) {
				tot[a[x[i]][j]] ++;
			}
		}
		// test();
		for(int i = 0; i < ylen; i++) {
			for(int j = 0; j<n; j++) {
				tot[a[y[i]][j]] --;
				if(tot[a[y[i]][j]] < 0) return false;
			}
		}		
	} else {
		for(int i = 0; i < ylen; i++) {
			for(int j = 0; j<n; j++) {
				tot[a[y[i]][j]] ++;
			}
		}
		for(int i = 0; i < xlen; i++) {
			for(int j = 0; j<n; j++) {
				tot[a[x[i]][j]] --;
				if(tot[a[x[i]][j]] < 0) return false;
			}
		}		
	}

	return true;
}

int main() {
	int t, cas = 0;
	scanf("%d", &t);

	while(t--) {
		cas ++;
		scanf("%d", &n);
		printf("Case #%d: ", cas);
		for(int i = 0; i < 2*n-1; i++) {
			for(int j = 0 ; j< 2*n -1; j++) {
				if(i != j)
					exp[i][j] = true;
			}
		}

		for(int i = 0 ; i < 2*n-1; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		for(int i = 0; i < 2*n-2; i++) {
			for(int j = i+1; j <2*n-1; j++) {
				int flag = 0;
				for(int k = 0; k < n; k++) {
					if(a[i][k] == a[j][k]) {
			            exp[i][j] = false;
			            exp[j][i] = false;
			            flag = 1; 
					}
				}
			}
		}

		for(int i = 0; i < 1<<(2*n-1); i++){
			memset(color,0,sizeof(color));
			x.clear();
			y.clear();
			for(int j = 0; j < 2*n-1; j++){
				if(i & (1<<j)){
					color[j] = 1;
				}
			}
			for(int j = 0 ; j < 2*n-1; j++){
				if(color[j]){
					x.push_back(j);
				}else{
					y.push_back(j);
				}
			}
			if(check()) {
				// for(int i = 0; i < x.size(); i++) {
				// 	cout<<x[i]<<" ";
				// }
				// cout<<endl;
				// for(int i = 0; i < y.size(); i++) {
				// 	cout<<y[i]<<" ";
				// }
				// cout<<endl;		
				// cout<<"---"<<endl;	
				if(output()) {
					ans.clear();
					for(int i = 0 ; i < MAXNUM; i++) {
						if(tot[i] > 0) {
							ans.push_back(i);
						}
					}
					sort(ans.begin(), ans.end());

					for(int i = 0; i < ans.size(); i++){
						printf("%d%c", ans[i], i==ans.size()-1?'\n':' ');
					}
					break;
				}
			}
		}
	}
}