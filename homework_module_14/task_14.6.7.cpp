//
// Created by Александр Широков on 11.02.2022.
//
#include "iostream"

using namespace std;
bool getNewTape(bool arr[12][12]) {
    for (int i=0; i<12; i++) for (int j=0; j<12; j++) arr[i][j]= true;
    return arr;
}

void printTape(bool arr[12][12]) {
    for (int i=0; i<12; i++) {
        for (int j=0; j<12; j++) {
            if (arr[i][j]==true) cout << 'O' << ' ' << ' ';
            else cout << 'X' << ' ';
        } cout << endl;
    }
}

void popBubble(int x, int y,bool arr[12][12]) {
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            if (arr[i][j]== true) {
                cout << "Pop! \n";
                arr[i][j]=false;
            }
        }
    }
}

bool checkTape(bool arr[12][12]) {
    bool isExistsO = false;
    for (int i=0; i<12; i++) {
        for (int j=0; j<12; j++) {
            if (arr[i][j]== true) isExistsO=true;
            if(isExistsO) break;
        }
    }
    return isExistsO;
}

int main () {
    while (true) {
        cout << "Do you want to get a new tape? (1/0) :";
        int n;
        cin >> n;
        if(n!=1) {
            cout << "Good luck!";
            return 0;
        } else {
            bool arrTape[12][12];
            getNewTape(arrTape);
            printTape(arrTape);
            int x,y;
            while (true) {
                cout << "Input coordinates x and y. \n Values cant be more then 12 and less then 1 \n";
                cin >> x >> y;
                while(x>12 || y>12) {
                    cout << "Values cant be more then 12 and less then 1 \n Input coordinates x and y again. \n";
                    cin >> x >> y;
                }
                popBubble(x,y, arrTape);
                printTape(arrTape);
                if (!checkTape(arrTape)) {
                    cout << "\nThere are no full bables in our tape! Congratulate u!\n";
                    printTape(arrTape);
                    break;
                }
            }
        }
    }
}

