// Created by Александр Широков on 04.04.2022.
/*
 * Вам даётся массив целых чисел и одно число -- результат.
 * Необходимо найти в массиве 2 числа, сумма которых будет давать результат, и вывести их на экран.
 * Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.
 * Пример:
 * a = {2, 7, 11, 15}. Результат = 9
 * 2 + 7 = 9, так что надо вывести числа 2 и 7
*/
//version 1.0
#include "iostream"
#include "vector"
using namespace std;

int main () {
    vector <int> a = {2, 7, 11, 15};
    int sumOfCouple=17;
    if (a.size()==0) return 0;
    for (int i=0; i<a.size();i++) {
        for (int j=i; j<a.size(); j++)
        if (sumOfCouple==a[i]+a[j]) {
            cout<<a[i]<<':'<<a[j];
            break;
        }
    }
    return 0;
}
