#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char s[2010];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            getchar();
            s[i] = getchar();
        }
        int a = 0, b = n - 1;
        bool left;
        int cnt = 0;
        while(a <= b) {
            for(int i = 0; a + i <= b; i++) {
                if (s[a+i] < s[b-i]) {
                    left = true;
                    break;
                } else if (s[a + i] > s[b-i]) {
                    left = false;
                    break;
                }
            }
            if (left) putchar(s[a++]);
            else putchar(s[b--]);
            cnt ++;
            if (cnt == 80) {
                putchar('\n');
                cnt = 0;
            }
        }
        putchar('\n');
    }
}
