/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=15481126
*/

#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cmath>  
#include<cstring>  
#include<vector>  
#include<queue>  
#include<set>  
#include<map>  
#include<algorithm>  
#include<sstream>  
#define clr(k,v) memset(k,v,sizeof(k))  
#define eps 1e-9  
#define pi acos(-1)  
#define INF 0x7fffffff  
#define inf -INF  
#define MM 12900  
#define N 50  
using namespace std;  
typedef long long ll;  
const int _max = 5e3 + 10;  
  
char g[20][20];  
int di[4]={-1,1,0,0};  
int dj[4]={0,0,1,-1};  
int cnt,tot;  
int v[20][20];//给连通块编号  
  
void dfs(int x,int y){  
  v[x][y]=tot;  
  for(int i = 0; i < 4; ++ i){  
    int _x = x + di[i];  
    int _y = y + dj[i];  
    if(_x<0||_x>=9||_y<0||_y>=9||v[_x][_y]==tot) continue;  
    if(g[_x][_y]=='x') continue;  
    if(g[_x][_y]=='.') {cnt++;v[_x][_y]=tot;}//编号：不同连通块可以多次访问，统一连通块只可访问一次  
    else dfs(_x,_y);  
  }  
}  
  
int judge(){//连通块  
  tot = 0;int tar = 0;  
  for(int i = 0; i < 9; ++ i)  
    for(int j = 0; j < 9; ++ j){  
       if(g[i][j]=='o'&&!v[i][j]) {  
          tot++;//从1开始给连通块编号  
          cnt = 0;//连通块周围'.'的个数  
          dfs(i,j);  
          if(cnt==1) return 1;  
       }  
    }  
  return 0;  
}  
  
int main(){  
#ifndef ONLINE_JUDGE  
  freopen("input.txt","r",stdin);  
#endif // ONLINE_JUDGE  
  int T;cin>>T;int kase = 1;  
  char s[10];  
  getchar();  
  while(T--){  
    gets(s);  
    for(int i = 0; i < 9; ++ i) scanf("%s",g[i]);  
    clr(v,0);  
    printf("Case #%d: ",kase++);  
    puts(judge()?"Can kill in one move!!!":"Can not kill in one move!!!");  
  }  
  return 0;  
}