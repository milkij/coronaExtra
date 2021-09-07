//
// Created by  Milkij on 07.09.2021.
//
#include "iostream"
#include "string"

int main(){
    std::string surname[10];
    std::cout << "Input 10 Surnames:" << std::endl;
    for (int i=0; i<10; i++){
        std::cin >> surname[i];
    }
    std::cout << "Chose 3 random flats from 0 to 9:" << std::endl;
    int numbersOfFlat[3];
    for (int i=0; i<3;i++){
        std::cin >> numbersOfFlat[i];
        if(numbersOfFlat[i]<0 || numbersOfFlat[i]>9){
            std::cout << "Incorect number of flat." << std::endl;
            i--;
        }
    }
    for (int i=0;i<3;i++) std::cout<<surname[numbersOfFlat[i]];
}

