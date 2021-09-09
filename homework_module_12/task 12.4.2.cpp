//
// Created by  Milkij on 09.09.2021.
//
#include "iostream"

int main(){
    int numbers[15];
    int X;
    std::cout << "Input the first number:" << std::endl;
    std::cin >> X;
    std::cout << std::endl;
    for (int i = 0; i<15; i++) {
        numbers[i]=X+i;
    }
    int randomIndex,randomPlace;
    while (true) {
        randomIndex = rand() % 15;
        randomPlace = rand() % 15;
      if(randomIndex!=randomPlace) {
          numbers[randomIndex] = numbers[randomPlace];
          break;
      }
    }

    std::cout << "The X number is " << X << " and ";
    int countOfCoincidence = 0, IndexOfCoincidence = 0;
    for (int i = 0; i<15; i++) {
        //std::cout << numbers[i] << std::endl;
        for(int j = 0; j<15;j++){
            if(numbers[i]==numbers[j]) countOfCoincidence++;
            if(countOfCoincidence>1) break;
        }
        if (countOfCoincidence>1) {
            IndexOfCoincidence=i;
            break;
        } else countOfCoincidence = 0;
    }
    //std::cout << countOfCoincidence << std::endl;
    std::cout << "the coincidence number is " << numbers[IndexOfCoincidence] << "." << std::endl;
    //for (int i = 0; i<15; i++) std::cout << numbers[i] << std::endl;
}
