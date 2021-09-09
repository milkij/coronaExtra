//
// Created by  Milkij on 09.09.2021.
//
#include "iostream"

int main(){
    float floatNumbers[15];
    std::cout << "Input 15 float naumbers" << std::endl;
    for (int i=0; i<15; i++){
        std::cin >> floatNumbers[i];
    }
    float x;
    for (int i=0;i<15;i++){
        for (int j=0;j<14;j++){
            if(floatNumbers[j]>floatNumbers[j+1]){
               x=floatNumbers[j];
               floatNumbers[j]=floatNumbers[j+1];
               floatNumbers[j+1]=x;
            }
        }
    }
    for(int i=0;i<15;i++) std::cout << floatNumbers[i] << " ";
}