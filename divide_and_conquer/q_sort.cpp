#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int> & arr, int l, int r) {
    int x = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] <= x) {
            ++j;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[l], arr[j]);
    return j;
}

void q_sort(std::vector<int> & arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = partition(arr, l ,r);
    q_sort(arr, l, m - 1);
    q_sort(arr, m + 1, r);
}

int main() {
    std::vector<int> arr = {5, 4, 3, 1, 2};
    std::cout << "Input: ";
    for (auto const & it : arr) {
        std::cout << it << " ";
    }
    q_sort(arr, 0, arr.size() - 1);
    std::cout << std::endl << "Output: ";
    for (auto const & it : arr) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}