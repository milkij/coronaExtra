//
// Created by  Milkij on 09.08.2021.
//
#include "iostream"
#include "cmath"

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

std::string cutZeros(std::string s) {
    bool isPoints = false;
    int points=0;
    for (int i=0; i<s.length();i++){
        if(s[i]=='.')points++;
    }
    if(points==1)isPoints=true;
    if(s[0]=='0'){
        int i=0;
        for(;i<s.length();) {
            if(s[i]=='0') i++;
            else break;
        }
        s.erase(0,i);
    }
    if(s[s.length()-1]=='0' && isPoints){
        int i=s.length()-1;
        for(;i!=0;){
            if(s[i]=='0') i--;
            else break;
        }
        s.erase(i+1,s.length()-1);
    }
    //if(isPoints) s.erase(s.find('.'),1);;
    return s;
}

std::string devideOnTwoParts(std::string x,int part=1){
    if (x.find('.')==-1) return x;
    else {
        if(part==1) return x.substr(0,x.find('.'));
        if(part==2) return x.substr(x.find('.')+1,x.length());
    }
    return x;
}

std::string addAccuracy(std::string changedString, std::string lenghtString){
    if(changedString.find('.')==-1) changedString+='.';
    int count=lenghtString.length()-changedString.length();
    for(int i = 0;i<count;i++){
        changedString.append("0");
    }
    return changedString;
}

int sum(std::string x){
    int sum=0;
    for(int i=0;i<x.length();i++){
        if(x[i]=='-') continue;
        else sum+=(int)x[i];
    }
    if(x[0]=='-') sum*=-1;
    return sum;
}

int convertCharToInt (char c,std::string s){
    if(s[0]=='-') return (int)c*-1;
    else return (int)c;
}

void sumOfChars(std::string x, std::string y) {
    int fX= sum(devideOnTwoParts(x));
    int fY= sum(devideOnTwoParts(y));
    if(fX>fY) std::cout << "more" << std::endl;
    else if(fX<fY) std::cout << "less" << std::endl;
    else if((x.find('.')!=-1 && x.find('.')!=x.length()-1) || (y.find('.')!=-1 && y.find('.')!=y.length()-1))  {
        //std::cout << "there is no decision" << std::endl;
        std::string sX,sY;
        sX= devideOnTwoParts(addAccuracy(x,y),2);
        sY= devideOnTwoParts(addAccuracy(y,x),2);
        bool isEquel = true;
        for(int i=0;i<sX.length();i++){
            if(convertCharToInt(sX[i],x)>convertCharToInt(sY[i],y)){
                std::cout << "more" << std::endl;
                isEquel= false;
                break;
            } else if(convertCharToInt(sX[i],x)<convertCharToInt(sY[i],y)){
                std::cout << "less" << std::endl;
                isEquel= false;
                break;
            } else continue;
        }
        if(isEquel) std::cout<<"equel"<<std::endl;
    }
    else {
        std::cout<<"equel"<<std::endl;
    }
    }

int main () {
    std::cout << "Input two float numbers:\n";
    std::string x;
    std::cin >> x;
    std::string y;
    std::cin >> y;

    x=cutZeros(x);
    y=cutZeros(y);
    if (checkFloat(x) && checkFloat(y)) {
        sumOfChars(x,y);
    } else std::cout << "Error" << std::endl;
    //std::cout << addAccuracy(x,y)<< std::endl;
    //std::cout << convertCharToInt('1',x) << std::endl;
}
