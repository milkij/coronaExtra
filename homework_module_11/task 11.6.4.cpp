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
    int i=0,j=s.length();
    for (;i<s.length();) {
        if(s[i]=='0') i++;
        else break;
    }
    for (;j!=0;j--) {
        if(s[j]=='0') continue;
        else break;
    }
    if (s.find('.')!=-1) return s.substr(i,j-1);
    else return s.substr(i,j);
}

int main () {
    std::cout << "Input two float numbers:\n";
    std::string x;
    std::cin >> x;
    std::string y;
    std::cin >> y;

    x = cutZeros(x);
    y = cutZeros(y);
    std::cout << x <<std::endl;
    std::cout << y <<std::endl;
    if (checkFloat(x) && checkFloat(y)) {
        int first = sumOfChars(x), second = sumOfChars(y);
        if(first<second) std::cout << "less" << std::endl;
        else if (first>second) std::cout << "more" << std::endl;
        else std::cout << "equal" << std::endl;
    } else std::cout << "Error" << std::endl;


}