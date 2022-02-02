//
// Created by Александр Широков on 02.02.2022.
//
#include "iostream"
#include "vector"

using namespace std;
 int main () {
     char playField [3][3];
     if (true) {
         for (int i = 0; i < 3; i++) {
             for (int j = 0; j < 3; j++) {
                 playField[i][j] = '.';
             }
         }
     }
         for (int i=0; i<3; i++) {
             for (int j=0; j<3; j++) {
                 cout << playField[i][j];
             }
             cout << endl;
         }
 }

