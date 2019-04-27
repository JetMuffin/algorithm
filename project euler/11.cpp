#include <iostream>
#include <cstring>
using namespace std;
int a[21][21];
int ans = 0;
void input() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}
void check(int x, int y) {
    if (y + 3 < 20) {
        ans = max(ans, a[x][y] * a[x][y+1] * a[x][y+2] * a[x][y+3]);
    }
    if (x + 3 < 20) {
        ans = max(ans, a[x][y] * a[x+1][y] * a[x+2][y] * a[x+3][y]);
    }
    if (x + 3 < 20 && y + 3 < 20) {
        ans = max(ans, a[x][y] * a[x+1][y+1] * a[x+2][y+2] * a[x+3][y+3]);
    }
    if (x + 3 < 20 && y - 3 >= 0) {
        ans = max(ans, a[x][y] * a[x+1][y-1] * a[x+2][y-2] * a[x+3][y-3]);
    }
}
int main() {
    input();
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            check(i, j);
        }
    }
    cout << ans << endl;
}
