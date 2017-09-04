#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
char s[1000];
int romanToInt(string s) {
	int index=0,num=0,temp=0;
	while(index<s.size()){
		char c=s[index++];
		switch(c){
			case 'I':num+=1;temp=1;break;
			case 'V':num+=temp==1?3:5;break;
			case 'X':num+=temp==1?8:10;temp=10;break;
			case 'L':num+=temp==10?30:50;break;
			case 'C':num+=temp==10?80:100;temp=100;break;
			case 'D':num+=temp==100?300:500;break;
			case 'M':num+=temp==100?800:1000;break;
		}
	}
	return num;
}
struct people {
	string name;
	int num;
	string rom;
	people() {}
	void output() {
		cout<<name<<" "<<rom<<endl;
	}
}p[100010];
bool cmp(people a, people b) {
	if(a.name == b.name) {
		return a.num < b.num;
	}
	return a.name < b.name;
}
int main() {
	int n;
	string name, rom;
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			cin>>name>>rom;
			p[i] = people();
			p[i].name = name;
			p[i].num = romanToInt(rom);
			p[i].rom = rom;
		}
		sort(p, p+n, cmp);
		for(int i = 0; i < n; i++) {
			p[i].output();
		}
	}
}
