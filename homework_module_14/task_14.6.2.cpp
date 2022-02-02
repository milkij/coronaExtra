//
// Created by Александр Широков on 27.01.2022.
//

#include "iostream"
#include "vector"

using namespace std;

bool checkCoordiantes(int X, int Y) {
    if (X < 1 && X > 3) return false;
    else if (Y < 1 && Y > 3) return false;
    else return true;
}

bool checkGame(char arr[3][3], char symb) {
    bool isMatchHorisontal = true;
    bool isMatchVertiacl = true;
    for (int i=0; i<3; i++) {
        for (int j=0; i<3; i++) {
            if(arr[i][j]!=symb) isMatchHorisontal = false;
            if(arr[j][i]!=symb) isMatchVertiacl = false;
        }
    }
    if (isMatchHorisontal || isMatchVertiacl) return true;
    else return false;
}



void ptintGameField (char arr[3][3]) {
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++) {
            cout << arr[i][j] << '|';
        }
        cout << endl;
    }
}

int main() {

    cout << "Do u wanna start the new game (yes/no)?";
    string answer = "";
    cin >> answer;
    while(answer!="yes") {
        if (answer=="no") {
            cout << "Good luck!";
            break;
        }
        cout << "Incorreect answer, try again! /n Do u wanna start the new game (yes/no)?";
        cin >> answer;
    }

    char playField [3][3];
    if (answer=="yes") {
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                playField[i][j] = ' ';
            }
        }
        cout << "We are ready to go!" << endl;
        ptintGameField(playField);
        int step=0;
        while (true) {
            int coordinateX;
            int coordinateY;
            //while(првоерка на выигрыш функция бул()) == false

            cout << "This is the PlayerX step (X) --> ";
            cout << "PlayerX, please, input X and Y coordinates (1,3): " << endl;
            cin >> coordinateX >> coordinateY;
            if (checkCoordiantes(coordinateX,coordinateY)) {
                while (playField[coordinateX-1][coordinateY-1]!=' ') {
                    ptintGameField(playField);
                    cout << "PlayerX Input X and Y coordinates again (from 1 to 3 numbers): " << endl;
                    cin >> coordinateX >> coordinateY;

                }
                playField[coordinateX-1][coordinateY-1]='X';
                step++;
                if (checkGame(playField,'X')) {
                    cout << "PlayerX won" << endl;
                    ptintGameField(playField);
                    break;
                } else {
                    ptintGameField(playField);
                }
            }

            if(step==9) {
                cout << "a draw game." << endl;
                ptintGameField(playField);
                break;
            }
            cout << step << endl;
            cout << "This is the PlayerO step (O) --> ";
            cout << "PlayerO, please, input X and Y coordinates (1,3): " << endl;
            cin >> coordinateX >> coordinateY;
            if (checkCoordiantes(coordinateX,coordinateY)) {
                while (playField[coordinateX-1][coordinateY-1]!=' ') {
                    ptintGameField(playField);
                    cout << "PlayerO, please, input X and Y coordinates again (from 1 to 3 numbers): " << endl;
                    cin >> coordinateX >> coordinateY;

                }
                playField[coordinateX-1][coordinateY-1]='O';
                step++;
                if (checkGame(playField,'O')) {
                    cout << "PlayerO won" << endl;
                    ptintGameField(playField);
                    break;
                } else {
                    ptintGameField(playField);
                }
            }

        }
    }
};