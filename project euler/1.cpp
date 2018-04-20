#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int sum = 0;
    for(int i = 3; i < 1000; i++) {
        int a = sum;
        if (i % 3 == 0) sum += i;
        if (i % 5 == 0) sum += i;
        if (i % 15 == 0) sum -= i;
    }
    printf("%d\n", sum);
}
