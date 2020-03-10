#include <iostream>
#include <algorithm>
#include <vector>

struct Segment {
    Segment intersect(Segment const & another) const {
        Segment temp;
        temp.left = std::max(this->left, another.left);
        temp.right = std::min(this->right, another.right);
        if (temp.left > temp.right) {
            temp = {-1, -1};
        }
        return temp;
    }

    int left;
    int right;
};

bool comp(Segment a, Segment b) {
  return a.right < b.right;
}

int main() {
    int n;
    std::cin >> n;
    Segment arr[n];
    std::vector<int> solution;
    Segment temp;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp.left >> temp.right;
        arr[i] = temp;
    }

    std::sort(arr, arr + n, comp);

    Segment sect;
    for (int i = 0; i < n; ++i) {
        sect = arr[i];
        int j;
        for (j = i + 1; j < n; ++j) {
            temp = sect.intersect(arr[j]);
            if (temp.left == temp.right && temp.left == -1) {
                break;
            }
            sect = temp;
        }
        solution.push_back(sect.right);
        i = j - 1;
    }

    std::cout << solution.size() << std::endl;
    for (int i = 0; i < solution.size(); ++i) {
        std::cout << solution[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}