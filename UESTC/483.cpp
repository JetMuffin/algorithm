#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[5005];
bool judge1(int n){
  for(int i = 1; i <= n; i++){
	if(a[i*2]!=-1){
	  if(a[i*2] > a[i])
		return false;
	}
	if(a[i*2+1]!=-1){
	  if(a[i*2+1] < a[i])
		return false;
	}
  }
  return true;
}
bool judge3(int n){
  for(int i = 1; i <= n; i++){
	if(a[i*2]!=-1){
	  if(a[i*2] < a[i])
		return false;
	}
	if(a[i*2+1]!=-1){
	  if(a[i*2+1] > a[i])
		return false;
	}
  }
  return true;	
}
bool judge2(int n){
  for(int i = 1; i <= n; i++){
	if(a[i*2]!=-1){
	  if(a[i*2] < a[i])
		return false;
	}
	if(a[i*2+1]!=-1){
	  if(a[i*2+1] < a[i])
		return false;
	}
  }
  return true;
}
bool judge4(int n){
  for(int i = 1; i <= n; i++){
	if(a[i*2]!=-1){
	  if(a[i*2] > a[i])
		return false;
	}
	if(a[i*2+1]!=-1){
	  if(a[i*2+1] > a[i])
		return false;
	}
  }
  return true;	
}
int main(){
  int T;
  int cas = 0;
  scanf("%d",&T);
  while(T--){
	int n;
	cas++;
	scanf("%d",&n);
	memset(a,-1,sizeof(a));
	for(int i = 1 ; i <= n; i++){
	  scanf("%d",a+i);
	}
	bool bst = (judge1(n) || judge3(n));
	bool heap = (judge2(n) || judge4(n));
	printf("Case #%d: ", cas);
	if(bst){
	  if(heap){
		puts("Both");
	  }else{
		puts("BST");
	  }
	}else{
	  if(heap){
		puts("Heap");
	  }else{
		puts("Neither");
	  }
	}
  }
}

