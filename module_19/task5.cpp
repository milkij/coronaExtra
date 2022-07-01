//
// Created by Александр Широков on 29.06.2022.
//
#include "iostream"
#include "fstream"
#include "vector"
const int sizeOfPlayField = 13;

int pointA=0;

int pointB=0;

int findCurStep(int &step, int &curStep) {
    if(curStep+step>sizeOfPlayField) return curStep=(curStep+step)%sizeOfPlayField;
    else return curStep+=+step;

}

void compareStepWith(int &curStep, int arr[sizeOfPlayField]) {
    for (int i=0; i<13; i++) {
        if(curStep==arr[i]) {
            curStep++;
            if(curStep>sizeOfPlayField) curStep%=sizeOfPlayField;
            i=0;
        }
    }
}


int main() {
    std::string questions[13];
    std::string answers[13];
    std::ifstream text;
    text.open("//Users//alexander//CLionProjects//coronaExtra//module_19//questions.txt");
        for(int i=0; i<13; i++) text >> questions[i];
    text.close();
    text.open("//Users//alexander//CLionProjects//coronaExtra//module_19//answers.txt");
    for(int i=0; i<13; i++) text >> answers[i];
    text.close();
    //std::cout<<questions[1] << std::endl << answers[1] << std::endl;
    int field[sizeOfPlayField];
    int step;
    int currStep=1;
    int j=0;
    while (j<sizeOfPlayField && pointA<=6 && pointB <=6) {
        std::cout << "Input num: ";
        std::cin >> step;
        findCurStep(step,currStep);
        std::cout << currStep << std::endl;
        compareStepWith(currStep,field);
        field[j]=currStep;
        std::cout << questions[currStep] << " (yes or no)?";
        std::string rightAnswer;
        std::cin >> rightAnswer;
        if(rightAnswer==answers[j]) {
            pointA++;
            std::cout << "right answer";
        }
        else {
            pointB++;
            std::cout << "wrong answer";
        }
        j++;
        std::cout << std::endl;
    }
    if (pointA==6) std::cout << "Player won";
    if (pointB==6) std::cout << "Quests won";
    //for (int i=0; i< 13;i++) std::cout << field[i] << ' ';

}

