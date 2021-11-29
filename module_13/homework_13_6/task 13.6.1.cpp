//
// Created by Александр Широков on 25.11.2021.
//
#include "iostream"
#include "vector"

std::vector<int> newVec(std::vector<int> vec, int number) {
    if (vec.size()==0 || number==-1) return vec;
    int count=0;
    std::vector<int> indexes;
    for (int i=0; i<vec.size(); i++) if(vec[i]==number) count++;

    if (count>0) {
        std::vector<int> newVec(vec.size()-count);
        int y=0;
        for (int i=0; i<vec.size(); i++) {
            if(vec[i]==number) y=i-1;
            else newVec[y]=vec[i];
            y++;
        }
        return newVec;
    } else {
        vec.push_back(number);
        return vec;
    }

}

int main(){
    std::vector<int> vec = {1, 3, 3, 5, 1};
    int n;
    std::cout << "input a number";
    while (n!=-1){
        std::cin >> n;
        vec=newVec(vec,n);
        //vec.push_back(n);
    }
    for (int i=0; i<vec.size(); i++) std::cout<< vec[i] << " ";
}
