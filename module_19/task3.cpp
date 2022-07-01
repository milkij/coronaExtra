//
// Created by Александр Широков on 27.06.2022.
//
#include "iostream"
#include "fstream"
#include "vector"

int main(){
    std::ifstream bill;
    bill.open("//Users//alexander//CLionProjects//coronaExtra//module_19//bill.txt");
    if(!bill.is_open()) {
        std::cout << "file is not exists";
        return 0;
    }
    std::string firstName;
    std::string lastName;
    int sum;
    std::string date;
    char buffer[1];
    int maxSum=0;
    std::string maxName;
    while (!bill.eof()){
        bill >> firstName >> lastName >> sum >> date;
        bill.read(buffer,1);
        //std::cout << firstName << ' ' << lastName << ' ' << sum << ' ' << date << std::endl;
        if (sum>maxSum) {
            maxSum=sum;
            maxName=firstName+' '+lastName;
        }
    }
    bill.close();
    std::cout << "score:\n" << maxName << ' ' << maxSum;
    return 0;
}

