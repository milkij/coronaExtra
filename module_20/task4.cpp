//
// Created by Александр Широков on 19.07.2022.
//
#include "iostream"
#include "fstream"
#include "ctime"
#include "cstdlib"
#include "vector"

const int nominalValue[] = {100,200,500,1000,2000,5000};
const int capacityAtm=1000;

int addMoneyToATM(std::vector<int>&money) {
    std::srand(std::time(nullptr));
    int count = 0;
    int randValue;
    int sumOfMoney = 0;
    std::ofstream ATM("//Users//alexander//CLionProjects//coronaExtra//module_20//ATM_DB.bin", std::ios::binary);
    while (count < capacityAtm) {
        randValue = nominalValue[std::rand() % 6];
        ATM.write((char *) &randValue, sizeof(randValue));
        sumOfMoney += randValue;
        count++;
    }
    ATM.close();
    //std::vector<int> money;
    std::ifstream ATM_read("//Users//alexander//CLionProjects//coronaExtra//module_20//ATM_DB.bin", std::ios::binary);
    while (!ATM_read.eof()) {
        ATM_read.read((char *) &randValue, sizeof(randValue));
        money.push_back(randValue);
    }
    ATM_read.close();
    int controlSum=0, vectorLen=0;
    for (int i =0; i<money.size()-1; i++) {
        controlSum+=money[i];
        vectorLen++;
    }
    if(sumOfMoney==controlSum && capacityAtm==vectorLen) {
        //std::cout << "Add money in ATM " << sumOfMoney << " c.e" << std::endl;
        return controlSum;
    } else return 0;

}
int currentSum(std::vector<int> atm) {
    int controlSum=0;
    for (int i=0; i<capacityAtm; i++) {
        controlSum+=atm[i];
    }
    return controlSum;
}

void deleteSumFromArr(std::vector<int> &moneyInAtm, int sum, int numOfBanknotes){
    int count;
    for (int i =0; i < capacityAtm && count <= numOfBanknotes; i++) {
        if (moneyInAtm[i]==sum) {
            moneyInAtm[i]=0;
            count++;
        }
    }
}

void takeCash(int &curentSum, std::vector<int> &moneyInAtm){
    std::cout<<"Input your sum:";
    int balance;
    std::cin >> balance;
    while(balance%100!=0) {
        std::cout<<"Input your sum again. The sum should by divisible on 100:";
        std::cin >> balance;
    }
    if (balance>curentSum) {
        std::cout << "There is only " << curentSum;
        return;
    }
    int numOfBanknotes=0;
    if (balance % 5000 != 0 && balance >= 5000) {
        numOfBanknotes = balance / 5000;
        deleteSumFromArr(moneyInAtm,5000,numOfBanknotes);
        balance %= 5000;
        std::cout << "5000 * " << numOfBanknotes << "\n";
    } else if (balance % 5000 == 0) {
        numOfBanknotes = balance / 5000;
        std::cout << "5000 * " << numOfBanknotes << "\n";
        balance %= 5000;
    }
    if (balance >= 2000 && balance % 2000 != 0) {
        numOfBanknotes = balance / 2000;
        balance %= 2000;
        std::cout << "2000 * " << numOfBanknotes << "\n";
    } else if (balance >= 2000 && balance % 2000 == 0) {
        numOfBanknotes = balance / 2000;
        std::cout << "2000 * " << numOfBanknotes << "\n";
        balance %= 2000;
    }
    if (balance > 1000 && balance % 1000 != 0) {
        numOfBanknotes = balance / 1000;
        balance %= 1000;
        std::cout << "1000 * " << numOfBanknotes << "\n";
    } else if (balance == 1000) {
        numOfBanknotes = balance / 1000;
        std::cout << "1000 * " << numOfBanknotes << "\n";
        balance %= 1000;
    }
    if (balance > 500 && balance % 500 != 0) {
        numOfBanknotes = balance / 500;
        balance %= 500;
        std::cout << "500  * " << numOfBanknotes << "\n";
    } else if (balance == 500) {
        numOfBanknotes = balance / 500;
        std::cout << "500  * " << numOfBanknotes << "\n";
        balance %= 500;
    }
    if (balance >= 200 && balance % 200 != 0) {
        numOfBanknotes = balance / 200;
        balance %= 200;
        std::cout << "200  * " << numOfBanknotes << "\n";
    } else if (balance > 0 && balance % 200 == 0) {
        numOfBanknotes = balance / 200;
        std::cout << "200  * " << numOfBanknotes << "\n";
        balance %= 200;
    }
    if (balance == 100 && balance % 100 != 0) {
        numOfBanknotes = balance / 100;
        balance %= 100;
        std::cout << "100  * " << numOfBanknotes << "\n";
    } else if (balance == 100) {
        numOfBanknotes = balance / 100;
        std::cout << "100  * " << numOfBanknotes << "\n";
    }

}

    int main() {
        char type_of_operation;
        int moneyInAtm=0;
        std::vector<int> moneyInAtmColection;
        //switch on ATM
        while (true) {
            while(moneyInAtm==0) {
                std::cout << "--- Current balance is " << moneyInAtm << " ---" << std::endl <<"You can choose only a comand of ATM + for adding money.";
                std::cout << std::endl << "Input command: ";
                std::cin >> type_of_operation;
                if (type_of_operation == '+') {
                    moneyInAtm=addMoneyToATM(moneyInAtmColection);
                }
            }
            std::cout << "-----"<< moneyInAtm << "------" << std::endl;
            std::cout << "Choose an operation of ATM + for adding money or - for taking money: ";
            std::cin >> type_of_operation;
            if (type_of_operation == '+') moneyInAtm=addMoneyToATM(moneyInAtmColection);

            if(type_of_operation == '-') takeCash(moneyInAtm, moneyInAtmColection);

            moneyInAtm=currentSum(moneyInAtmColection);
            std::string whatWillDo;
            std::cout << "Press any button to continie: ";
            std::cin >> whatWillDo;
            if(whatWillDo!="exit") continue;
            else break;
        }
    }

