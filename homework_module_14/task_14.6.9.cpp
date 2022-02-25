//
// Created by Александр Широков on 11.02.2022.
//
#include "iostream"
#include "math.h"

using namespace std;

void print (int arr[10][10]) {
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
           cout << arr[i][j] << ' ' << ' ';
        }
        cout << endl;
    }
}

bool checkBoard(int x1, int y1, int x2, int y2) {
    if (x1<1 || x1>10 || y1<1 || y1>10 || x2<1 || x2>10 || y2<1 || y2>10) return false;
    else return true;
}

bool checkOneLineAndDist(int x1, int y1, int x2, int y2, int type) {
    bool isOneLine=false;
    if ((x1*(y2-y1) + x1*(y1-y2) + y1*(x2-x1) + y1*(x2-x1) == 0) || (x1!=x2 && y1==y2)) isOneLine=true;
    int AB = sqrt(pow(x2-x1,2)+ pow(y2-y1,2))+1;
    if(AB!=2&&type==2) isOneLine=false;
    if(AB!=3&&type==3) isOneLine=false;
    if(AB!=4&&type==4) isOneLine=false;
    //if ((x1==x2 && AB-1+y1>10) || (y1==y2 && AB-1+x1 > 10)) isOneLine=false;
    if (x1==x2 && y1+AB-1>10) isOneLine=false;
    if (y1==y2 && x1+AB-1>10) isOneLine=false;
    return isOneLine;
}

bool checkFreeSpots(int arr[10][10], int x1, int y1, int x2, int y2, int type) {
    //1 1 1 3 y1!=y2
    //1 1 3 1 x1!=x2
    bool isAllFree = true;
    //int AB = sqrt(pow(x2-x1,2)+ pow(y2-y1,2))+1;
    if (arr[x1][y1]==1 && type==1) return false;
    if (type==2) {
        for (int i=x1;i<=x2;i++) {
            for (int j=y1; j<=y2; j++) {
                if(arr[i][j]==1) return false;
            }
        }
    }
    return isAllFree;
}

void placeShip(int playField[10][10], int x1, int y1, int x2, int y2, int type){
    if (type == 1) playField[x1][y1] = 1;
    if (type == 2) {
        for (int i=x1;i<=x2;i++) {
            for (int j=y1; j<=y2; j++) {
                playField[i][j]=1;
            }
        }
    }
}
void fillShipsIntoPlayField(int player, string typeOfShip, int playField[10][10]) {
    int size,cnt,ship=1,x1,y1,x2,y2;
    if(typeOfShip=="small") {
        size=1;
        cnt=4;
    }
    if(typeOfShip=="medium") {
        size=2;
        cnt=3;
    }
    if(typeOfShip=="big") {
        size=3;
        cnt=2;
    }
    if(typeOfShip=="large") {
        size=4;
        cnt=1;
    }
    if (typeOfShip=="small") {
        cout << "Player "<<player<<", add "<<cnt<<" small ships "<<endl;
        //ship=1;
        for (int i=1; i<=cnt;) {
            cout<<"Player "<<player<<", Input "<< ship <<" "<< typeOfShip <<" ship coordinates x & y: ";
            cin>>x1>>y1;
            if(checkFreeSpots(playField,x1-1,y1-1,x1-1,y1-1,1)
               && checkBoard(x1,y1,x1,y1)) {
                placeShip(playField,x1-1,y1-1,x1-1,y1-1,1);
                i++;
                ship++;
            }
            else {
                cout<< "Maybe the spot has taken. Try again" <<endl;
                print(playField);
                cout<<"\n---------- Repeat ----------\n";
            }
        }
    } else {
        cout << "Player "<<player<<", add "<<cnt<<" " << typeOfShip << " ships "<<endl;
        //reset ship
        //ship=1;
        for (int i=1; i<=cnt;) {
            cout<<"Player "<<player<<", Input "<< ship <<" "<< typeOfShip <<" ship coordinates x1 & y1 & x2 & y2 : ";
            cin>>x1>>y1>>x2>>y2;
            if(checkFreeSpots(playField,x1-1,y1-1,x2-1,y2-1,2)
               && checkOneLineAndDist(x1,y1,x2,y2,size)
               && checkBoard(x1,y1,x2,y2)) {
                placeShip(playField,x1-1,y1-1,x2-1,y2-1,2);
                i++;
                ship++;
            }
            else {
                cout<< "Maybe the spot has taken. Try again" <<endl;
                print(playField);
                cout<<"\n---------- Repeat ----------\n";
            }

        }
    }
    cout<<"\n---------- Next step ----------\n";
}

int main() {
    while (true) {
        cout << "New game (1/0)?\n";
        int x;
        cin >> x;
        if (x!=1) {
            cout << "Good luck! \n";
            return 0;
        } else {
            int playField1[10][10];
            int playField2[10][10];
            for (int i=0; i<10; i++) {
                for (int j=0; j<10; j++) {
                    playField1[i][j]=0;
                    playField2[i][j]=0;
                }
            }

            //first player set
            cout<<"Hello Player 1!\n You should set: \n -> 4 small ships (1 points);\n -> "
                  "3 medium ships (2 points); \n -> 2 big ships (3 points); \n"
                  " -> 1 large ship (4 points).\n ---------- Let's do it --------"<<endl;
            fillShipsIntoPlayField(1,"small",playField1);
            fillShipsIntoPlayField(1,"medium",playField1);
            fillShipsIntoPlayField(1,"big",playField1);
            fillShipsIntoPlayField(1,"large",playField1);
            print(playField1);

            //second player set
            cout<<"Hello Player 2!\n You should set: \n -> 4 small ships (1 points);\n -> "
                  "3 medium ships (2 points); \n -> 2 big ships (3 points); \n"
                  " -> 1 large ship (4 points).\n ---------- Let's do it --------"<<endl;
            fillShipsIntoPlayField(2,"small",playField2);
            fillShipsIntoPlayField(2,"medium",playField2);
            fillShipsIntoPlayField(2,"big",playField2);
            fillShipsIntoPlayField(2,"large",playField2);
            print(playField2);

            cout<<"\n-----------Greatfull-----------\n"
                  "--> Let's go to fight -->\n";
            int x,y, round=1;
            while (true){
                int p1=20, p2=20;
                cout<<"This is "<<round<<" round.\n";
                cout<<"Player 1! This is your step!\n Input x1 & y2 coordinates";
                cin>>x>>y;
                if(playField2[x][y]==1) {
                    playField2[x][y]=1;
                    p2--;
                    cout<<"\n--------Baga Boom!-------\n";
                    if(p2==0) {
                        cout<<"\n---------- Player1 win! ----------\n";
                        break;
                    }
                } else cout<<"\n----------Miss---------\n";
                cout<<"Player 2! This is your step!\n Input x1 & y2 coordinates";
                cin>>x>>y;
                if(playField1[x][y]==1) {
                    playField1[x][y]=1;
                    cout<<"\n--------Baga Boom!-------\n";
                    p1--;
                    if(p1==0) {
                        cout<<"\n----\n------ Player1 win! -----\n-----\n";
                        break;
                    }
                } else cout<<"\n----------Miss---------\n";

            }


        }

    }
}

