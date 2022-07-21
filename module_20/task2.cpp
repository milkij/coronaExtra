//
// Created by Александр Широков on 11.07.2022.
//
#include "iostream"
#include "ctime"
#include "fstream"
bool test_mode=false;
int main(){
    std::srand(std::time(nullptr));
    int height=50, weight=100;
    if(!test_mode) {
        std::cout << "Input height and weight of picture in one line: ";
        std::cin >> height >> weight;
    }
    std::ofstream pic("//Users//alexander//CLionProjects//coronaExtra//module_20//pic.txt");
    if(!pic.is_open()) return 1;
    for (int i=0; i<height;i++) {
        for(int j=0; j<weight; j++) {
           pic << std::rand()%2;
        }
        pic<<std::endl;
    }
    pic.close();
}

