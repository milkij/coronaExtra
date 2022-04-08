//
// Created by Александр Широков on 18.10.2021.
//
#include "iostream"
#include "vector"

std::vector<int> add_to_position(std::vector<int> vec, int val, int position) {
    std::vector<int> newVec(vec.size()+1);
    for (int i = 0; i < position; i++) {
        newVec[i] = vec[i];
    }
    newVec[position] = val;
    position+=1;
    for (int i = position; i < newVec.size(); i++){
        newVec[i] = vec[i-1];
    }

    return newVec;
}

int main(){
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    int n=15, p=3;
    vec=add_to_position(vec,n,p);
    for(int i=0;i<vec.size();i++){
        std::cout << vec[i] << std::endl;
    }
}