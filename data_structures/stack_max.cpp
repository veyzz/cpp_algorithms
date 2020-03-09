#include <iostream>
#include <string>
#include <algorithm>

struct Node {
    int value;
    int max;
    Node * prev = NULL;
};

struct Stack {
    void push(int value) {
        Node * element = new Node;
        if (head_ == NULL) {
            element->max = value;
            element->value = value;
            head_ = element;
        } else {
            element->prev = head_;
            element->max = std::max(value, head_->max);
            head_ = element;
        }
    }

    int pop() {
        if (head_ == NULL) {
            return -777777;
        } else {
            Node *p = head_;
            int rt = p->value;
            head_ = head_->prev;
            delete p;
            return rt;
        }
    }

    int max() {
        if (head_ == NULL) {
            return -777777;
        } else {
            return head_->max;
        }
    }

private:
    Node * head_ = NULL;
};

int main() {
    int n, value;
    std::string query;
    Stack stack;
    int max;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> query;
        if (query == "push") {
            std::cin >> value;
            stack.push(value);
        } else if (query == "pop") {
            stack.pop();
        } else if (query == "max") {
            max = stack.max();
            if (max != -777777) {
                std::cout << stack.max() << std::endl;
            }
        }
    }
	return 0;
}