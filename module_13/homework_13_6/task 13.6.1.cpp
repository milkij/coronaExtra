//
// Created by Александр Широков on 25.11.2021.
//
#include "iostream"
#include "vector"

std::vector<int> newVec(std::vector<int> vec, int number) {
    if (vec.size()==0 || number==-1) return vec;
    //int count=0;
    //for (int i=0; i<vec.size(); i++) if(vec[i]==number) count++;
    //std::vector<int> newVec;
    //for (int i=0; i<vec.size();i++) if(vec[i]!=number) newVec.push_back(vec[i]);
    //if (count==0) newVec.push_back(number);
    //return newVec;
    using namespace std;
    vector<int> newVec(vec.size());
    int j=0;
    for (int i=0; i<vec.size(); i++) {
        if(vec[i]!=number) {
            newVec[j]=vec[i];
            ++j;
        }
    }
    newVec.resize(j);
    if (newVec.size()==vec.size()) newVec.push_back(number);
    return newVec;

}

int main(){
    std::vector<int> vec = {1, 3, 3, 5, 1};
    int n;
    while (n!=-1){
        std::cout << "input a number: ";
        std::cin >> n;
        vec=newVec(vec,n);

        if (vec.size()==0) {
            std::cout << "All elements have been deleted" << std::endl;
            break;
        } else {
            std::cout << "result: ";
            for (int i=0; i<vec.size(); i++) std::cout<< vec[i] << " ";
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << "summery:" << std::endl;
    if (vec.size()==0) std::cout << "vector is empty" << std::endl;
    for (int i=0; i<vec.size(); i++) std::cout<< vec[i] << " ";

}
