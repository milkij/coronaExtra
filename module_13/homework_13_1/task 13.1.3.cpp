//
// Created by Александр Широков on 11.10.2021.
//
#include "iostream"
#include "vector"

int main(){
    int N = 6;
    //std::cin >> N;
    std::vector<int> vec = {7,4,5,2,3,6};
    //for (int i=0; i<N; i++) std::cin >> vec[i];
    int max = vec[0], mid = vec[1], first;
    for (int i=1; i<N; i++) {
        if(max < vec[i]) {
            mid=max;
            max = vec[i];
        }
        if (mid < max && vec[i]!=max) mid = vec[i];
    }
    std::cout << "max is " << max << " and pre max is " << mid << std::endl;
}
