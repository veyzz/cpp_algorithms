#include <iostream>
#include <cstddef>
#include <vector>

int fib_mod(long n, int m) {
    if (n <= 1) {
        return (int)n;
    }

    std::vector<int> fib = {0, 1};

    for (std::size_t i = 2; i <= 6 * m; ++i) {
        fib.push_back((fib[i - 2] + fib[i - 1]) % m);
        if (i == n) {
            return fib.back();
        }
        if (fib[i] == 1 && fib[i - 1] == 0) {
            break;
        }
    }

    std::size_t period = fib.size() - 2;
    return fib[n % period];
}

int main() {
    long n;
    int m;
    std::cin >> n >> m;
    std::cout << fib_mod(n, m) << std::endl;
    return 0;
}