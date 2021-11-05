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
    int M=0;
    //int vecSize = vec.size();
    while (vec.size()>0 && M!=-1) {
        std::cout << "input a number of robot quque what you want to buy: ";
        std::cin >> M;
        vec=del(vec,M);
    }

    if (vec.size()==0) std::cout << "All robots have been bought";

    for (int i=0; i < vec.size(); i++){
        std::cout << vec[i] << ' ';
    }

}
