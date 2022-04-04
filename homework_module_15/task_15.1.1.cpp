//
// Created by Александр Широков on 23.03.2022.
//
#include <iostream>
#include "vector"

using namespace std;
int main() {

    std::vector<int> a{-2,1,-3,4,-1,2,1,-5,4,10};
    if (a.size() == 0) return 0;

    int max_sum = a[0], max_start = -1, max_end = -1;
    int cur_sum = 0, start = 0;

    for (int i = 0; i < a.size(); ++i) {
        if (cur_sum <= 0) {
            start = i;
            cur_sum = 0;
        }

        cur_sum += a[i];

        if (cur_sum >= max_sum) {
            max_sum = cur_sum;
            max_start = start;
            max_end = i;
        }
    }

    cout<<max_start<<':'<<max_end<<':'<<max_sum;

    return 0;
}