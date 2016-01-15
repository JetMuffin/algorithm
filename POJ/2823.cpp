#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
#define maxn 1000020
using namespace std;

struct node{
  int v,i;
  node(){}
  node(int a,int b){
	v = a;
	i = b;
  }
}queue[maxn];
int a[maxn], ans[maxn];
int n, k;

int Scan() { 
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return flag ? -res : res;
}

void Out(int a) {
    if(a < 0) { putchar('-'); a = -a; }
    if(a >= 10) Out(a / 10);
    putchar(a % 10 + '0');
}
void max(){
  int start = 1;
  int end = 0;
  for(int i = 0; i < n; i++){
	node t = node(a[i], i);
	while(start <= end && queue[end].v <= a[i]) end--;
	queue[++end] = t;
  	
	while(start <= end && queue[start].i < i-k+1) start++;
	ans[i] = queue[start].v;
  }
}

void min(){
  int start = 1;
  int end = 0;
  for(int i = 0; i < n; i++){
	node t = node(a[i], i);
	while(start <= end && queue[end].v >= a[i]) end--;
	queue[++end] = t;

	while(start <= end && queue[start].i < i-k+1) start++;
	ans[i] = queue[start].v;
  }
}

int main(){
  while(~scanf("%d%d",&n,&k)){
	for(int i = 0; i < n; i++){
	  scanf("%d",a+i);
	  // a[i] = Scan();
	}
	min();
	for(int i = k-1; i < n; i++){
		// printf(i == n-1 ? "%d\n":"%d ",ans[i]);
		Out(ans[i]);
		if(i == n-1)
			putchar('\n');
		else
			putchar(' ');
	}
	max();
	for(int i = k-1; i < n; i++){
		// printf(i == n-1 ? "%d\n":"%d ",ans[i]);
		Out(ans[i]);
		if(i == n-1)
			putchar('\n');
		else
			putchar(' ');
	}	
  } 
}
