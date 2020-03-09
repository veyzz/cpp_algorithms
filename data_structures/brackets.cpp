#include <iostream>
#include <stddef.h>
#include <string>

struct Node {
    Node(char value, int index)
        : value(value), index(index)
    {}
    char value;
    int index;
    Node * prev = NULL;
};

struct Stack {
    char pop() {
        if (size_ > 0) {
            Node * element = this->head_;
            char value = element->value;
            this->head_ = element->prev;
            --(this->size_);
            delete element;
            return value;
        } else {
            return 0;
        }
    }

    void push(char const & value, int const & index) {
        Node * new_element = new Node(value, index);
        new_element->prev = this->head_;
        this->head_ = new_element;
        ++(this->size_);
    }

    size_t size() const {
        return this->size_;
    }

    Node const * top() const {
        return this->head_;
    }

private:
    Node * head_ = NULL;
    size_t size_ = 0;
};

int correct_brackets(std::string const & str) {
    Stack stack;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack.push(str[i], i + 1);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (stack.size() == 0) {
                return i + 1;
            }
            Node const * top_el = stack.top();
            if ((top_el->value == '(' && str[i] == ')') || \
                (top_el->value == '[' && str[i] == ']') || \
                (top_el->value == '{' && str[i] == '}')) {
                stack.pop();
            } else {
                return i + 1;
            }
        }
    }
    if (stack.size() > 0) {
        return stack.top()->index;
    }
    return 0;
}

int main() {
    std::string str;
    std::cin >> str;
    int result = correct_brackets(str);
    if (result == 0) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << result << std::endl;
    }
    return 0;
}