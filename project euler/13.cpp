#include <iostream>
#include <cstdio>
using namespace std;
char s[51];
int a[101][51];
int sum[51];
int main() {
    for(int i = 0; i < 100; i++) {
        scanf("%s", s);
        for(int j = 0; j < 50; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 50; j++) {
            sum[j] = a[i][j] + sum[j];
        }
    }
    int o = 0, t;
    for(int i = 49; i >= 0; i--) {
        t = sum[i] + o;
        if(t > 10) {
            o = t/10;
            sum[i] = t % 10;
        }
    }
    int n = 0;
    if (o > 0) {
        printf("%d", o);
        while(o) {
            n++;
            o /= 10;
        }
    }
    for(int i = 0; i + n < 10; i++) {
        printf("%d", sum[i]);
    }
    printf("\n");
}
