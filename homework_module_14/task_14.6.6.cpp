//
// Created by Александр Широков on 08.02.2022.
//
#include "iostream"
#include "vector"

using namespace std;
int main(){
    float arr[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    vector<float> V = {1,2,3,4};
    float num;
    cout << "Input 4 numbers." << endl;
    int c=1;
    for (int i=0; i<V.size(); i++) {
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

    for (int i=0; i<V.size(); i++) {
        for (int j=0; j<4; j++) {
            V[i]+=V[i]*arr[i][j];

        }
    }

    for (int i=0; i<V.size(); i++)  cout << V[i] << ' ';
}

