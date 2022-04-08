#include <iostream>
#include <vector>

int main () {
    std::vector<int> v = {-100, -50, -1, 1, 2, 3, 4};

    int j = 0;
    while (j < v.size() && v[j] < 0) {
        ++j;
    }

    int i = j--;
    while (j >= 0 || i < v.size()) {
        int res = (j >= 0 && (i == v.size() || v[i] > -v[j]) ? v[j--] : v[i++]);
        std::cout << res << ' ';
    }

    std::cout << '\n';

    return 0;
}