//
// Created by Александр Широков on 19.07.2022.
//
#include "iostream"
#include "fstream"

int main () {
    std::ifstream river("//Users//alexander//CLionProjects//coronaExtra//module_20//river.txt");
    std::ofstream basket("//Users//alexander//CLionProjects//coronaExtra//module_20//basket.txt", std::ios::app);
    if(!river.is_open() || !basket.is_open()) return 1;
    std::string fish;
    std::string buffer;
    int count=0;
    while (true){
        if(fish=="finish") {
            std::cout << "Game over!" << std::endl << "You have caught " << count << " fishes.";
            break;
        }
        std::cout << "Input name of fish: ";
        std::cin >>  fish;
        while (!river.eof()) {
            river >> buffer;
            if(buffer==fish) {
                basket << buffer << std::endl;
                count++;
                std::cout << "------Congratulate!!! The fish " << fish << " in your basket.------";
                std::cout << std::endl << std::endl;
                break;
            };
        }
        river.seekg(0);
    }
    river.close();
    basket.close();

}