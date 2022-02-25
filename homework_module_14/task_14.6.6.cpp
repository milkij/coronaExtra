//
// Created by Александр Широков on 08.02.2022.
//
#include "iostream"
#include "vector"

using namespace std;
int main(){
    float arr[4][4]; //= {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    vector<float> V{4}; //= {1,2,3,4};
    float num;
    cout << "Input 4 numbers." << endl;
    int c=1;
    for (int i=0; i<4; i++) {
        cout << "Input " << c << ": ";
        c++;
        cin >> num;
        V[i]=num;
    }
    cout << "Input 16 numbers." << endl;
    c=1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << "Input " << c << ": ";
            c++;
            cin >> num;
            arr[i][j]=num;
        }
    }

    vector<float> C = {0,0,0,0};
    for (int i=0; i<4; i++) {

        for (int j=0; j<4; j++) {
            C[i]+=V[i]*arr[j][i];
        }
    }
    for (int i=0; i<4; i++)  cout << C[i] << ' ';
}

