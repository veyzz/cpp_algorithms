#include <iostream>
#include <vector>

long int inv = 0;

std::vector<int> merge(std::vector<int> const & arr1, std::vector<int> const & arr2) {
    std::vector<int> temp(arr1.size() + arr2.size());
    auto arr1_iter = arr1.begin();
    auto arr2_iter = arr2.begin();
    auto temp_iter = temp.begin();
    while (arr1_iter != arr1.end() && arr2_iter != arr2.end()) {
        if (*arr1_iter <= *arr2_iter) {
            *(temp_iter++) = *(arr1_iter++);
        } else {
            *(temp_iter++) = *(arr2_iter++);
            inv += arr1.end() - arr1_iter;
        }
    }
    auto iter = arr1_iter;
    auto end = arr1.end();
    if (arr1_iter == arr1.end()) {
        iter = arr2_iter;
        end = arr2.end();
    }
    for (auto i = iter; i != end; ++i) {
        *(temp_iter++) = *i;
    }
    return temp;
}

std::vector<int> merge_sort(std::vector<int> & arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        return merge(merge_sort(arr, l , m), merge_sort(arr, m + 1 , r));
    }
    return {arr[l]};
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    arr = merge_sort(arr, 0, n - 1);
    std::cout << inv << std::endl;
    return 0;
}