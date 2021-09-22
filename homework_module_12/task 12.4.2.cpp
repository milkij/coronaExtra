//
// Created by  Milkij on 09.09.2021.
//
#include "iostream"


int main() {
    int numbers[15];
    int X;
    std::cout << "Input the first number:" << std::endl;
    std::cin >> X;
    std::cout << std::endl;
    for (int i = 0; i < 15; i++) {
        numbers[i] = X + i;
    }
    int randomIndex, randomPlace;
    while (true) {
        randomIndex = rand() % 15;
        randomPlace = rand() % 15;
        if (randomIndex != randomPlace) {
            numbers[randomIndex] = numbers[randomPlace];
            break;
        }
    }

    std::cout << "The X number is " << X << " and ";
    int sum=0;
    for(int i=0;i<15;i++) if(numbers[i]<=numbers[i-1]) std::cout << numbers[i] << " is a dublicate." << std::endl;
    //for(int i=0;i<15;i++) std::cout << numbers[i] << ", ";
    //std::cout << "SumOf is " << sum / 15;
}

