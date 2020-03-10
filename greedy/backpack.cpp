#include <iostream>
#include <algorithm>
#include <iomanip>

struct Item {
    explicit Item() {
        this->cost = 0;
        this->weight = 0;
        this->prop = 0;
    }

    explicit Item(int cost, int weight) {
        this->cost = cost;
        this->weight = weight;
        this->prop = (double)cost / weight;
    }

    int cost;
    int weight;
    double prop;
};

bool comp(Item a, Item b) {
  return a.prop > b.prop;
}

int main() {
    int n, W;
    std::cin >> n >> W;
    Item arr[n];
    int ci, wi;
    for (int i = 0; i < n; ++i) {
        std::cin >> ci >> wi;
        arr[i] = Item(ci, wi);
    }

    std::sort(arr, arr + n, comp);

    double max_cost = 0;
    double weight_remains = W;
    int i = 0;
    while (weight_remains > 0 && i <= n) {
        if (arr[i].weight <= weight_remains) {
            weight_remains -= arr[i].weight;
            max_cost += arr[i].cost;
        } else {
            max_cost += weight_remains * arr[i].prop;
            weight_remains = 0;
        }
        ++i;
    }
    std::cout << std::fixed << std::setprecision(3) << max_cost << std::endl;
	return 0;
}