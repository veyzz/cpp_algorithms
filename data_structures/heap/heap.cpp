#include <iostream>
#include <vector>

std::vector<std::vector<int> > swap_array;

struct Heap {
    explicit Heap() {}

    explicit Heap(std::vector<int> arr) {
        data_ = std::move(arr);
        for (int i = data_.size() / 2; i >= 0; --i) {
            sift_down(i);
        }
    }

    void insert(int value) {
        data_.push_back(value);
        sift_up(data_.size() - 1);
    }

    int extract_max() {
        int temp = data_[0];
        std::swap(data_[0], data_[data_.size() - 1]);
        data_.pop_back();
        if (data_.size()) {
            sift_down(0);
        }
        return temp;
    }

    std::vector<int> array() const {
        return data_;
    }

private:
    void sift_up(int i) {
        if (i == 0) {
            return;
        }
        if (data_[i] < data_[(i - 1) / 2]) {
            std::swap(data_[i], data_[(i - 1) / 2]);
            sift_up((i - 1) / 2);
        }
    }

    void sift_down(int i) {
        int min_i;
        if (2 * i + 1 >= data_.size()) {
            return;
        }
        if (2 * i + 2 < data_.size()) {
            min_i = data_[2 * i + 1] < data_[2 * i + 2] ? \
                    2 * i + 1 : 2 * i + 2;
        } else {
            min_i = 2 * i + 1;
        }
        if (data_[i] > data_[min_i]) {
            std::swap(data_[i], data_[min_i]);
            swap_array.push_back({i, min_i});
            sift_down(min_i);
        }
    }

    std::vector<int> data_;
};

int main() {
    int size;
    std::cin >> size;
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    std::vector<int> heap = Heap(arr).array();
    std::cout << swap_array.size() << std::endl;
    for (auto const & el : swap_array) {
        std::cout << el[0] << " " << el[1] << std::endl;
    }
    return 0;
}