//
// Created by Александр Широков on 08.02.2022.
//
#include "iostream"

using namespace std;
int main(){
   int arr[4][4];
   int c;
   int n=1;
    cout << "Input 16 numbers" << endl;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << "input " << n << ": ";
            n++;
            cin >> c;
            arr[i][j]=c;
        }
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) (j==i) ? cout << arr[i][j] << ' ':  cout << '0' << ' ';
        cout << endl;
    }

}

