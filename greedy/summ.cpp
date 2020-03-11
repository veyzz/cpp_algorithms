#include <iostream>
#include <vector>

int main() {
    int number;
    std::cin >> number;
    int k = 1;
    int n = number;
    std::vector<int> solution;
    while (n - k >= k + 1) {
        n -= k;
        solution.push_back(k++);
    }
    solution.push_back(n);
    std::cout << solution.size() << std::endl;
    for (int i = 0; i < solution.size(); ++i) {
        std::cout << solution[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}