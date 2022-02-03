//
// Created by Александр Широков on 03.02.2022.
//
#include "iostream"

using namespace std;

int main() {
    int x=0,y=0;
    cout << "Input size of table (x, y) to see a snake:" << endl;
    cin >> x >> y;
    int snake[x][y];
    int N=0;
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            (i%2 == 0) ? snake[i][j] = N : snake[i][y - 1 - j] = N;
            N++;
        }
    }
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
           cout << snake[i][j] << ' ';
        }
        cout << endl;
    }
}