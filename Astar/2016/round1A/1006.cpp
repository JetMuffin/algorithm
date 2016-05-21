#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std ;
#define M 200010
#define N 100010
#define inf 0x3f3f3f3f

int vv[M], nxt[M], h[N], e;
int in[N];
struct cmp{
    bool operator ()(int &a,int &b){
        return a<b;
    }
};

void add( int v, int u )
{
    vv[e] = v, nxt[e] = h[u], h[u] = e++;
    ++in[v];
}
int ans[M];
int f[M];
int n;
void gao()
{
    // priority_queue<int> q;
    priority_queue<int,vector<int>,cmp>q;
    for( int i = 1; i <= n; ++i ) if( !in[i] )
        q.push( i );
    int u, v, c = 0;
    while( !q.empty() ){
        u = q.top(), q.pop();
        ans[c++] = u;
        for( int i = h[u]; i + 1; i = nxt[i] ){
            v = vv[i];
            --in[v];
            if( !in[v] ) q.push( v );
        }
    }
}
int main()
{
    int T, m, u, v;
    scanf( "%d", &T );
    while( T-- ){
        scanf( "%d%d", &n, &m );
        e = 0, memset( h, -1, sizeof(h) );
        memset( in, 0, sizeof(in) );
        while( m-- ){
            scanf( "%d%d", &u, &v );
            add( v, u );
        }
        gao();
        // for( int i = 0; i < n; ++i )
        //     printf( "%d%c", ans[i], i == n-1? '\n': ' ' );
        long long res = 0;
        f[0] = ans[0];
        for(int i = 1; i < n; i++) {
            f[i] = min(f[i-1], ans[i]);
        }
        // for(int i = 0; i < n; i++) {
        //     cout<<f[i]<<" ";
        // }
        // cout<<endl;
        for(int i = n-1; i >= 0; i--) {
            res += f[i];
        }
        printf("%lld\n", res);
    }
}