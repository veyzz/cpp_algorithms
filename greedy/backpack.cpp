#include <iostream>
#include <algorithm>
#include <iomanip>

struct Item {
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
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i].cost >> arr[i].weight;
        arr[i].prop = (double)arr[i].cost / arr[i].weight;
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