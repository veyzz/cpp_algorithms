#include <iostream>
#include <algorithm>

struct Node {
    int start;
    int finish;
};

struct Queue {
    explicit Queue(int max_size) {
        size_ = 0;
        front_ = 0;
        back_ = -1;
        max_size_ = max_size;
        data_ = new Node[max_size_];
    }

    ~Queue() {
        delete [] data_;
    }

    int enqueue(int arr, int dur) {
        Node temp;
        temp.start = std::max(arr, last_finish());
        temp.finish = temp.start + dur;
        back_ = (back_ + 1) % max_size_;
        data_[back_] = temp;
        ++size_;
        return temp.start;
    }

    int dequeue() {
        int old_i = front_;
        front_ = (front_ + 1) % max_size_;
        --size_;
        return data_[old_i].finish;
    }

    int last_finish() const {
        return data_[back_].finish;
    }

    int first_finish() const {
        return data_[front_].finish;
    }

    bool full() const {
        if (size_ < max_size_) {
            return false;
        } else {
            return true;
        }
    }

    int size() const {
        return size_;
    }

private:
        int size_;
        int front_;
        int back_;
        int max_size_;
        Node * data_;
};

int main() {
    int size, n;
    std::cin >> size >> n;
    Queue queue(size);
    int packets[n] = {};
    int arr, dur;
    int time = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr >> dur;
        if (!queue.full()) {
            packets[i] = queue.enqueue(arr, dur);
        } else {
            if (arr >= queue.first_finish()) {
                queue.dequeue();
                packets[i] = queue.enqueue(arr, dur);
            } else {
                packets[i] = -1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << packets[i] << std::endl;
    }
    return 0;
}