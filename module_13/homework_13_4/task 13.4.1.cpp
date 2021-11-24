//
// Created by Александр Широков on 24.11.2021.
//
#include "iostream"
#include "vector"

int main(){
    int N;
    std::vector<int> robots;
    while (N!=-1) {
        std::cout<< "Input robot number: ";
        std::cin >> N;
        robots.push_back(N);
        //std::cout << robots.capacity() << " ";
    }
    for (int i=0; i<robots.size(); i++) std::cout<< robots[i] << " ";

}