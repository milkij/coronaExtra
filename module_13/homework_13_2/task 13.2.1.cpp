//
// Created by Александр Широков on 15.10.2021.
//
#include "iostream"
#include "vector"

std::vector<int> add(std::vector<int> vec, int n){
    std::vector<int> newVec(vec.size()+1);
    for(int i=0; i<vec.size();i++){
        newVec[i]=vec[i];
    }
    newVec[newVec.size()-1]=n;
    return newVec;
}

int main(){
    std::vector<int> vec;
    int n=0;
    while (n!=-1){
        std::cout << "enter a number" << std::endl;
        std::cin >> n;
        vec=add(vec,n);
    }

    for(int i=0;i<vec.size()-1;i++){
        std::cout << vec[i] << std::endl;
    }
}
