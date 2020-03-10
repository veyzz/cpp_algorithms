#include <iostream>

unsigned int gcd(unsigned int x, unsigned int y) {
    if (x == 0) {
        return y;
    }
    if (y == 0) {
        return x;
    }
    if (x > y) {
        return gcd(x % y, y);
    } else {
        return gcd(y % x, x);
    }
}

int main() {
    unsigned int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}