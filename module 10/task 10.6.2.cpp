//
// Created by  Milkij on 22.07.2021.
//

#include "iostream"

bool checkSymbol (char chr) {
    bool value = false;
    std::string specialSymbols = "@.!#$%&'*+-/=?^_`{|}~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < specialSymbols.length(); i++) {
        if (specialSymbols[i] == chr) {
            value = true;
            break;
        }
    }
    return value;
}

bool countOfSymbols (std::string str) {
    bool cnt = false;
    int points = 0;
    int ats = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') points++;
        if (str[i] == '@') ats++;
        if (points > 0 && ats == 1) cnt = true;
    }
    return cnt;
}

bool secondPartContainsPoints (std::string str) {
    bool thereIs = false;
    int i = 0;
    //std::string second;
    if (countOfSymbols(str)) thereIs = true;
    for (; i < str.length() && thereIs; i++) {
        if (str[i] == '@') {
            i += 1;
            break;
        }
    }
    for (;i < str.length() && thereIs; i++) {
        if (str[i] == '.' && (str[i] != str.length() - 1) || !(str[i] == '.' && str[i - 1] == '@')) {
            thereIs = true;
        }
    }
    return thereIs;
}

bool checkEmail (std::string str) {
    bool check = true;
    if (!secondPartContainsPoints(str)) check = false;
    for (int i = 0; i < str.length() && check; i++) {
        if ((i == 0 && (str[i] == '.' || str[i] == '@'))
                || (i > 0 && str[i] == '.' && str[i - 1] == '.')
                    || !checkSymbol(str[i])) {
            check = false;
            break;
        }
    }
    return check;
}


int main () {
    std::string email = "shir@.y.ru";

   if (checkEmail(email)) {
       std::cout << "Yes";
   } else {
       std::cout << "No";
   };
}