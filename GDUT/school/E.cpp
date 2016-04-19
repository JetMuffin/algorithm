#include <iostream>
using namespace std;
#define maxn 1000010
#define LL long long 
LL a[maxn];
LL q[maxn];
LL c[maxn];

LL leftSum(int left, int right) {
  int head = 1, tail = 0;
  LL res = 0;
  for(int i = right; i >= left; i--) {
    while(head <= tail && q[tail] < a[i]) {
        --tail;
    }
    q[++tail] = a[i];
    c[tail] = i;
  }
//   output(head, tail);
  for(int i = head; i < tail ; i++) {
    // cout<<c[i]+1<<"-"<<c[i+1]<<" ";
    for(int j = c[i]-1; j >= c[i+1]; j--) {
      res += (a[c[i+1]]-a[j]);
    }
    // cout<<res<<endl;
  }
  return res;
}

LL rightSum(int left, int right) {
  int head = 1, tail = 0;
  long long res = 0;
  for(int i = left; i <= right; i++) {
    while(head <= tail && q[tail] < a[i]) {
        --tail;
    }
    q[++tail] = a[i];
    c[tail] = i;
  }
//   output(head, tail);
  for(int i = head; i < tail ; i++) {
    // cout<<c[i]+1<<"-"<<c[i+1]<<" ";
    for(int j = c[i]+1; j <= c[i+1]; j++) {
      res += (a[c[i+1]]-a[j]);
    }
    // cout<<res<<endl;
  }
  return res;
}

int main() {
    int t, n, maxi;
    LL maxx;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
      for(int i = 1; i <= n; i++) {
       scanf("%lld", &a[i]);
      }
      maxx = a[0];
      maxi = 0;
      for(int i = 1 ; i <= n; i ++) {
        if(a[i] > maxx) {
          maxx = a[i];
          maxi = i;
        }
      }
      printf("%lld\n", leftSum(1, maxi)+rightSum(maxi, n));
    }
}
