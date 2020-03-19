#include <iostream>
#include <vector>
#include <algorithm>

int find_LMS_last(std::vector<int> const & arr) {
    int n = arr.size();
    std::vector<int> temp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] % arr[j] == 0 && temp[j] + 1 >= temp[i]) {
                temp[i] = temp[j] + 1;
            }
        }
    }
    int ans = temp[0];
    for (int i = 0; i < n; ++i) {
        if (ans < temp[i]) {
            ans = temp[i];
        }
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << find_LMS_last(arr) << std::endl;
    return 0;
}