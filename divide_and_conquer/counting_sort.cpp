#include <iostream>
#include <vector>

void c_sort(std::vector<int> & arr) {
    int n = arr.size();
    std::vector<int> count(11);
    std::vector<int> temp(n);
    for (auto const & it : arr) {
        ++count[it];
    }
    for (int i = 1; i < count.size(); ++i) {
        count[i] += count[i-1];
    }
    for (int i = n - 1; i >= 0; --i) {
        temp[--count[arr[i]]] = arr[i];
    }
    std::cout << std::endl;
    arr = std::move(temp);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    c_sort(arr);
    for (auto const & it : arr) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}