#include <iostream>
#include <vector>
#include <algorithm>

int const LEFT = -1;
int const POINT = 0;
int const RIGHT = 1;

struct Point {
    Point(int const & value, int const & type, int const & index)
        : value(value)
        , type(type)
        , index(index)
    {}

    int value;
    int type;
    int index;
};

bool comp(Point const & a, Point const & b){
    if (a.value != b.value) {
        return a.value < b.value;
    } else {
        return a.type < b.type;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    int a, b;
    std::vector<Point> points;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        points.emplace_back(a, LEFT, -1);
        points.emplace_back(b, RIGHT, -1);
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> a;
        points.emplace_back(a, POINT, i);
    }
    std::sort(points.begin(), points.end(), comp);
    std::vector<int> answer(m, -1);
    int counter = 0;
    for (auto const & it : points) {
        if (it.type == LEFT) {
            ++counter;
        } else if (it.type == RIGHT) {
            --counter;
        } else {
            answer[it.index] = counter;
        }
    }
    for (auto const & it : answer) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
	return 0;
}