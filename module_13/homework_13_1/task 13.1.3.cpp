//
// Created by Александр Широков on 11.10.2021.
//
#include "iostream"
#include "vector"

int main(){
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    for (int i=0; i<N; i++){
        std::cin >> vec[i];
    }
    int max = vec[0],preMax = vec[0];
    for (int i=1; i<N; i++){
        if(max < vec[i]) {
            max = vec[i];
        }
        if (preMax < max && preMax > vec[i]) {
            //preMax = vec[i];
        }
    }
}
