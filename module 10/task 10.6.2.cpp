//
// Created by  Milkij on 22.07.2021.
//

#include "iostream"

bool checkAvailableCharInString (std::string str) {
    bool is_exists = true;
    std::string specialSymbols = "@.!#$%&'*+-/=?^_`{|}~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < str.length() && is_exists; i++) {
        is_exists = false;
        for (int j = 0; j < specialSymbols.length(); j++) {
            if (str[i] == specialSymbols[j]) {
                is_exists = true;
                break;
            }
        }
    }
    return is_exists;
}

bool findPointsAndAts (std::string str) {
    bool is_exists = false;
    if (checkAvailableCharInString(str)) is_exists = true;
    int points = 0, ats = 0;
    for (int i = 0; i < str.length() && is_exists; i++) {
        if (str[i] == '.') points++;
        if (str[i] == '@') ats++;
    }
    if (points > 0 && ats == 1 && is_exists) return true;
    else return false;
}

bool checkCases (std::string str) {
    bool is_valid = false;
    if (findPointsAndAts(str)) is_valid = true;
    for (int i = 0; i <= '@' && is_valid; i++) {
        if
       if (!(i == 0 && (str[i]) == '.' || str[i] == '@')) return true;
       else return false;
    }
}

bool checkDomain(std::string str) {

}

bool checkEmail (std::string str) {
    if (findPointsAndAts(str)) return true;
    else return false;
}


int main () {
    std::string email = "shirokov@ya.ru";

   if (checkCases(email)) {
       std::cout << "Yes" << std::endl;
   } else {
       std::cout << "No" << std::endl;
   };

   std::cout << email[email.length() - 1] << std::endl;


}