//
// Created by Александр Широков on 03.02.2022.
//
#include "iostream"
using namespace std;
void inputMatrix(int m[4][4], string str) {
    cout<<"Input " << str <<  " matrix 4x4:" << endl;
    int step=0;
    int N;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            step++;
            cout<<"Input "<< step <<" step: ";
            cin>>N;
            m[i][j]=N;
        }
    }
    cout << "Thank u" << endl;
}

void printMatrix(int m[4][4]) {
    cout << endl << "the reult is: " << endl;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}


int main(){
    int a[4][4];
    int b[4][4];

    inputMatrix(a, "the first");
    printMatrix(a);

    inputMatrix(b, "the second");
    printMatrix(b);

    bool isMatch = true;
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            if (a[i][j]!=b[i][j]) isMatch= false;
            if (!isMatch) break;
        }
    }
    if(isMatch) cout<<"Match";
    else cout << "Not Match";

}
