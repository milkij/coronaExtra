//
// Created by Александр Широков on 31.10.2021.
//

#include "iostream"
#include "vector"

std::vector<int> del(std::vector<int> vec, int position){
    if (position==-1) return vec;
    position-=1;
    std::vector<int> newVec(vec.size()-1);
    for (int i=0; i<position; i++) {
        newVec[i]=vec[i];
    }
    for (int i=position; i<newVec.size(); i++) {
        newVec[i]=vec[i+1];
    }
    return newVec;
}

int main () {
    int N;
    std::cout << "Input count of robots:";
    std::cin >> N;
    std::vector<int> vec(N);
    for (int i=0; i<N; i++) {
        std::cout << "input robot numbers: ";
        std::cin >> vec[i];
    }
    bool cont = true;
    while (cont) {
        int M = 0;
        int sell;
        std::cout << "Would you like to buy robots 1/0 (Yes/No)?";
        std::cin >> sell;
        if (sell == 1) {
            while (vec.size() > 0 && M != -1) {
                std::cout << "input a number of robot quque what you want to buy: ";
                std::cin >> M;
                vec = del(vec, M);
                if (vec.size() == 0) std::cout << "All robots have been bought";
            }
        } else std::cout << "continue..." << std::endl;
        int add;
        std::cout << "Would you like to add robots in our quque 1/0 (Yes/No)?";
        std::cin >> add;
        if (add == 1) {
            int newRobot;
            while (newRobot!=-1) {
                std::cout << "Input new robot number:";
                std::cin >> newRobot;
                if (newRobot!=-1) {
                    vec.resize(vec.size() + 1);
                    vec[vec.size() - 1] = newRobot;
                }
            }
        } else std::cout << "continue..." << std::endl;

        std::cout << "Would you like to continue the operation 1/0 (Yes/No)?";
        int C;
        std::cin >> C;
        if (C==1) continue;
        else cont= false;
    }

    for (int i=0; i < vec.size(); i++){
        std::cout << vec[i] << ' ';
    }

}