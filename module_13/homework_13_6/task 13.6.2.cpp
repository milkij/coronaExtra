//
// Created by Александр Широков on 25.11.2021.
//

#include "iostream"
#include "vector"

int main () {
    std::vector<float> price = {2.5, 4.25, 3.0, 10.0};
    std::cout << "input an index of product. You can choice from 1 to " << price.size() << '.' << std::endl;
    std::cout << "If you want to stop shopping - input the index 0" << std::endl;
    std::cout << "Let's go shopping! ";
    std::vector<int> index;
    //std::cout << "Input an index: ";
    int N=-1;
    while (true) {
        std::cout << "Input an index: ";
        std::cin >> N;
        while (N < 0 || N > price.size()) {
            std::cout << "Incorrect index of product. Input again: ";
            std::cin >> N;
        }
        if (N==0) {
            std::cout << "Stop shopping" << std::endl;
            break;
        }
        N-=1;
        index.push_back(N);
    }
    float result = 0;
    for (int i=0; i<index.size();i++){
        result += price[index[i]];
    }

    std::cout << "The cost of products is " << result << "$.";
}

