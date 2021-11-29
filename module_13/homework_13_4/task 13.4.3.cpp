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
        if(robots.capacity()-robots.size()==2) {
            std::cout << "Thare are two places in the room." << std::endl;
            robots.pop_back();
        }
    }
    for (int i=0; i<robots.size(); i++) std::cout<< robots[i] << " ";

}