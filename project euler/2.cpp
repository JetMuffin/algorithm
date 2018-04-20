#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a = 1, b = 1, c;
    int sum = 0;
    while(b <= 4000000) {
        c = a + b;
        a = b;
        b = c;
        if (b % 2 == 0) {sum += b;cout<<b<<endl;}
    }
    printf("%d\n", sum);
}
