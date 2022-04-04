//
// Created by Александр Широков on 04.04.2022.
//
/*Вам даётся массив целых чисел, отсортированных по возрастанию.
Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел
Пример:
Массив {-100,-50, -5, 1, 10, 15}
Вывод: 1, -5, 10, 15, -50, -100
Задание со звёздочкой: оптимизировать решение четвёртой задачи, чтобы оно совершало как можно меньше операций
*/
//version1.0
#include "iostream"
#include "vector"
#include "math.h"

using namespace std;
int main () {
    vector<int> a = {-100,-50, -5, 1, 10, 15};
    for (int i=0; i<a.size()-1; i++) {
        for (int j=0; j<a.size()-1-i; j++){
            int temp;
            if(abs(a[j])>abs(a[j+1])) {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
        }
    }

    for(int i=0; i<a.size(); i++) {
        cout<<a[i]<<' ';
    }
    return 0;
}