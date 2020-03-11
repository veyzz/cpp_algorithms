#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

struct Node {
    char symbol = 0;
    int freq = 0;
    Node * first = NULL;
    Node * secord = NULL;
};

bool comp(Node const * a, Node const * b) {
    return a->freq < b->freq;
}

void get_codes(Node const * a, std::map<char, std::string> & codes, std::string code) {
    if (a->symbol != 0) {
        codes[a->symbol] = code;
    }
    if (a->first != NULL) {
        get_codes(a->first, codes, code + "0");
    }
    if (a->secord != NULL) {
        get_codes(a->secord, codes, code + "1");
    }
}

int main() {
    std::string str;
    std::cin >> str;
    std::map<char, int> frequency;
    for (auto const & c : str) {
        ++frequency[c];
    }
    int i = 0;
    int n = frequency.size();
    std::vector<Node *> arr(n);
    for (auto const & c : frequency) {
        Node * temp = new Node;
        temp->symbol = c.first;
        temp->freq = c.second;
        arr[i++] = temp;
    }

    while (arr.size() != 1) {
        Node * temp = new Node;
        auto it = std::min_element(arr.begin(), arr.end(), comp);
        temp->first = *it;
        temp->freq += (*it)->freq;
        arr.erase(it);
        it = std::min_element(arr.begin(), arr.end(), comp);
        temp->secord = *it;
        temp->freq += (*it)->freq;
        arr.erase(it);
        arr.push_back(temp);
    }

    std::map<char, std::string> codes;
    get_codes(arr[0], codes, "");

    if (codes.size() == 1) {
        auto it = codes.begin();
        (*it).second = "0";
    }

    std::string out;
    for (auto const & c : str) {
        out += codes[c];
    }
    std::cout << codes.size() << " " << out.size() << std::endl;
    for (auto const & c : codes) {
        std::cout << c.first << ": " << c.second << std::endl;
    }
    std::cout << out << std::endl;
	return 0;
}