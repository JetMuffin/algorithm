#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define LL long long
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, a;
        scanf("%d", &n);
        int flag = 0, p = 0;
        for(int i = 0 ; i < n; i++) {
            scanf("%d", &a);
            if(a > 1) {
                flag = 1;
            }
            p ^= a;

        }
        int win = 0;
        if(!flag) {
            if(n % 2 ) {
                win = 0;
            } else {
                win = 1;
            }            
        } else {
            if(p == 0) {
                win = 0;
            } else {
                win = 1;
            }
        }

        if (!win) {
            puts("Meidikeji_Shijiediyi!");
        } else {
            puts("Yamato_Saikou!");
        }
    }
}  
