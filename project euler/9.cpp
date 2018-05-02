#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    for(int i = 1; i <= 1000; i++) {
        for(int j = i; j + i <= 1000; j++) {
            int k = 1000 - i - j;
            if (k * k == (i * i + j * j)) {
                cout << i << " " << j << " " << k << " " << i*j*k << endl;
            }
        }
    }
}
