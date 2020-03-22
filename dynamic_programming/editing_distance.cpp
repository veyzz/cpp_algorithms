#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int ed_dist(std::string const & a, std::string const & b) {
    int n = a.size();
    int m = b.size();
    std::vector<std::vector<int> > D(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) {
        D[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        D[0][j] = j;
    }
    bool c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            c = a[i - 1] == b[j - 1] ? 0 : 1;
            D[i][j] = std::min(D[i - 1][j], D[i][j - 1]) + 1;
            D[i][j] = std::min(D[i][j], D[i - 1][j - 1] + c);
        }
    }
    return D[n][m];
}

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << ed_dist(str1, str2) << std::endl;
    return 0;
}