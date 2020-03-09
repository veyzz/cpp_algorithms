#include <iostream>

int fib_digit(int n) {
    int a = 0;
    int b = 1;
    int c;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        c = (a + b) % 10;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib_digit(n) << std::endl;
    return 0;
}