//
// Created by  Milkij on 09.08.2021.
//
#include "iostream"

bool checkFloat (std::string someFloatNumber) {
    int i = 0;
    int amountOfPoints = 0;
    bool thereIsNoForbidenSymbols = true;
    for (int i = 0 ; i < someFloatNumber.length() && thereIsNoForbidenSymbols; i++) {
        if (someFloatNumber[i] ==  '+' && i == 0) {
            //return "The plus is not exist\n";
            thereIsNoForbidenSymbols = false;
        }
        if (someFloatNumber[i] ==  'e') {
            //return "The 'e' is not exist\n";
            thereIsNoForbidenSymbols = false;
        }
        if (someFloatNumber[i] == '.') {
            amountOfPoints++;
            if (amountOfPoints > 1) {
                //return "There are so many points in a number\n";
                thereIsNoForbidenSymbols = false;
            }
        }
    }

    bool isFloat = true;
    for (int i = 0; i < someFloatNumber.length() && thereIsNoForbidenSymbols; i++) {
        if ((someFloatNumber[i] - '0' >= 0 && someFloatNumber[i] - '0' <= 9) || someFloatNumber[i] == '.' ||  (someFloatNumber[i] == '-' && i == 0)) {
            continue;
        } else {
            //std::cout << someFloatNumber[i] << "\n";
            isFloat = false;
        }
    }
    if (thereIsNoForbidenSymbols) {
        if (isFloat) return true;
        else return false;
    } else return false;
}

int sumOfChars(std::string x) {
    int sumOf = 0;
    for (int i = 0; i < x.length(); i++) {
        if(x[i]=='.') sumOf+=0;
        else sumOf+=(int)x[i];

    }
    return sumOf;
}

std::string cutZeros(std::string s) {
    if(s[0]=='0'){
        int i=0;
        for(;i<s.length();) {
            if(s[i]=='0') i++;
            else break;
        }
        s.erase(0,i);
    }
    if(s[s.length()-1]=='0'){
        int i=s.length()-1;
        for(;i!=0;){
            if(s[i]=='0') i--;
            else break;
        }
        s.erase(i+1,s.length()-1);
    }
    return s;
}

int main () {
    std::cout << "Input two float numbers:\n";
    std::string x;
    std::cin >> x;
    std::string y;
    std::cin >> y;


    if (checkFloat(cutZeros(x)) && checkFloat(cutZeros(y))) {
        int first = sumOfChars(x), second = sumOfChars(y);
        if(first<second) std::cout << "less" << std::endl;
        else if (first>second) std::cout << "more" << std::endl;
        else std::cout << "equal" << std::endl;
    } else std::cout << "Error" << std::endl;
    std::cout << cutZeros(x) << std::endl;
    std::cout << cutZeros(y) << std::endl;
}
