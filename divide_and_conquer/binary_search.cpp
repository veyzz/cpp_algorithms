#include <iostream>
#include <vector>

int get_pos(std::vector<int> const & arr, int element) {
    int begin = 0;
    int end = arr.size() - 1;
    int mid;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (arr[mid] == element) {
            return mid + 1;
        }
        if (arr[mid] > element) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int k, element;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> element;
        std::cout << get_pos(arr, element) << " ";
    }
    std::cout << std::endl;
    return 0;
}
