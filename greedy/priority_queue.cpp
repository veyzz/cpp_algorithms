#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Heap {
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

private:
    void sift_up(int i) {
        if (i == 0) {
            return;
        }
        if (data_[i] > data_[(i - 1) / 2]) {
            std::swap(data_[i], data_[(i - 1) / 2]);
            sift_up((i - 1) / 2);
        }
    }

    void sift_down(int i) {
        int max_i;
        if (2 * i + 1 >= data_.size()) {
            return;
        }
        if (2 * i + 2 < data_.size()) {
            max_i = data_[2 * i + 1] > data_[2 * i + 2] ? \
                    2 * i + 1 : 2 * i + 2;
        } else {
            max_i = 2 * i + 1;
        }
        if (data_[i] < data_[max_i]) {
            std::swap(data_[i], data_[max_i]);
            sift_down(max_i);
        }
    }

    std::vector<int> data_;
};

int main() {
    int n, value;
    std::string cmd;
    Heap queue;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> cmd;
        if (cmd == "Insert") {
            std::cin >> value;
            queue.insert(value);
        } else if (cmd == "ExtractMax") {
            std::cout << queue.extract_max() << std::endl;
        }
    }
    return 0;
}