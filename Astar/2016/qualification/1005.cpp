#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int UP = 100000;
const int DOWN = -100000;
struct range {
	int left, right;
	range(){}
	range(int l, int r) {
		left = l;
		right = r;
	}
	bool check(range r) {
		if(r.left > right || r.right < left)
			return false;
		return true;
	}
	void print() {
		cout<<left<<" , "<< right;
	}
};
map<string, range>::iterator it;
struct exp {
	bool empty;
	map<string, range> cons;
	map<string, bool> vis;
	void push(string var, string op, int num) {
		if(!vis[var]) {
			range r;
			if(op == "<") {
				r = range(DOWN, num-1);
			} else if(op == ">") {
				r = range(num+1, UP);
			} else if(op == "<=") {
				r = range(DOWN, num);
			} else if(op == ">=") {
				r = range(num, UP);
			}
			cons[var] = r;
			vis[var] = true;		
		} else {
			range r = cons[var];
			if(op == "<") {
				if(DOWN >= num) {
					empty = true;
					cons.clear();
				} else {
					cons[var] = range(r.left, min(r.right, num-1));
				}
			} else if(op == ">") {
				if(UP <= num) {
					empty = true;
					cons.clear();
				} else {
					cons[var] = range(max(r.left, num+1), r.right);
				}
			} else if(op == "<=") {
				if(DOWN > num) {
					empty = true;
					cons.clear();
				} else {
					cons[var] = range(r.left, min(r.right, num));
				}
			} else if(op == ">=") {
				if(UP < num) {
					empty = true;
					cons.clear();
				} else {
					cons[var] = range(max(r.left, num), r.right);
				}
			} else {
				if(num < r.right && num > r.left) {
					cons[var] = range(num, num);
				} else {
					empty = true;
					cons.clear();
				}
			}
		}
	}

	void print() {
		cout<<empty<<endl;
		for(it= cons.begin(); it!=cons.end(); it++) {
			cout<<it->first<<" "<<"(";
			it->second.print();
			cout<<")"<<endl;
		}
	}
}f[1005];
int main() {
	int n;
	string buffer;
	scanf("%d", &n);
		getchar();
		for(int k = 0 ; k < n; k ++) {
			getline(cin, buffer);
			int i = 0;
			while(i < buffer.length()) {
				int j = i;
				string var, op = "";
				int num;
				while(buffer[i]>='a' && buffer[i]<='z') {
					i++;
				}
				if(j != i) {
					var = buffer.substr(j, i-j);
					// cout<<var<<endl;	
				}		

				while(buffer[i] == ' ' || buffer[i] == ',') i++;

				if(buffer[i] == '<') {
					op = "";
					op += buffer[i];
					i++;
					if(buffer[i] == '=') {
						op += buffer[i];
						i++;
					}
				}

				if(buffer[i] == '>') {
					op = "";
					op += buffer[i];
					i++;
					if(buffer[i] == '=') {
						op += buffer[i];
						i++;
					}
				}

				if(buffer[i] == '=') {
					// cout<<buffer[i]<<buffer[i+1]<<endl;
					op = "";
					op += buffer[i];
					op += buffer[i+1];
					i+=2;
				}

				while(buffer[i] == ' ' || buffer[i] == ',') i++;

				j = i;
				while(buffer[i]>='0' && buffer[i]<='9') {
					i++;
				}	
				if(j != i) {
					string str = buffer.substr(j, i-j);
					stringstream ss;
					ss<<str;
					ss>>num;
					// cout<<num<<endl;	
				}		

				// cout<<var<<" "<<op<<" "<<num<<endl;
				while(buffer[i] == ' ' || buffer[i] == ',') i++;
				f[k].push(var, op, num);	
			}
		// cout<<var<<" "<<op<<" "<<num<<endl;
			// f[k].print();						
			// cout<<endl;
		}

		for(int k = 0; k < n; k++) {
			if(f[k].empty || k == 0) {
				puts("unique");
				continue;
			}
			vector<int> ans;
			for(int j = 0 ; j < k; j++) {
				if(f[j].empty)
					continue;
				for(it = f[k].cons.begin(); it!=f[k].cons.end(); it++) {
					if(!it->second.check(f[j].cons[it->first])) {
						break;
					}
				}
				ans.push_back(j+1);
			}
			if(ans.size()==0){
				puts("unique");
			} else {
				for(int j = 0; j < ans.size(); j++) {
					printf("%d%c", ans[j], j==ans.size()-1?'\n':' ');
				}
			}
		}
}