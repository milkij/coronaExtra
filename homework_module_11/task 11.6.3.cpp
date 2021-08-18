//
// Created by  Milkij on 06.08.2021.
//
#include "iostream"
bool checkPoints (std::string ipAdress) {
    bool is_valid=true;
    int len = ipAdress.length();
    for (int i=0; i<len && is_valid; i++) {
        if ((ipAdress[i]>='0' && ipAdress[i]<='9') || ipAdress[i]=='.') continue;
        else is_valid=false;
    }
    int cntPoints=0;
    for (int i=0; i<len && is_valid; i++) {
        if (ipAdress[0]=='.' || ipAdress[len - 1]=='.') is_valid = false;
        if (is_valid && ipAdress[i]=='.' && (ipAdress[i-1]=='.' || ipAdress[i+1]=='.')) is_valid = false;
        if (is_valid && ipAdress[i-1]=='.' && ipAdress[i]=='0' && (ipAdress[i+1]>='0' && ipAdress[i+1]<='9')) is_valid=false;
        if (is_valid && ipAdress[i]=='0' && (ipAdress[i+1]>='0' && ipAdress[i+1]<='9')) is_valid=false;
        if (is_valid && ipAdress[i]=='.') {
            cntPoints++;
            if (cntPoints > 3) is_valid=false;
        }
    }
    if (is_valid && cntPoints!=3) is_valid=false;
    return is_valid;
}

bool rightNumber (std::string numb) {
    int numbLen=numb.length();
    if(numbLen==3 && numb[0]=='1') return true;
    else if(numbLen==3 && (numb[0]>'2' || numb[1]>'5' || numb[2]>'5')) return false;
    else return true;
}

bool checkIpCort (std::string ipAdress) {
    bool is_right_number= checkPoints(ipAdress);
    int i=0;
    std::string numb;

    for (; i<ipAdress.length() && is_right_number; i++) {
        if(ipAdress[i]=='.') {
            i+=1;
            //std::cout << numb << std::endl;
            if(rightNumber(numb)) numb="";
        };
        numb+=ipAdress[i];
        if(numb.length() > 3) is_right_number=false;
        //std::cout << i << std::endl;
    }
    if(is_right_number) is_right_number=rightNumber(numb);
    return is_right_number;
}

int main() {
    std::string ipAdress;
    std::cout << "Input IP adress" << std::endl;
    std::cin >> ipAdress;
    std::cout << (checkIpCort(ipAdress) ? "Yes" : "No") << std::endl;
}
