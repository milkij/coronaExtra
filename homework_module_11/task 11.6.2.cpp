//
// Created by  Milkij on 22.07.2021.
//

#include "iostream"

bool checkSymbol (char symbol, int part) {
    bool is_exists = false;
    std::string specialSymbols;
    if (part == 1) specialSymbols = ".!#$%&'*+-/=?^_`{|}~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (part == 2) specialSymbols = ".-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0; i < specialSymbols.length(); i++) {
            if (specialSymbols[i] == symbol) {
                is_exists = true;
                break;
            }
        }
    return is_exists;
}

bool checkAtsAndPoints (std::string str) {
    bool is_exists = false;
    int at = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '@') at++;
    }
    if (at == 1) is_exists = true;
    if (is_exists && (str[0] == '.' || str[str.length()] == '.')) is_exists = false;
    for (int i = 0; is_exists && i < str.length(); i++) {
        if (str[i] == '.' && (str[i + 1] == '.' || (i != 0 && str[i - 1] == '.'))) is_exists = false;
    }
    return is_exists;
}

bool checkEmail (std::string str) {
    bool is_validPart = false;
    if (checkAtsAndPoints(str)) is_validPart = true;
    //find position of at
    int postionOfAt;
    int countOfSymb = 0;
    for (int i = 0; i < str.length() && is_validPart; i++) {
        if (str[i] == '@') {
            postionOfAt = i;
            break;
        } else {
            countOfSymb++;
        }
    }
    if (countOfSymb == 0 || countOfSymb > 64) is_validPart = false;

    for (int j = 0; j < str.length() && j < postionOfAt && is_validPart; j++) {
        is_validPart = false;
        if (checkSymbol(str[j], 1)) {
            is_validPart = true;
        }
    }

    countOfSymb = 0;

    for (int j = postionOfAt + 1; j < str.length() && is_validPart; j++) {
        is_validPart = false;
        countOfSymb++;
        if (checkSymbol(str[j], 2)) {
            is_validPart = true;
        }
    }

    if (countOfSymb == 0 || countOfSymb > 63) is_validPart = false;

    return is_validPart;
}


int main() {
    std::string email = "shirokov@ya.ru";

   if (checkEmail(email)) {
       std::cout << "Yes" << std::endl;
   } else {
       std::cout << "No" << std::endl;
   }

}