#include <iostream>
#include <algorithm>

struct Node {
    int value;
    int max;
    Node * prev;
};

struct Stack {
    void push(int value) {
        Node * p = new Node;
        p->value = value;
        p->prev = head;
        if (head == NULL) {
            p->max = value;
        } else {
            p->max = std::max(head->max, value);
        }
        head = p;
    }

    int get_max() {
        if(head == NULL) {
            return -1;
        }
        return head->max;
    }

    void pop() {
        if(head != NULL) {
            Node * tmp = head;
            head = head->prev;
            delete tmp;
        }
    }

    Node * head = NULL;
};

struct Queue {
    void enqueue(int value) {
        pushstack.push(value);
    }

    void dequeue() {
        if(popstack.head == NULL) {
            while (pushstack.head != NULL) {
                int temp = pushstack.head->value;
                pushstack.pop();
                popstack.push(temp);
            }
        }
        popstack.pop();
    }

    int get_max() {
        return std::max(pushstack.get_max(), popstack.get_max());
    }

    Stack pushstack, popstack;
};

int main() {
    int n, m;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    std::cin >> m;
    Queue queue;
    for (int i = 0; i < m; ++i) {
        queue.enqueue(array[i]);
    }
    std::cout << queue.get_max();
    for (int i = m; i < n; ++i) {
        queue.enqueue(array[i]);
        queue.dequeue();
        std::cout << " " << queue.get_max();
    }
    std::cout << std::endl;
}