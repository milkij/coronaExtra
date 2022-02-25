//
// Created by Александр Широков on 11.02.2022.
//

#include "iostream"


using namespace std;
int main() {
    int square[5][5];
    int n;
    int step=1;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cout << "Input "<< step <<" square height: ";
            cin >> n;
            while(n<0 || n>9) {
                cout << "Incorrect input! Try again. \n ";
                cout << "Input "<< step <<" square height: ";
                cin >> n;
            }
            square[i][j]=n;
            step++;
        }
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            std::cout<< (square[i][j]>0);;
        }
        cout << endl;
    }



}