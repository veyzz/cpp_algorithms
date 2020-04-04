#include <iostream>
#include <vector>
#include <algorithm>

int max_weight(int W, std::vector<int> gold_bars) {
    int n = gold_bars.size();
    std::vector<std::vector<int> > D(W + 1, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int w = 1; w <= W; ++w) {
            D[w][i] = D[w][i - 1];
            if (gold_bars[i] <= w) {
                D[w][i] = std::max(D[w][i], D[w - gold_bars[i]][i - 1] + gold_bars[i]);
            }
        }
    }
    return D[W][n - 1];
}

int main() {
    int W, n;
    std::cin >> W >> n;
    std::vector<int> gold_bars(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> gold_bars[i];
    }
    std::cout << max_weight(W, gold_bars) << std::endl;
    return 0;
}