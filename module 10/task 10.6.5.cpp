//
// Created by  Milkij on 09.08.2021.
//
#include "iostream"

void showString(std::string s) {
    std::cout << s << std::endl;
}

bool checkSymb(std::string str) {
    bool isValid = false;
    if (str.length()==9) isValid=true;
    int i = 0;
    for (; i < str.length() && isValid; i++) {
        if (str[i]=='X' || str[i]=='O' || str[i] == '.') {
            continue;
            } else isValid = false;
        }
    return isValid;
    }

bool checkCombinations (char symb, std::string str) {
    bool isRightCombination = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[0] == symb && str[1] == symb && str[2] == symb) isRightCombination = true;
        if (str[3] == symb && str[4] == symb && str[5] == symb) isRightCombination = true;
        if (str[6] == symb && str[7] == symb && str[8] == symb) isRightCombination = true;
        if (str[0] == symb && str[3] == symb && str[6] == symb) isRightCombination = true;
        if (str[1] == symb && str[4] == symb && str[7] == symb) isRightCombination = true;
        if (str[2] == symb && str[5] == symb && str[8] == symb) isRightCombination = true;
        if (str[0] == symb && str[4] == symb && str[8] == symb) isRightCombination = true;
        if (str[2] == symb && str[4] == symb && str[6] == symb) isRightCombination = true;
    }
    return isRightCombination;
}

void checkExesAndZeros (std::string str){
    bool isExists = checkSymb(str);
    int x=0, o=0, p=0;
    for (int i = 0; i<str.length();i++){
        if(str[i]=='X') x++;
        if(str[i]=='O') o++;
        if(str[i]=='.') p++;
    }
    if (x==o) isExists=false;
    if (p>4) isExists=false;

    if (isExists && checkCombinations('X', str)) showString("Petya won");
    else if (isExists && checkCombinations('O', str)) showString("Vanya won");
    else if (isExists && !checkCombinations('X',str) && !checkCombinations('O',str)) showString("NOBODY");
    else showString("Incorrect");
}

int main() {
std::string f = "XOX";
std::string s = "OXO";
std::string t = "OXO";



checkExesAndZeros(f+s+t);

}
