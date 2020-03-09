#include <iostream>
#include <vector>
#include <algorithm>

struct Tree {

    void add_child(Tree * child) {
        children_.push_back(child);
    }

    int height() const {
        int h = 1;
        for (int i = 0; i < children_.size(); ++i) {
            h = std::max(h, children_[i]->height() + 1);
        }
        return h;
    }

private:
    std::vector<Tree *> children_;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Tree> tree_array(n);
    int root, ind;
    for (int i = 0; i < n; ++i) {
        std::cin >> ind;
        if (ind == -1) {
            root = i;
        }
        else {
            tree_array[ind].add_child(&tree_array[i]);
        }
    }
    std::cout << tree_array[root].height() << std::endl;
    return 0;
}