#include <iostream>
#include <string>
#include <algorithm>

struct Node {
    Node() {
        symbol = 0;
        freq = 0;
        first = NULL;
        second = NULL;
    }

    char symbol;
    int freq;
    Node * first;
    Node * second;
};

struct Tree {
    Tree() {
        Node * node = new Node;
        root = node;
    }

    void generate_path(Node * node, std::string path, char const & symbol) {
        if (path.size() == 0) {
            node->symbol = symbol;
            return;
        }
        if (path.at(0) == '0') {
            if (node->first == NULL) {
                Node * temp = new Node;
                node->first = temp;
            }
            generate_path(node->first, path.substr(1), symbol);
        }
        if (path.at(0) == '1') {
            if (node->second == NULL) {
                Node * temp = new Node;
                node->second = temp;
            }
            generate_path(node->second, path.substr(1), symbol);
        }
    }

    Node * get_node(Node * node, std::string const & code) {
        if (code.size() == 0) {
            return node;
        }
        if (code.at(0) == '0') {
            return get_node(node->first, code.substr(1));
        }
        if (code.at(0) == '1') {
            return get_node(node->second, code.substr(1));
        }
        return node;
    }

    Node * root;
};

int main() {
    int k, len;
    std::cin >> k >> len;
    char symbol, stub;
    std::string code;
    Node * node;
    Tree tree;
    for (int i = 0; i < k; ++i) {
        std::cin >> symbol;
        std::cin >> stub;
        std::cin >> code;
        tree.generate_path(tree.root, code, symbol);
    }

    node = tree.root;
    for (int i = 0; i < len; ++i) {
        std::cin >> symbol;
        node = tree.get_node(node, std::string(1, symbol));
        if (node->symbol != 0) {
            std::cout << node->symbol;
            node = tree.root;
        }
    }
    std::cout << std::endl;
    return 0;
}