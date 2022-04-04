//
// Created by Александр Широков on 04.04.2022.
/*
С клавиатуры вводятся числа.
Когда пользователь вводит -1 -- необходимо выводить на экран пятое по возрастанию число среди введённых.
Когда пользователь вводит -2 -- программа завершает работу.
Пример:
ввод: 7 5 3 1 2 4 6 -1
вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
ввод: 1 1 1 -1
вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
ввод -2
завершение программы
 */
//version 1.0

#include "iostream"
#include "vector"
using namespace std;

bool sortBuble (vector<int>&vect) {
    if(vect.size()<=1) return false;
    for (int i; i<vect.size()-1; i++) {
        for (int j=0; j<vect.size()-1-i;j++) {
            int temp;
            if(vect[j]>vect[j+1]) {
                temp=vect[j];
                vect[j]=vect[j+1];
                vect[j+1]=temp;
            }
        }
    }
    return true;
}

bool print(vector<int>&vect) {
    if(vect.size()==0) return false;
    for (int i=0; i<vect.size();i++){
        cout<<vect[i]<<' ';
    }
    return true;
}

int main () {
    vector <int> a = {1,2,3,4,5,6,7};
    int N;
    while (true){
        cout<<"Innput some number: ";
        cin>>N;
        if (N==-2) {
            sortBuble(a);
            print(a);
            break;
        }
        else if (N==-1) {
            sortBuble(a);
            cout<<a[4]<<' ';
            print(a);
            break;
        } else {
            a.push_back(N);
        }
    }

    return 0;
}
